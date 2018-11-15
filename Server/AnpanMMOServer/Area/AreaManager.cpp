#include "stdafx.h"
#include "AreaManager.h"
#include "TickManager.h"
#include "Client.h"
#include "Character/Player/PlayerCharacter.h"
#include "Master/MasterData.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketMovePlayer.h"
#include "Packet/PacketAttack.h"

AreaManager AreaManager::Instance;

// コンストラクタ
AreaManager::AreaManager()
{
}

// 初期化.
void AreaManager::Initialize()
{
	TickManager::GetInstance().Add(boost::bind(&AreaManager::Poll, this, _1));

	std::vector<AreaItem> Items = MasterData::GetInstance().GetAreaMaster().GetAll();
	for (unsigned int i = 0; i < Items.size(); i++)
	{
		const AreaItem *pItem = MasterData::GetInstance().GetAreaMaster().GetItem(Items[i].ID);
		Area *pArea = new Area(pItem);
		AreaSharedPtr pSharedArea = AreaSharedPtr(pArea);
		Areas[pItem->ID] = pSharedArea;
	}
}

// 取得.
AreaPtr AreaManager::Get(u32 ID) const
{
	AreaMap::const_iterator It = Areas.find(ID);
	if (It == Areas.end()) { return AreaPtr(); }
	return It->second;
}

// 毎フレームの処理.
void AreaManager::Poll(int DeltaTime)
{
	for (AreaMap::iterator It = Areas.begin(); It != Areas.end(); ++It)
	{
		It->second->Poll(DeltaTime);
	}
}

// 移動を受信した。
void AreaManager::OnRecvMove(Client *pClient, MemoryStreamInterface *pStream)
{
	PacketMovePlayer Packet;
	Packet.Serialize(pStream);

	AreaPtr pArea = pClient->GetCharacter().lock()->GetArea();
	pArea.lock()->OnRecvMove(pClient->GetUuid(), Packet.X, Packet.Y, Packet.Rotation);
}

// 攻撃を受信した。
void AreaManager::OnRecvAttack(Client *pClient, MemoryStreamInterface *pStream)
{
	PacketAttack Packet;
	Packet.Serialize(pStream);

	AreaPtr pArea = pClient->GetCharacter().lock()->GetArea();
	pArea.lock()->OnRecvAttack(pClient->GetUuid(), Packet.TargetUuid);
}
