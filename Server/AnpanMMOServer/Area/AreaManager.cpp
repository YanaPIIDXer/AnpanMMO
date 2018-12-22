/**
 * @file AreaManager.cpp
 * @brief �G���A�Ǘ��N���X
 * @author YanaP
 */
#include "stdafx.h"
#include "AreaManager.h"
#include "TickManager.h"
#include "Client.h"
#include "Character/Player/PlayerCharacter.h"
#include "Master/MasterData.h"
#include "Area/Area.h"
#include "Area/InstanceArea.h"

AreaManager AreaManager::Instance;

// �R���X�g���N�^
AreaManager::AreaManager()
	: NextInstanceAreaUuid(1)
{
}

// ������.
void AreaManager::Initialize()
{
	TickManager::GetInstance().Add(boost::bind(&AreaManager::Poll, this, _1));

	std::vector<AreaItem> Items = MasterData::GetInstance().GetAreaMaster().GetAll();
	for (unsigned int i = 0; i < Items.size(); i++)
	{
		const AreaItem *pItem = MasterData::GetInstance().GetAreaMaster().GetItem(Items[i].ID);
		if (pItem->Type != AreaItem::NORMAL_AREA) { continue; }
		Area *pArea = new Area(pItem);
		AreaSharedPtr pSharedArea = AreaSharedPtr(pArea);
		Areas[pItem->ID] = pSharedArea;
		pArea->Initialize();
	}
}

// �擾.
AreaPtr AreaManager::Get(u32 ID) const
{
	AreaMap::const_iterator It = Areas.find(ID);
	if (It == Areas.end()) { return AreaPtr(); }
	return It->second;
}

// ���t���[���̏���.
void AreaManager::Poll(int DeltaTime)
{
	for (AreaMap::iterator It = Areas.begin(); It != Areas.end();)
	{
		It->second->Poll(DeltaTime);
		
		if (It->second->IsAbleDelete())
		{
			It = Areas.erase(It);
		}
		else
		{
			++It;
		}
	}
}

// �C���X�^���X�G���A�̐���.
AreaPtr AreaManager::CreateInstanceArea(u32 AreaId)
{
	u32 Uuid = 10000 + NextInstanceAreaUuid;
	const AreaItem *pItem = MasterData::GetInstance().GetAreaMaster().GetItem(AreaId);
	InstanceArea *pArea = new InstanceArea(Uuid, pItem);
	AreaSharedPtr pSharedPtr = AreaSharedPtr(pArea);
	Areas[Uuid] = pSharedPtr;
	pArea->Initialize();

	NextInstanceAreaUuid++;
	return pSharedPtr;
}
