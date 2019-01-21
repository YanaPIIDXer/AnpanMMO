// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.


#include "BuffSpeedUp.h"
#include "Character/CharacterBase.h"

// コンストラクタ
BuffSpeedUp::BuffSpeedUp(ACharacterBase *pInCharacter, float InRate)
	: BuffBase(pInCharacter)
	, Rate(InRate)
{
}

// 開始時の処理.
void BuffSpeedUp::Begin()
{
	GetCharacter()->SetMoveSpeedRate(Rate);
}

// 終了時の処理.
void BuffSpeedUp::Finish()
{
	GetCharacter()->SetMoveSpeedRate(1.0f);
}
