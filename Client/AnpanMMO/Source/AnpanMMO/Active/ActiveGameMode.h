// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MMOGameModeBase.h"
#include "Character/Player/PlayerManager.h"
#include "Character/Anpan/AnpanManager.h"
#include "WarpPoint/WarpPointManager.h"
#include "Party/PartyInformation.h"
#include "Notice/NoticeManager.h"
#include "Ping/PingManager.h"
#include "Level/TimeManager.h"
#include "Character/NPC/NPCManager.h"
#include "ActiveGameMode.generated.h"

class UMainHUD;
class UGameMenuWidget;
class ULevelManager;
class AOtherPlayerCharacter;
class UScriptWidgetRoot;

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

	// パーティ情報取得.
	const PartyInformation &GetPartyInfo() const { return PartyInfo; }

	// 通知リストを取得.
	TArray<NoticeInformation> GetNoticeList() const { return NoticeMgr.GetNoticeList(); }

	// 通知を消去.
	void RemoveNotice(uint32 Uuid) { NoticeMgr.RemoveNotice(Uuid); }

	// 天球をセット。
	void RegisterSkyControl(ASkyControl *pSky);

	// スクリプトの実行開始.
	void StartScript(const FString &ScriptFileName);

	// スクリプトのメッセージ表示.
	void ShowScriptMessage(const FString &Message);

	// スクリプトの選択肢を追加.
	void AddScriptSelection(const FString &Item);

	// スクリプトの選択肢を表示.
	void ShowScriptSelection();

	// スクリプト終了.
	void FinishScript();

	// キャラから見た前方のターゲットを取得.
	AAnpan *FindCenterTarget(float Distance);

protected:

private:

	// プレイヤー管理.
	PlayerManager PlayerMgr;

	// アンパン管理.
	AnpanManager AnpanMgr;

	// ワープポイントマネージャ
	WarpPointManager WarpPointMgr;

	// Ping管理.
	PingManager PingMgr;

	// 時間管理.
	TimeManager TimeMgr;

	// NPC管理.
	NPCManager NPCMgr;

	// MainHUD
	UPROPERTY()
	UMainHUD *pMainHUD;

	// レベル管理.
	UPROPERTY()
	ULevelManager *pLevelManager;

	// スクリプトWidget
	UPROPERTY()
	UScriptWidgetRoot *pScriptWidget;

	// パーティ情報.
	PartyInformation PartyInfo;

	// 通知管理.
	NoticeManager NoticeMgr;

	// MainHUDを初期化したか？
	bool bInitializedMainHUD;


	// キャラクタタイプからキャラクタを取得.
	ACharacterBase *GetCharacterFromType(uint8 CharacterType, uint32 Uuid);

	// エリア移動を受信した。
	void OnRecvAreaMove(MemoryStreamInterface *pStream);

	// ダメージを受信した。
	void OnRecvDamage(MemoryStreamInterface *pStream);

	// 回復を受信した。
	void OnRecvHeal(MemoryStreamInterface *pStream);

	// 経験値を受信した。
	void OnRecvAddExp(MemoryStreamInterface *pStream);

	// レベルアップを受信した。
	void OnRecvLevelUp(MemoryStreamInterface *pStream);

	// エリア移動結果を受信した。
	void OnRecvAreaMoveResponse(MemoryStreamInterface *pStream);

	// リスポンを受信した。
	void OnRecvRespawn(MemoryStreamInterface *pStream);

	// スキルキャストを受信した。
	void OnRecvSkillCast(MemoryStreamInterface *pStream);

	// スキルキャスト完了を受信した。
	void OnRecvSkillCastFinish(MemoryStreamInterface *pStream);

	// スキル発動を受信した。
	void OnRecvSkillActivate(MemoryStreamInterface *pStream);

	// スキル発動失敗を受信した。
	void OnRecvSkillUseFailed(MemoryStreamInterface *pStream);

	// スキルのリキャスト完了を受信した。
	void OnRecvSkillRecast(MemoryStreamInterface *pStream);

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

	// インスタンスエリア脱出ポイント生成を受信した。
	void OnRecvSpawnInstanceAreaExitPoint(MemoryStreamInterface *pStream);

	// ゴールド変化を受信した。
	void OnRecvChangeGold(MemoryStreamInterface *pStream);

	// スキルツリー開放結果を受信した。
	void OnRecvSkillTreeOpenResult(MemoryStreamInterface *pStream);

	// スキルリスト保存レスポンスを受信した。
	void OnRecvSaveSkillListResponse(MemoryStreamInterface *pStream);

	// アイテム追加を受信した。
	void OnRecvAddItem(MemoryStreamInterface *pStream);

	// アイテム消滅を受信した。
	void OnRecvSubtractItem(MemoryStreamInterface *pStream);

};
