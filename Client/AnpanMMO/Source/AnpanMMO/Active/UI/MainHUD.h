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
	void OnHUDInitialize();
	void OnHUDInitialize_Implementation() {}

	// ダメージを受けた。
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "MainHUD")
	void OnDamaged(int32 Value);
	void OnDamaged_Implementation(int32 Value) {}

	// リスポンした。
	UFUNCTION(BlueprintNativeEvent, Category = "Respawn")
	void OnRespawn();
	void OnRespawn_Implementation() {}

	// レベルアップした。
	UFUNCTION(BlueprintNativeEvent, Category = "LevelUp")
	void OnLevelUp();
	void OnLevelUp_Implementation() {}

	// マップチェンジ開始.
	UFUNCTION(BlueprintNativeEvent, Category = "MapChange")
	void OnStartMapChange();
	void OnStartMapChange_Implementation() {}

	// マップ移動が完了した。
	UFUNCTION(BlueprintNativeEvent, Category = "MapChange")
	void OnRecvMapChangeFinished();
	void OnRecvMapChangeFinished_Implementation() {}

	// チャットを受信した。
	UFUNCTION(BlueprintNativeEvent, Category = "Chat")
	void OnRecvChat(const FString &Name, const FString &Message, bool bIsSelf);
	void OnRecvChat_Implementation(const FString &Name, const FString &Message, bool bIsSelf) {}

protected:

	// 攻撃ボタンが押された。
	UFUNCTION(BlueprintCallable, Category = "Attack")
	void OnPressedAttackButton();

	// レベルロード開始.
	UFUNCTION(BlueprintCallable, Category = "MapChange")
	void StartLevelLoad();

	// ゲームメニュー表示.
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void ShowGameMenu();

private:
	
	// Blueprintのアセットパス
	static const TCHAR *AssetPath;

	// キャラクタ
	TWeakObjectPtr<AGameCharacter> pCharacter;
	
};
