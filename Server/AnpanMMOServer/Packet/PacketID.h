/**
 * @file $FILE_NAME$
 * @brief パケットＩＤ定義.
 * @author NativePacketGenerator
 */

#ifndef __PACKETID_H__
#define __PACKETID_H__

/**
 * @brief パケットＩＤ定義.
 */
class PacketID
{

public:

	enum EID
	{
		//! アンパンリスト
		AnpanList = 0x01,
		//! アンパン生成
		SpawnAnpan = 0x02,
		//! アンパン移動
		MoveAnpan = 0x03,
		//! アンパン回転
		RotateAnpan = 0x04,
		//! アンパン停止
		StopAnpan = 0x05,
		//! ダメージ
		Damage = 0x06,
		//! 回復
		Heal = 0x07,
		//! チャット送信
		SendChat = 0x08,
		//! チャット受信
		ReceiveChat = 0x09,
		//! 準備完了
		GameReady = 0x0A,
		//! エリア移動
		AreaMove = 0x0B,
		//! エリア移動リクエスト
		AreaMoveRequest = 0x0C,
		//! エリア移動レスポンス
		AreaMoveResponse = 0x0D,
		//! 経験値追加
		AddExp = 0x0E,
		//! レベルアップ
		LevelUp = 0x0F,
		//! ゴールド変化
		ChangeGold = 0x10,
		//! インスタンスマップチケット発行
		InstanceAreaTicketPublish = 0x11,
		//! インスタンスマップチケット処理
		InstanceAreaTicketProcess = 0x12,
		//! インスタンスマップチケット破棄
		InstanceAreaTicketDiscard = 0x13,
		//! インスタンスマップ脱出ポイント生成
		SpawnInstanceAreaExitPoint = 0x14,
		//! ログイン時アイテムリスト通知
		ItemList = 0x15,
		//! ログイン時アイテムショートカット通知
		ItemShortcut = 0x16,
		//! アイテム使用
		ItemUse = 0x17,
		//! アイテム追加
		ItemAdd = 0x18,
		//! アイテム消費
		ItemSubtract = 0x19,
		//! アイテム破棄リクエスト
		ItemSubtractRequest = 0x1A,
		//! アイテムショートカット保存リクエスト
		SaveItemShortcutRequest = 0x1B,
		//! アイテムショートカット保存結果
		SaveItemShortcutResult = 0x1C,
		//! ログインリクエスト
		LogInRequest = 0x1D,
		//! ログインリクエスト結果
		LogInResult = 0x1E,
		//! キャラクタ作成リクエスト
		CreateCharacterRequest = 0x1F,
		//! キャラクタ作成結果
		CreateCharacterResult = 0x20,
		//! キャラクタパラメータ
		CharacterStatus = 0x21,
		//! 通知リスト
		NoticeList = 0x22,
		//! 通知
		ReceiveNotice = 0x23,
		//! 会話開始
		NPCTalk = 0x24,
		//! 選択肢を選択
		NPCTalkSelection = 0x25,
		//! パーティ作成リクエスト
		PartyCreateRequest = 0x26,
		//! パーティ作成結果
		PartyCreateResult = 0x27,
		//! パーティ勧誘リクエスト
		PartyInviteRequest = 0x28,
		//! パーティ勧誘結果
		PartyInviteResult = 0x29,
		//! パーティ勧誘レスポンス
		PartyInviteResponse = 0x2A,
		//! パーティ加入
		PartyJoin = 0x2B,
		//! パーティメンバ加入
		PartyJoinMember = 0x2C,
		//! パーティ離脱リクエスト
		PartyExitRequest = 0x2D,
		//! パーティ離脱結果
		PartyExitResult = 0x2E,
		//! パーティ離脱
		PartyExit = 0x2F,
		//! パーティメンバキックリクエスト
		PartyKickRequest = 0x30,
		//! パーティメンバキック結果
		PartyKickResult = 0x31,
		//! パーティメンバキック
		PartyKick = 0x32,
		//! パーティ解散リクエスト
		PartyDissolutionRequest = 0x33,
		//! パーティ解散結果
		PartyDissolutionResult = 0x34,
		//! パーティ解散
		PartyDissolution = 0x35,
		//! Ping
		Ping = 0x36,
		//! プレイヤーリスト
		PlayerList = 0x37,
		//! プレイヤー生成
		SpawnPlayer = 0x38,
		//! プレイヤー移動
		MovePlayer = 0x39,
		//! プレイヤー退出
		ExitPlayer = 0x3A,
		//! プレイヤーリスポン要求
		RespawnRequest = 0x3B,
		//! プレイヤーリスポン
		PlayerRespawn = 0x3C,
		//! クエストデータリスト
		QuestData = 0x3D,
		//! クエスト受注
		QuestAccept = 0x3E,
		//! クエストアンパンキル
		QuestAnpanKill = 0x3F,
		//! クエストステージ進行
		QuestStageChange = 0x40,
		//! クエストクリア
		QuestClear = 0x41,
		//! クエスト破棄リクエスト
		QuestRetireRequest = 0x42,
		//! クエスト破棄レスポンス
		QuestRetireResponse = 0x43,
		//! アクティブクエスト保存
		SaveActiveQuest = 0x44,
		//! スクリプトフラグ
		ScriptFlag = 0x45,
		//! スキル使用
		SkillUse = 0x46,
		//! スキル使用失敗
		SkillUseFailed = 0x47,
		//! スキル詠唱開始
		SkillCast = 0x48,
		//! スキル詠唱完了
		SkillCastFinish = 0x49,
		//! スキル発動
		SkillActivate = 0x4A,
		//! リキャスト完了
		SkillRecast = 0x4B,
		//! スキルリスト
		SkillList = 0x4C,
		//! スキルリスト保存リクエスト
		SaveSkillListRequest = 0x4D,
		//! スキルリスト保存レスポンス
		SaveSkillListResponse = 0x4E,
		//! スキルツリーデータ
		SkillTreeData = 0x4F,
		//! スキルツリー開放要求
		SkillTreeOpenRequest = 0x50,
		//! スキルツリー開放結果
		SkillTreeOpenResult = 0x51,
		//! ログイン時の時間通知
		Time = 0x52,
		//! 時間変化通知
		TimeChange = 0x53,
		
	};
};

#endif		// #ifndef __PACKETID_H__
