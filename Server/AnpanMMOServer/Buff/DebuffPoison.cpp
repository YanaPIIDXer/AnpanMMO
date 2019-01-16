/**
 * @file DebuffPoison.cpp
 * @brief �Ńf�o�t�N���X
 * @author YanaP
 */
#include "stdafx.h"
#include "DebuffPoison.h"
#include "Character/CharacterBase.h"

const u32 DebuffPoison::DamageInterval = 3000;

// �R���X�g���N�^
DebuffPoison::DebuffPoison(u32 Time, CharacterBase *pInCharacter, float InDamageRate)
	: BuffBase(Time, pInCharacter)
	, DamageRate(InDamageRate)
	, DamageTimer(DamageInterval)
{
}


// ���t���[���̏���
void DebuffPoison::Update(u32 DeltaTime)
{
	DamageTimer -= DeltaTime;
	if (DamageTimer <= 0)
	{
		u32 Value = static_cast<u32>(GetCharacter()->GetParameter().GetMaxHp() * DamageRate);
		GetCharacter()->ApplyDamage(CharacterPtr(), Value);
		DamageTimer += DamageInterval;
	}
}
