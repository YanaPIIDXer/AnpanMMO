// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "QuestMenu.generated.h"

// クエストデータ
USTRUCT(BlueprintType)
struct FQuestData
{

	GENERATED_USTRUCT_BODY()

public:

	// クエストＩＤ
	uint32 QuestId;

	// クエスト名.
	UPROPERTY(BlueprintReadOnly)
	FString Name;

	// 説明文.
	UPROPERTY(BlueprintReadOnly)
	FString Explain;

	// メインクエストか？
	UPROPERTY(BlueprintReadOnly)
	bool bIsMainQuest;

	// アクティブクエストか？
	UPROPERTY(BlueprintReadWrite)
	bool bIsActive;

};

/**
 * クエストメニュー
 */
UCLASS()
class ANPANMMO_API UQuestMenu : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()
	
public:

	// コンストラクタ
	UQuestMenu(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UQuestMenu() {}

	// パケットを受信した。
	virtual void OnRecvPacket(uint8 ID, MemoryStreamInterface *pStream) override;

protected:

	// 初期化.
	UFUNCTION(BlueprintCallable, Category = "QuestMenu")
	void Init();

	// 初期化イベント
	UFUNCTION(BlueprintNativeEvent, Category = "QuestMenu")
	void InitEvent(const TArray<FQuestData> &List);
	void InitEvent_Implementation(const TArray<FQuestData> &List) {}
	
	// クエスト破棄.
	UFUNCTION(BlueprintCallable, Category = "QuestMenu")
	void RetireQuest(const FQuestData &Data);

	// アクティブクエストを変更.
	UFUNCTION(BlueprintCallable, Category = "QuestMenu")
	void ChangeActiveQuest(const FQuestData &Data);

};
