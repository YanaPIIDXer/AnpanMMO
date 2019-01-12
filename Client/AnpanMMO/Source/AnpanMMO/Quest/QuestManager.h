// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Packet/QuestData.h"

DECLARE_DELEGATE_OneParam(FOnActiveQuestUpdated, const QuestData *);

class UMMOGameInstance;

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

	// GameInstanceを設定。
	// ※本当はコンストラクタでやりたいんだけど、
	//   コンストラクタでやると自動生成コードで怒られるので仕方なくの対処。
	void SetGameInstance(UMMOGameInstance *pInInst) { pInst = pInInst; }

	// 初期化.
	void Initialize();

	// 追加.
	void Add(const QuestData &Data);

	// アンパン殺害.
	void KillAnpan(uint32 QuestId);

	// ステージ進行.
	void ProgressStage(uint32 QuestId, uint32 StageNo);

	// クリア
	void Clear(uint32 QuestId);

	// 破棄.
	void Retire(uint32 QuestId);

	// 進行中か？
	bool IsActive(uint32 QuestId) const;

	// クリアしているか？
	bool IsClear(uint32 QuestId) const;

	// ステージ番号を取得.
	uint32 GetStageNo(uint32 QuestId) const;

	// 進行中のクエストを列挙.
	TArray<const QuestData *> CollectProgressingQuests() const;

	// アクティブクエストを設定.
	void SetActiveQuest(uint32 QuestId, bool bSendSavePacket);

	// アクティブクエストのデータを取得.
	const QuestData *GetActiveQuestData() const;

	// アクティブクエストが更新された。
	FOnActiveQuestUpdated OnActiveQuestUpdated;

private:

	// クエストマップ
	QuestMap Quests;

	// アクティブクエストＩＤ
	uint32 ActiveQuestId;

	// GameInstance
	TWeakObjectPtr<UMMOGameInstance> pInst;

};
