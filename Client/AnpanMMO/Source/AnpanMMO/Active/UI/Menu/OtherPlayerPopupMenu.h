// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OtherPlayerPopupMenu.generated.h"

class AOtherPlayerCharacter;

/**
 * 他人に関するポップアップメニュー
 */
UCLASS()
class ANPANMMO_API UOtherPlayerPopupMenu : public UUserWidget
{

	GENERATED_BODY()

public:

	// 表示.
	static UOtherPlayerPopupMenu *Show(UObject *pOuter, AOtherPlayerCharacter *pCharacter);

	// コンストラクタ
	UOtherPlayerPopupMenu(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UOtherPlayerPopupMenu() {}

protected:

	// パーティに勧誘できるか？
	UFUNCTION(BlueprintPure, Category = "Party")
	bool IsAblePartyInvite() const;

	// パーティ勧誘を送信.
	UFUNCTION(BlueprintCallable, Category = "Party")
	void SendPartyInvite();

	// メニューを消去.
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void EraseMenu();


	// キャラクタ名.
	UPROPERTY(BlueprintReadOnly, Category = "Character")
	FString CharacterName;

private:

	// アセットパス
	static const TCHAR *AssetPath;

	// キャラのUUID
	uint32 CharacterUuid;
	
};
