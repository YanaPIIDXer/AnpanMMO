// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

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

	// ショップを表示.
	void ShowShop(uint32 ShopId);

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
	bool OnRecvAreaMove(MemoryStreamInterface *pStream);

	// ダメージを受信した。
	bool OnRecvDamage(MemoryStreamInterface *pStream);

	// 回復を受信した。
	bool OnRecvHeal(MemoryStreamInterface *pStream);

	// 経験値を受信した。
	bool OnRecvAddExp(MemoryStreamInterface *pStream);

	// レベルアップを受信した。
	bool OnRecvLevelUp(MemoryStreamInterface *pStream);

	// エリア移動結果を受信した。
	bool OnRecvAreaMoveResponse(MemoryStreamInterface *pStream);

	// リスポンを受信した。
	bool OnRecvRespawn(MemoryStreamInterface *pStream);

	// スキルキャストを受信した。
	bool OnRecvSkillCast(MemoryStreamInterface *pStream);

	// スキルキャスト完了を受信した。
	bool OnRecvSkillCastFinish(MemoryStreamInterface *pStream);

	// スキル発動を受信した。
	bool OnRecvSkillActivate(MemoryStreamInterface *pStream);

	// スキル発動失敗を受信した。
	bool OnRecvSkillUseFailed(MemoryStreamInterface *pStream);

	// スキルのリキャスト完了を受信した。
	bool OnRecvSkillRecast(MemoryStreamInterface *pStream);

	// チャットを受信した。
	bool OnRecvChat(MemoryStreamInterface *pStream);

	// キック結果を受信した。
	bool OnRecvPartyKickResult(MemoryStreamInterface *pStream);

	// パーティ勧誘結果を受信した。
	bool OnRecvPartyInviteResult(MemoryStreamInterface *pStream);

	// インスタンスマップチケット発行を受信した。
	bool OnRecvInstanceAreaTicketPublish(MemoryStreamInterface *pStream);

	// インスタンスマップチケット破棄を受信した。
	bool OnRecvInstanceAreaTicketDiscard(MemoryStreamInterface *pStream);

	// インスタンスエリア脱出ポイント生成を受信した。
	bool OnRecvSpawnInstanceAreaExitPoint(MemoryStreamInterface *pStream);

	// ゴールド変化を受信した。
	bool OnRecvChangeGold(MemoryStreamInterface *pStream);

	// スキルツリー開放結果を受信した。
	bool OnRecvSkillTreeOpenResult(MemoryStreamInterface *pStream);

	// スキルリスト保存レスポンスを受信した。
	bool OnRecvSaveSkillListResponse(MemoryStreamInterface *pStream);

	// アイテム追加を受信した。
	bool OnRecvAddItem(MemoryStreamInterface *pStream);

	// アイテム消滅を受信した。
	bool OnRecvSubtractItem(MemoryStreamInterface *pStream);

	// アイテムショートカット保存結果を受信した。
	bool OnRecvSaveItemShortcutResult(MemoryStreamInterface *pStream);

	// クエスト受注を受信した。
	bool OnRecvAcceptQuest(MemoryStreamInterface *pStream);

	// クエスト進行を受信した。
	bool OnRecvProgressQuest(MemoryStreamInterface *pStream);

	// クエストでのアンパン殺害を受信した。
	bool OnRecvQuestKilledAnpan(MemoryStreamInterface *pStream);

	// クエストクリアを受信した。
	bool OnRecvClearQuest(MemoryStreamInterface *pStream);

	// クエスト破棄レスポンスを受信した。
	bool OnRecvRetireQuestResponse(MemoryStreamInterface *pStream);

	// 装備変更結果を受信した。
	bool OnRecvEquipChangeResult(MemoryStreamInterface *pStream);

	// バフ追加を受信した。
	bool OnRecvAddBuff(MemoryStreamInterface *pStream);

	// バフ消去を受信した。
	bool OnRecvRemoveBuff(MemoryStreamInterface *pStream);
	
};
