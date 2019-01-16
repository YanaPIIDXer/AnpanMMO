/**
 * @file BuffAutoHeal.cpp
 * @brief 自動回復バフクラス
 * @author YanaP
 */
#include "stdafx.h"
#include "BuffAutoHeal.h"
#include "Character/CharacterBase.h"

const u32 BuffAutoHeal::HealInterval = 3000;

// コンストラクタ
BuffAutoHeal::BuffAutoHeal(u32 Time, CharacterBase *pInCharacter, float InHealRate)
	: BuffBase(Time, pInCharacter)
	, HealRate(InHealRate)
	, HealTimer(HealInterval)
{
}


// 毎フレームの処理
void BuffAutoHeal::Update(u32 DeltaTime)
{
	HealTimer -= DeltaTime;
	if (HealTimer <= 0)
	{
		u32 Value = static_cast<u32>(GetCharacter()->GetParameter().GetMaxHp() * HealRate);
		GetCharacter()->Heal(Value);
		HealTimer += HealInterval;
	}
}
