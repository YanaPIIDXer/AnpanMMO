// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class ANPCCharacter;

/**
 * NPC管理クラス
 */
class ANPANMMO_API NPCManager
{

public:

	// コンストラクタ
	NPCManager();

	// デストラクタ
	~NPCManager() {}

	// Worldを設定.
	void SetWorld(UWorld *pInWorld) { pWorld = pInWorld; }

	// マップが切り替わった。
	void OnMapChanegd(uint32 MapId);

	// リセット。
	void Reset();

private:

	// World
	TWeakObjectPtr<UWorld> pWorld;

	// NPCリスト
	TArray<TWeakObjectPtr<ANPCCharacter>> NPCs;

};
