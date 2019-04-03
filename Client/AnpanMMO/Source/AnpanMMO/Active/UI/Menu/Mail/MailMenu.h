// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "MailMenu.generated.h"

// メールフラグ
UENUM(BlueprintType)
enum class EMailFlag : uint8
{
	// 未読.
	NotRead,

	// 既読.
	Read,

	// 添付物受信済み
	RecvAttachment,
};

// メール添付物の種類.
UENUM(BlueprintType)
enum class EMailAttachmentType : uint8
{
	// 無し
	None,

	// アイテム
	Item,

	// ゴールド
	Gold,
};

class MailData;

// メールデータ
USTRUCT(BlueprintType)
struct FMailData
{

	GENERATED_USTRUCT_BODY()

public:

	// ID
	uint32 Id;

	// 件名.
	UPROPERTY(BlueprintReadOnly)
	FString Subject;

	// 本文.
	UPROPERTY(BlueprintReadOnly)
	FString Body;

	// フラグ
	UPROPERTY(BlueprintReadOnly)
	EMailFlag Flag;

	// 添付物タイプ
	UPROPERTY(BlueprintReadOnly)
	EMailAttachmentType AttachmentType;

	// 添付物アイテム名.
	UPROPERTY(BlueprintReadOnly)
	FString AttachmentItemName;

	// 添付物数.
	UPROPERTY(BlueprintReadOnly)
	int32 AttachmentCount;


	// コンストラクタ
	FMailData() {}
	FMailData(const MailData &Source);

};

/**
 * メールメニュー
 */
UCLASS()
class ANPANMMO_API UMailMenu : public ULayeredMenuWidgetBase
{
	GENERATED_BODY()
		
public:

	// コンストラクタ
	UMailMenu(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UMailMenu() {}

	// メールリスト要求.
	UFUNCTION(BlueprintCallable, Category = "Mail")
	void SendMailListRequest();

	// パケットを受信した。
	virtual void OnRecvPacket(uint8 ID, MemoryStreamInterface *pStream) override;

protected:

	// 子Widgetから戻ってきた時の処理.
	virtual void OnBackFromChild_Implementation() override;

	// 初期化イベント
	UFUNCTION(BlueprintNativeEvent, Category = "Mail")
	void OnInit(const TArray<FMailData> &MailList);
	void OnInit_Implementation(const TArray<FMailData> &MailList) {}

private:

	// 初期化.
	void Init();

};
