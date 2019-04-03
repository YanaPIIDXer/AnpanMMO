// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "MailMenu.h"
#include "MailDetail.generated.h"

/**
 * メール詳細.
 */
UCLASS()
class ANPANMMO_API UMailDetail : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()
		
public:

	// コンストラクタ
	UMailDetail(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UMailDetail() {}

	// メールを開く
	UFUNCTION(BlueprintCallable, Category = "Mail")
	void Open(const FMailData &InData);

	// パケットを受信した。
	virtual void OnRecvPacket(uint8 ID, MemoryStreamInterface *pStream) override;

protected:

	// メールを開いた
	UFUNCTION(BlueprintNativeEvent, Category = "Mail")
	void OnOpen();
	void OnOpen_Implementation() {}

	// データを取得.
	UFUNCTION(BlueprintPure, Category = "Mail")
	const FMailData &GetData() const { return Data; }

	// 添付物受信要求を送信.
	UFUNCTION(BlueprintCallable, Category = "Mail")
	void SendRecvAttachmentRequest();

	// 添付物があるか？
	// ※受注済みの場合でもtrueを返す。
	UFUNCTION(BlueprintPure, Category = "Mail")
	bool HasAttachment() const { return (Data.AttachmentType != EMailAttachmentType::None); }

private:
	
	// データ
	FMailData Data;

};
