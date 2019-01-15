/**
 * @file BuffManager.cpp
 * @brief バフ管理クラス
 * @author YanaP
 */
#include "stdafx.h"
#include "BuffManager.h"
#include "BuffBase.h"

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
			delete It->second;
			It = Buffs.erase(It);
		}
		else
		{
			++It;
		}
	}
}
