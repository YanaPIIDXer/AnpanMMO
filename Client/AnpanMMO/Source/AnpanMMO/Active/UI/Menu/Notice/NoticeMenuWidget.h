// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "NoticeMenuWidget.generated.h"

// 通知タイプ
// ※NoticeDataの定義と合わせる事。
UENUM(BlueprintType)
enum class ENoticeType : uint8
{
	// ダミーの定義.
	None,

	// パーティ勧誘.
	PartyInvite,
};

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
	void Action();

	// 通知タイプを取得.
	UFUNCTION(BlueprintPure, Category = "Notice")
	virtual ENoticeType GetNoticeType() const { return ENoticeType::None; }

	// キャラクタ名を取得.
	UFUNCTION(BlueprintPure, Category = "Notice")
	const FString &GetCharacterName() const { return CharacterName; }

protected:

	// 通知に対する行動.
	virtual void OnAction() {}


	// カスタマＩＤ
	uint32 CustomerId;

	// 通知UUID
	uint32 NoticeUuid;

	// キャラクタ名.
	FString CharacterName;

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
	static UPartyInviteNotice *Create(UObject *pOuter, uint32 NoticeUuid, uint32 CustomerId, const FString &CharacterName);

	// コンストラクタ
	UPartyInviteNotice(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UPartyInviteNotice() {}

	// 通知タイプを取得.
	virtual ENoticeType GetNoticeType() const override { return ENoticeType::PartyInvite; }

	// 勧誘を受けるかどうかを設定.
	void SetAccept(bool bInAccept) { bAccept = bInAccept; }

protected:

	// 通知に対する行動.
	virtual void OnAction() override;

private:

	// 勧誘を受けるか？
	bool bAccept;

};

class UNoticeMenuWidget;

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

	// 親を設定.
	UFUNCTION(BlueprintCallable, Category = "Notice")
	void SetParent(UNoticeMenuWidget *pInParent) { pParent = pInParent; }

protected:

	// 通知に対する行動.
	UFUNCTION(BlueprintCallable, Category = "Notice")
	void Action();


	// 通知.
	UPROPERTY(BlueprintReadOnly, Category = "Notice")
	UNoticeBase *pNotice;

private:

	// 親.
	UPROPERTY()
	UNoticeMenuWidget *pParent;

};

/**
 * パーティ勧誘通知アイテム
 * ※勧誘を受けるかどうかを設定する必要があるためC++で定義。
 */
UCLASS()
class ANPANMMO_API UPartyInviteNoticeItem : public UNoticeMenuItem
{

	GENERATED_BODY()

public:

	// コンストラクタ
	UPartyInviteNoticeItem(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UPartyInviteNoticeItem() {}

protected:

	// 勧誘を受けるかどうかを設定.
	UFUNCTION(BlueprintCallable, Category = "PartyInvite")
	void SetAccept(bool bAccept);

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

	// 初期化された。
	UFUNCTION(BlueprintNativeEvent, Category = "Menu")
	void OnInit();
	void OnInit_Implementation() {}


	// 通知リスト
	UPROPERTY(BlueprintReadOnly, Category = "Notice")
	TArray<UNoticeBase *> NoticeList;

private:

	// アセットパス
	static const TCHAR *AssetPath;
	
};
