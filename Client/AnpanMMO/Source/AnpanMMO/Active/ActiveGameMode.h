// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MMOGameModeBase.h"
#include "Character/Player/PlayerManager.h"
#include "Character/Anpan/AnpanManager.h"
#include "WarpPoint/WarpPointManager.h"
#include "ActiveGameMode.generated.h"

class UMainHUD;
class UGameMenuWidget;
class ULevelManager;

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

	// マップロード開始.
	void StartLevelLoad(uint32 AreaId);

	// レベルロードが完了した。
	void OnLevelLoadFinished();

	// ゲームメニューを表示.
	void ShowGameMenu();

	// ゲームメニューが閉じられた。
	void OnCloseGameMenu();
	
protected:

private:

	// プレイヤー管理.
	PlayerManager PlayerMgr;

	// アンパン管理.
	AnpanManager AnpanMgr;

	// ワープポイントマネージャ
	WarpPointManager WarpPointMgr;

	// MainHUD
	UPROPERTY()
	UMainHUD *pMainHUD;

	// ゲームメニュー
	UPROPERTY()
	UGameMenuWidget *pGameMenu;

	// レベル管理.
	UPROPERTY()
	ULevelManager *pLevelManager;

	// MainHUDを初期化したか？
	bool bInitializedMainHUD;


	// エリア移動を受信した。
	void OnRecvAreaMove(MemoryStreamInterface *pStream);

	// ダメージを受信した。
	void OnRecvDamage(MemoryStreamInterface *pStream);

	// 経験値を受信した。
	void OnRecvAddExp(MemoryStreamInterface *pStream);

	// レベルアップを受信した。
	void OnRecvLevelUp(MemoryStreamInterface *pStream);

	// エリア移動結果を受信した。
	void OnRecvAreaMoveResponse(MemoryStreamInterface *pStream);

	// リスポンを受信した。
	void OnRecvRespawn(MemoryStreamInterface *pStream);

	// チャットを受信した。
	void OnRecvChat(MemoryStreamInterface *pStream);

};
