/**
 * @file BuffBase.cpp
 * @brief バフ基底クラス
 * @author YanaP
 */
#include "stdafx.h"
#include "BuffBase.h"
#include "Character/CharacterBase.h"

// コンストラクタ
BuffBase::BuffBase(u32 Time, CharacterBase *pInCharacter)
	: LastTime(Time)
	, pCharacter(pInCharacter)
{
}

// 毎フレームの処理.
void BuffBase::Poll(u32 DeltaTime)
{
	LastTime -= DeltaTime;
	if (IsFinished()) { return; }
	Update(DeltaTime);
}
