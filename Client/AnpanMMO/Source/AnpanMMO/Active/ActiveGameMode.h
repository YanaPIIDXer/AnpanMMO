// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MMOGameModeBase.h"
#include "Character/Player/PlayerManager.h"
#include "Character/Anpan/AnpanManager.h"
#include "ActiveGameMode.generated.h"

class UMainHUD;

/**
 * ゲーム中GameMode
 */
UCLASS()
class ANPANMMO_API AActiveGameMode : public AMMOGameModeBase
{

	GENERATED_BODY()

public:

	// コンストラクタ
	AActiveGameMode(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~AActiveGameMode() {}

	// 開始時の処理.
	virtual void BeginPlay() override;

	// 毎フレームの処理.
	virtual void Tick(float DeltaTime) override;

	// プレイヤーキャラ追加.
	void AddPlayerCharacter(uint32 Uuid, APlayerCharacterBase *pPlayer);

	// メインHUD取得.
	UFUNCTION(BlueprintPure, Category = "HUD")
	UMainHUD *GetMainHUD() const { return pMainHUD; }
	
protected:

private:

	// プレイヤー管理.
	PlayerManager PlayerMgr;

	// アンパン管理.
	AnpanManager AnpanMgr;

	// MainHUD
	UPROPERTY()
	UMainHUD *pMainHUD;

	// MainHUDを初期化したか？
	bool bInitializedMainHUD;


	// ダメージを受信した。
	void OnRecvDamage(MemoryStreamInterface *pStream);

	// 経験値を受信した。
	void OnRecvAddExp(MemoryStreamInterface *pStream);

	// レベルアップを受信した。
	void OnRecvLevelUp(MemoryStreamInterface *pStream);

};
