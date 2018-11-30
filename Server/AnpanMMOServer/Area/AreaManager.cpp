#include "stdafx.h"
#include "AreaManager.h"
#include "TickManager.h"
#include "Client.h"
#include "Character/Player/PlayerCharacter.h"
#include "Master/MasterData.h"
#include "Area/Area.h"

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
		if (pItem->Type != AreaItem::NORMAL_AREA) { continue; }
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
