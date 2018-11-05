// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class AAnpan;

/**
 * アンパン管理.
 */
class ANPANMMO_API AnpanManager
{

private:		// 別名定義.

	typedef TWeakObjectPtr<AAnpan> AnpanPtr;

public:

	// コンストラクタ
	AnpanManager();

	// デストラクタ
	~AnpanManager() {}

private:

	// アンパンマップ
	TMap<uint32, AnpanPtr> AnpanMap;

};
