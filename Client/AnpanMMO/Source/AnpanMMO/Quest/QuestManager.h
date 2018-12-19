// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Packet/QuestData.h"

/**
 * クエスト管理.
 */
class ANPANMMO_API QuestManager
{

private:	// 別名定義.

	typedef TMap<uint32, QuestData> QuestMap;

public:

	// コンストラクタ
	QuestManager();

	// デストラクタ
	~QuestManager() {}

	// 追加.
	void Add(const QuestData &Data);

private:

	// クエストマップ
	QuestMap Quests;

};
