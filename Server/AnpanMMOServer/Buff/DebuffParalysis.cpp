/**
 * @file DebuffParalysis.cpp
 * @brief 麻痺デバフクラス
 * @author YanaP
 */
#include "stdafx.h"
#include "DebuffParalysis.h"

// コンストラクタ
DebuffParalysis::DebuffParalysis(u32 Time, CharacterBase *pInCharacter)
	: BuffBase(Time, pInCharacter)
{
}
