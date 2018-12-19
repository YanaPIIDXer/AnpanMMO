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

	// 破棄.
	void Retire(u32 QuestId);

	// 進行中か？
	bool IsActive(u32 QuestId) const;

	// ステージ番号を取得.
	uint32 GetStageNo(u32 QuestId) const;

private:

	// クエストマップ
	QuestMap Quests;

};
