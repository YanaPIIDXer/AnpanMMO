// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BuffBase.h"

/**
 * バフ：何もしない
 * クライアント側で特にやる事が無い場合はこのクラスを使う。
 */
class ANPANMMO_API BuffNop : public BuffBase
{

public:

	// コンストラクタ
	BuffNop(ACharacterBase *pInCharacter, uint8 InType);

	// デストラクタ
	virtual ~BuffNop() {}

	// タイプを取得.
	virtual uint8 GetType() const override { return Type; }

private:

	// タイプ
	uint8 Type;

};
