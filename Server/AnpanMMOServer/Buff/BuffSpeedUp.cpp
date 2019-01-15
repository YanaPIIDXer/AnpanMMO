/**
 * @file BuffSpeedUp.cpp
 * @brief スピードアップバフクラス
 * @author YanaP
 */
#include "stdafx.h"
#include "BuffSpeedUp.h"

// コンストラクタ
BuffSpeedUp::BuffSpeedUp(u32 Time, CharacterBase *pInCharacter, float InSpeedRate)
	: BuffBase(Time, pInCharacter)
	, SpeedRate(InSpeedRate)
{
}
