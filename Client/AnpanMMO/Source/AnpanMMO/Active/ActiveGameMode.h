// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MMOGameModeBase.h"
#include "Character/Player/PlayerManager.h"
#include "Character/Anpan/AnpanManager.h"
#include "WarpPoint/WarpPointManager.h"
#include "Party/PartyInformation.h"
#include "Notice/NoticeManager.h"
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

	// メインHUDを表示するかどうかを設定.
	void SetHiddenMainHUD(bool bHidden);

	// 他人のポップアップメニューを表示.
	void ShowOtherPlayerPopupMenu(AOtherPlayerCharacter *pCharacter);

	// 他人のポップアップメニューを消去.
	void EraseOtherPlayerPopupMenu();

	// パーティ情報取得.
	const PartyInformation &GetPartyInfo() const { return PartyInfo; }

	// 通知リストを取得.
	TArray<NoticeInformation> GetNoticeList() const { return NoticeMgr.GetNoticeList(); }

	// 通知を消去.
	void RemoveNotice(uint32 Uuid) { NoticeMgr.RemoveNotice(Uuid); }

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

	// 他人のポップアップメニュー
	UPROPERTY()
	UOtherPlayerPopupMenu *pOtherPlayerMenu;

	// レベル管理.
	UPROPERTY()
	ULevelManager *pLevelManager;

	// パーティ情報.
	PartyInformation PartyInfo;

	// 通知管理.
	NoticeManager NoticeMgr;

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

	// キック結果を受信した。
	void OnRecvPartyKickResult(MemoryStreamInterface *pStream);

	// パーティ勧誘結果を受信した。
	void OnRecvPartyInviteResult(MemoryStreamInterface *pStream);

	// インスタンスマップチケット発行を受信した。
	void OnRecvInstanceAreaTicketPublish(MemoryStreamInterface *pStream);

	// インスタンスマップチケット破棄を受信した。
	void OnRecvInstanceAreaTicketDiscard(MemoryStreamInterface *pStream);

};
