// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class ASkyControl;
class MemoryStreamInterface;

/**
 * 時間管理.
 */
class ANPANMMO_API TimeManager
{

public:

	// コンストラクタ
	TimeManager();

	// デストラクタ
	~TimeManager() {}

	// 天球をセット。
	void SetSkyControl(ASkyControl *pInSky) { pSky = pInSky; }

	// 時間変動を受け取った。
	void OnRecvTimeChange(MemoryStreamInterface *pStream);

private:

	// 天球.
	TWeakObjectPtr<ASkyControl> pSky;

};
