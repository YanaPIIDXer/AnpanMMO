/**
 * @file BuffSpeedUp.cpp
 * @brief �X�s�[�h�A�b�v�o�t�N���X
 * @author YanaP
 */
#include "stdafx.h"
#include "BuffSpeedUp.h"

// �R���X�g���N�^
BuffSpeedUp::BuffSpeedUp(u32 Time, CharacterBase *pInCharacter, float InSpeedRate)
	: BuffBase(Time, pInCharacter)
	, SpeedRate(InSpeedRate)
{
}
