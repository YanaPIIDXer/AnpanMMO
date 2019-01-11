#include "stdafx.h"
#include "CharacterParameter.h"

// コンストラクタ
CharacterParameter::CharacterParameter()
	: Level(1)
	, Hp(1)
	, MaxHp(1)
	, BaseMaxHp(1)
	, Str(0)
	, Def(0)
	, Int(0)
	, Mnd(0)
	, Vit(0)
{
}

// パラメータをセット
void CharacterParameter::Set(u32 InLevel, u32 InHp, u32 InMaxHp, u32 InStr, u32 InDef, u32 InInt, u32 InMnd, u32 InVit, bool bIsVitAffectMaxHp)
{
	Level = InLevel;
	Hp = InHp;
	MaxHp = InMaxHp;
	BaseMaxHp = InMaxHp;
	Str = InStr;
	Def = InDef;
	Int = InInt;
	Mnd = InMnd;
	Vit = InVit;

	if (bIsVitAffectMaxHp)
	{
		RecalcMaxHp();
	}
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

// 装備切り替え
void CharacterParameter::ChangeEquip(u32 RightEquipId, u32 LeftEquipId)
{
	RightEquip.Set(RightEquipId);
	LeftEquip.Set(LeftEquipId);

	RecalcMaxHp();
}


// 最大ＨＰの再計算.
void CharacterParameter::RecalcMaxHp()
{
	MaxHp = BaseMaxHp + static_cast<u32>(GetVit() * 1.5f);
}
