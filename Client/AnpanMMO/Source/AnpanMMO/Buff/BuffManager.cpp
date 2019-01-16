// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.


#include "BuffManager.h"
#include "BuffNop.h"
#include "Master/MasterData.h"

// コンストラクタ
BuffManager::BuffManager()
	: pOwner(nullptr)
{
}

// デストラクタ
BuffManager::~BuffManager()
{
	for (auto KeyValue : Buffs)
	{
		delete KeyValue.Value;
	}
}

// バフ追加.
void BuffManager::Add(uint32 BuffId)
{
	const BuffItem *pItem = MasterData::GetInstance().GetBuffMaster().Get(BuffId);
	check(pItem != nullptr);

	if (Buffs.Contains(pItem->Type))
	{
		delete Buffs[pItem->Type];
		Buffs.Remove(pItem->Type);
	}

	BuffBase *pBuff = nullptr;
	switch (pItem->Type)
	{
		case BuffItem::SPEEDUP:

			// @TODO:スピードアップバフクラスを作成し、そっちに差し替える。
			//		 ※エラー回避のための措置。
			pBuff = new BuffNop(pOwner.Get(), pItem->Type);
			break;

		default:

			// クライアント側は特にやる事無し。
			pBuff = new BuffNop(pOwner.Get(), pItem->Type);
			break;
	}

	Buffs.Add(pBuff->GetType(), pBuff);
	pBuff->Begin();
}

// バフ消去.
void BuffManager::Remove(uint8 Type)
{
	if (!Buffs.Contains(Type)) { return; }

	Buffs[Type]->Finish();
	delete Buffs[Type];
	Buffs.Remove(Type);
}
