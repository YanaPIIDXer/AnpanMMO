// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OtherPlayerMenu.generated.h"

class AOtherPlayerCharacter;

/**
 * 他人に関するポップアップメニュー
 */
UCLASS()
class ANPANMMO_API UOtherPlayerMenu : public UUserWidget
{

	GENERATED_BODY()

public:

	// コンストラクタ
	UOtherPlayerMenu(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UOtherPlayerMenu() {}

	// セットアップ
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void Setup(AOtherPlayerCharacter *pCharacter);

protected:

	// パーティに勧誘できるか？
	UFUNCTION(BlueprintPure, Category = "Party")
	bool IsAblePartyInvite() const;

	// パーティ勧誘を送信.
	UFUNCTION(BlueprintCallable, Category = "Party")
	void SendPartyInvite();


	// キャラクタ名.
	UPROPERTY(BlueprintReadOnly, Category = "Character")
	FString CharacterName;

private:

	// キャラのUUID
	uint32 CharacterUuid;
	
};
