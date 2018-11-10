// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainHUD.generated.h"

class AGameCharacter;

/**
 * メインHUD
 */
UCLASS()
class ANPANMMO_API UMainHUD : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// 表示.
	static UMainHUD *Show(UObject *pOuter);

	// コンストラクタ
	UMainHUD(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UMainHUD() {}

	// 開始時の処理.
	virtual void NativeConstruct() override;

	// 初期化.
	UFUNCTION(BlueprintNativeEvent, Category = "MainHUD")
	void OnInitialize();
	void OnInitialize_Implementation() {}

protected:

	// 攻撃ボタンが押された。
	UFUNCTION(BlueprintCallable, Category = "Attack")
	void OnPressedAttackButton();

private:
	
	// Blueprintのアセットパス
	static const TCHAR *AssetPath;

	// キャラクタ
	TWeakObjectPtr<AGameCharacter> pCharacter;
	
};
