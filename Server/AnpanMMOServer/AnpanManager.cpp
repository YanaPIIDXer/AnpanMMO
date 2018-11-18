#include "stdafx.h"
#include "AnpanManager.h"
#include "Math/Random.h"
#include "Packet/PacketAnpanList.h"
#include "Character/Anpan/Anpan.h"
#include "AnpanPopArea.h"
#include "Master/MasterData.h"

// �R���X�g���N�^
AnpanManager::AnpanManager()
	: NextUuid(1)
{
}

// �f�X�g���N�^
AnpanManager::~AnpanManager()
{
	for (unsigned int i = 0; i < PopAreaList.size(); i++)
	{
		delete PopAreaList[i];
	}
}

// ������.
void AnpanManager::Initialize(u32 AreaId)
{
	std::vector<const AnpanPopAreaItem *> Items = MasterData::GetInstance().GetAnpanPopAreaMaster().CollectItems(AreaId);
	for (u32 i = 0; i < Items.size(); i++)
	{
		AnpanPopArea *pArea = new AnpanPopArea(Items[i]);
		pArea->SetSpawnFunction(bind(&AnpanManager::SpawnAnpan, this, _1));
		PopAreaList.push_back(pArea);
	}
}


// ���t���[���̏���.
void AnpanManager::Poll(int DeltaTime)
{
	for (unsigned int i = 0; i < PopAreaList.size(); i++)
	{
		PopAreaList[i]->Poll(DeltaTime);
	}
	Update(DeltaTime);
}

// �擾.
AnpanPtr AnpanManager::Get(u32 Uuid) const
{
	AnpanMap::const_iterator It = AnpanList.find(Uuid);
	if (It == AnpanList.end()) { return AnpanPtr(); }

	return It->second;
}
// �A���p�����X�g�p�P�b�g�𐶐�.
void AnpanManager::MakeListPacket(PacketAnpanList &Packet)
{
	for (AnpanMap::iterator It = AnpanList.begin(); It != AnpanList.end(); ++It)
	{
		AnpanSharedPtr pAnpan = It->second;
		const CharacterParameter &Param = pAnpan->GetParameter();
		const Vector3D Position = pAnpan->GetPosition();
		AnpanData Data(It->first, Position.X, Position.Y, Position.Z, pAnpan->GetRotation().Get(),Param.Hp, Param.MaxHp);
		Packet.List.PushBack(Data);
	}
}


// �A���p������.
void AnpanManager::SpawnAnpan(AnpanSharedPtr pAnpan)
{
	unsigned int Uuid = NextUuid;
	AnpanList[Uuid] = pAnpan;
	pAnpan->SetUuid(Uuid);

	NextUuid++;

	if (OnSpawn)
	{
		OnSpawn(Uuid, pAnpan);
	}
}

// �X�V����.
void AnpanManager::Update(int DeltaTime)
{
	AnpanMap::iterator It = AnpanList.begin();
	while (It != AnpanList.end())
	{
		if (It->second->IsDead())
		{
			It = AnpanList.erase(It);
		}
		else
		{
			It->second->Poll(DeltaTime);
			++It;
		}
	}
}
