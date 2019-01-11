#include "stdafx.h"
#include "CharacterParameter.h"

// コンストラクタ
CharacterParameter::CharacterParameter()
	: Level(1)
	, Hp(1)
	, MaxHp(1)
	, Str(0)
	, Def(0)
	, Int(0)
	, Mnd(0)
	, Vit(0)
{
}

// パラメータをセット
void CharacterParameter::Set(u32 InLevel, u32 InHp, u32 InMaxHp, u32 InStr, u32 InDef, u32 InInt, u32 InMnd, u32 InVit)
{
	Level = InLevel;
	Hp = InHp;
	MaxHp = InMaxHp;
	Str = InStr;
	Def = InDef;
	Int = InInt;
	Mnd = InMnd;
	Vit = InVit;
}

// ＨＰ増加
void CharacterParameter::AddHp(u32 Value)
{
	Hp += Value;
	if (Hp > MaxHp)
	{
		Hp = MaxHp;
	}
}

// ＨＰ減算
void CharacterParameter::SubtractHp(u32 Value)
{
	if (Hp >= Value)
	{
		Hp -= Value;
	}
	else
	{
		Hp = 0;
	}
}
