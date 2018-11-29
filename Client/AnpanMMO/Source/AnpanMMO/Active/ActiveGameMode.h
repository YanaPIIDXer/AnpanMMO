// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MMOGameModeBase.h"
#include "Character/Player/PlayerManager.h"
#include "Character/Anpan/AnpanManager.h"
#include "WarpPoint/WarpPointManager.h"
#include "Party/PartyInformation.h"
#include "ActiveGameMode.generated.h"

class UMainHUD;
class UGameMenuWidget;
class UOtherPlayerPopupMenu;
class ULevelManager;
class AOtherPlayerCharacter;

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

	// 他人のポップアップメニューを表示.
	void ShowOtherPlayerPopupMenu(AOtherPlayerCharacter *pCharacter);

	// 他人のポップアップメニューを消去.
	void EraseOtherPlayerPopupMenu();

	// パーティ情報取得.
	const PartyInformation &GetPartyInfo() const { return PartyInfo; }

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

	// 他人のポップアップメニュー
	UPROPERTY()
	UOtherPlayerPopupMenu *pOtherPlayerMenu;

	// レベル管理.
	UPROPERTY()
	ULevelManager *pLevelManager;

	// パーティ情報.
	PartyInformation PartyInfo;

	// MainHUDを初期化したか？
	bool bInitializedMainHUD;


	// ゲームメニューが閉じられた。
	void OnCloseGameMenu();

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

	// パーティ勧誘結果を受信した。
	void OnRecvPartyInviteResult(MemoryStreamInterface *pStream);

};
