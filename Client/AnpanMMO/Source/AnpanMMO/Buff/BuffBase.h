// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class ACharacterBase;

/**
 * バフ基底クラス
 */
class ANPANMMO_API BuffBase
{

public:

	// コンストラクタ
	BuffBase(ACharacterBase *pInCharacter);

	// デストラクタ
	virtual ~BuffBase() {}

	// タイプを取得.
	virtual uint8 GetType() const = 0;

	// 開始時の処理.
	virtual void Begin() {}

	// 終了時の処理.
	virtual void Finish() {}

protected:

	// キャラクタ取得.
	ACharacterBase *GetCharacter() { return pCharacter.Get(); }

private:

	// キャラクタ
	TWeakObjectPtr<ACharacterBase> pCharacter;

};
