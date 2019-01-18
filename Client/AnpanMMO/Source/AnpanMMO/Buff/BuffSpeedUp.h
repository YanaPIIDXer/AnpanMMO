// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BuffBase.h"
#include "Master/BuffMaster.h"

/**
 * バフ：スピードアップ
 */
class ANPANMMO_API BuffSpeedUp : public BuffBase
{

public:

	// コンストラクタ
	BuffSpeedUp(ACharacterBase *pInCharacter, float InRate);

	// デストラクタ
	virtual ~BuffSpeedUp() {}

	// タイプを取得.
	virtual uint8 GetType() const override { return BuffItem::SPEEDUP; }

	// 開始時の処理.
	virtual void Begin() override;

	// 終了時の処理.
	virtual void Finish() override;

private:

	// 移動速度倍率.
	float Rate;

};
