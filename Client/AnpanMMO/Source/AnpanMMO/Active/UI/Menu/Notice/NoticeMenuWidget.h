// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "NoticeMenuWidget.generated.h"

/**
 * 通知基底クラス
 */
UCLASS(Abstract, BlueprintType)
class UNoticeBase : public UObject
{

	GENERATED_BODY()

public:

	// コンストラクタ
	UNoticeBase(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UNoticeBase() {}

	// 通知に対する行動.
	UFUNCTION(BlueprintCallable, Category = "Notice")
	virtual void Action() {}

protected:

	// カスタマＩＤ
	uint32 CustomerId;

};

/**
 * パーティ勧誘通知.
 */
UCLASS(BlueprintType)
class UPartyInviteNotice : public UNoticeBase
{

	GENERATED_BODY()

public:

	// 生成.
	static UPartyInviteNotice *Create(uint32 CustomerId);

	// コンストラクタ
	UPartyInviteNotice(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UPartyInviteNotice() {}

	// 通知に対する行動.
	virtual void Action() override;

};

/**
 * 通知メニューのアイテム
 */
UCLASS()
class ANPANMMO_API UNoticeMenuItem : public UUserWidget
{

	GENERATED_BODY()

public:

	// コンストラクタ
	UNoticeMenuItem(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UNoticeMenuItem() {}

	// 通知をセット。
	UFUNCTION(BlueprintCallable, Category = "Notice")
	void SetNotice(UNoticeBase *pInNotice) { pNotice = pInNotice; }

protected:

	// 通知に対する行動.
	UFUNCTION(BlueprintCallable, Category = "Notice")
	void Action();

private:

	// 通知.
	UPROPERTY()
	UNoticeBase *pNotice;

};

/**
 * 通知メニュー
 */
UCLASS()
class ANPANMMO_API UNoticeMenuWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// 表示.
	static void ShowWidget(UObject *pOuter);

	// コンストラクタ
	UNoticeMenuWidget(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UNoticeMenuWidget() {}

	// 開始時の処理.
	virtual void NativeConstruct() override;

protected:

	// 通知リスト
	UPROPERTY(BlueprintReadOnly, Category = "Notice")
	TArray<UNoticeBase *> NoticeList;

private:

	// アセットパス
	static const TCHAR *AssetPath;
	
};
