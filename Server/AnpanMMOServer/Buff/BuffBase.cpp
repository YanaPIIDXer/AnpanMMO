/**
 * @file BuffBase.cpp
 * @brief �o�t���N���X
 * @author YanaP
 */
#include "stdafx.h"
#include "BuffBase.h"
#include "Character/CharacterBase.h"

// �R���X�g���N�^
BuffBase::BuffBase(u32 Time, CharacterBase *pInCharacter)
	: LastTime(Time)
	, pCharacter(pInCharacter)
{
}

// ���t���[���̏���.
void BuffBase::Poll(u32 DeltaTime)
{
	LastTime -= DeltaTime;
	if (IsFinished()) { return; }
	Update(DeltaTime);
}
