#include "stdafx.h"
#include "AnpanPopArea.h"
#include "Character/Anpan/Anpan.h"
#include "Master/MasterData.h"
#include "Master/AnpanPopAreaMaster.h"
#include "Math/Random.h"

// コンストラクタ
AnpanPopArea::AnpanPopArea(const AnpanPopAreaItem *pMasterItem)
	: Range(pMasterItem->Range)
	, Position(pMasterItem->X, pMasterItem->Y, pMasterItem->Z)
	, MaxCount(pMasterItem->MaxCount)
	, PopDataId(pMasterItem->PopId)
	, PopInterval(pMasterItem->PopInterval)
	, CurrentInterval(pMasterItem->PopInterval)
{
}

// 毎フレームの処理.
void AnpanPopArea::Poll(int DeltaTime)
{
	CurrentInterval -= DeltaTime;
	if (CurrentInterval <= 0)
	{
		SpawnAnpan();
		CurrentInterval += PopInterval;
	}
	UpdateList();
}


// アンパンを生成.
void AnpanPopArea::SpawnAnpan()
{
	if (AnpanList.size() >= MaxCount) { return; }

	float X = Position.X + Random::Range<float>(-Range, Range);
	float Y = Position.Y + Random::Range<float>(-Range, Range);
	float Z = Position.Z;

	std::vector<const AnpanPopDataItem *> Items = MasterData::GetInstance().GetAnpanPopDataMaster().CollectItems(PopDataId);
	if (Items.size() == 0) { return; }
	s32 PopDataIndex = Random::Range<s32>(0, Items.size() - 1);
	const AnpanPopDataItem *pPopData = Items[PopDataIndex];
	const AnpanItem *pAnpanItem = MasterData::GetInstance().GetAnpanMaster().GetItem(pPopData->AnpanId);

	Anpan *pNewAnpan = new Anpan(Vector3D(X, Y, Z), pAnpanItem->ID, pAnpanItem->Hp, pAnpanItem->Atk, pAnpanItem->Def, pAnpanItem->Exp, pAnpanItem->Scale, pAnpanItem->DropId);
	shared_ptr<Anpan> pAnpan = shared_ptr<Anpan>(pNewAnpan);
	AnpanList.push_back(pAnpan);
	if (SpawnFunction)
	{
		SpawnFunction(pAnpan);
	}
}

// リスト更新.
void AnpanPopArea::UpdateList()
{
	std::vector<AnpanPtr>::iterator It = AnpanList.begin();
	while (It != AnpanList.end())
	{
		if (It->expired())
		{
			It = AnpanList.erase(It);
		}
		else
		{
			++It;
		}
	}
}
