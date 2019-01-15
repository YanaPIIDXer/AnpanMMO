/**
 * @file BuffManager.cpp
 * @brief バフ管理クラス
 * @author YanaP
 */
#include "stdafx.h"
#include "BuffManager.h"
#include "BuffBase.h"
#include "Character/CharacterBase.h"
#include "Master/MasterData.h"
#include "BuffSpeedUp.h"

// コンストラクタ
BuffManager::BuffManager(CharacterBase *pInOwner)
	: pOwner(pInOwner)
{
}

// デストラクタ
BuffManager::~BuffManager()
{
	for (BuffMap::iterator It = Buffs.begin(); It != Buffs.end(); ++It)
	{
		delete It->second;
	}
}

// 毎フレームの処理
void BuffManager::Poll(u32 DeltaTime)
{
	for (BuffMap::iterator It = Buffs.begin(); It != Buffs.end();)
	{
		It->second->Poll(DeltaTime);
		if (It->second->IsFinished())
		{
			u8 BuffType = It->second->GetType();
			delete It->second;
			It = Buffs.erase(It);
			pOwner->OnBuffRemoved(BuffType);
		}
		else
		{
			++It;
		}
	}
}

// バフ追加。
void BuffManager::AddBuff(u32 BuffId)
{
	const BuffItem *pItem = MasterData::GetInstance().GetBuffMaster().GetItem(BuffId);
	if (pItem == NULL)
	{
		std::cout << "Warning! Invalid BuffID:" << BuffId << std::endl;
		return;
	}

	// @TODO:各種バフを追加する処理。
	BuffBase *pBuff = NULL;
	switch (pItem->Type)
	{
		case BuffItem::SPEEDUP:

			// スピードアップ
			pBuff = new BuffSpeedUp(pItem->TimeMilliSec, pOwner, pItem->Value);
			break;

		case BuffItem::AUTO_HEAL:

			// 自動回復.
			break;

		case BuffItem::POISON:

			// 毒.
			break;

		case BuffItem::PARALYSIS:

			// 麻痺.
			break;
	}

	if (pBuff == NULL)
	{
		std::cout << "Warning! Buff object is NULL! BuffID:" << BuffId << std::endl;
		return;
	}

	if (Buffs.find(pItem->Type) != Buffs.end())
	{
		delete Buffs[pItem->Type];
	}

	Buffs[pItem->Type] = pBuff;
	pOwner->OnBuffAdded(BuffId);
}
