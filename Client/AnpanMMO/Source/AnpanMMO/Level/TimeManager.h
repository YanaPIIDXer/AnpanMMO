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
	void SetSkyControl(ASkyControl *pInSky);

	// 開始時の時間を受け取った。
	bool OnRecvTime(MemoryStreamInterface *pStream);

	// 時間変動を受け取った。
	bool OnRecvTimeChange(MemoryStreamInterface *pStream);

private:

	// 天球.
	TWeakObjectPtr<ASkyControl> pSky;

	// 現在のマスタＩＤ
	uint32 CurrentMasterId;

};
