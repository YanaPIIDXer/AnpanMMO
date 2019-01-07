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

	/**
	 * @enum EID
	 * パケットＩＤ
	 */
	enum EID
	{
		//! アンパンリストパケット
		AnpanList = 0x01,
		//! アンパン生成パケット
		SpawnAnpan = 0x02,
		//! アンパン移動パケット
		MoveAnpan = 0x03,
		//! アンパン回転パケット
		RotateAnpan = 0x04,
		//! アンパン停止パケット
		StopAnpan = 0x05,
		//! ダメージパケット
		Damage = 0x06,
		//! 回復パケット
		Heal = 0x07,
		//! チャット送信パケット
		SendChat = 0x08,
		//! チャット受信パケット
		ReceiveChat = 0x09,
		//! 準備完了パケット
		GameReady = 0x0A,
		//! エリア移動パケット
		AreaMove = 0x0B,
		//! エリア移動リクエストパケット
		AreaMoveRequest = 0x0C,
		//! エリア移動レスポンスパケット
		AreaMoveResponse = 0x0D,
		//! 経験値追加パケット
		AddExp = 0x0E,
		//! レベルアップパケット
		LevelUp = 0x0F,
		//! ゴールド変化パケット
		ChangeGold = 0x10,
		//! インスタンスマップチケット発行パケット
		InstanceAreaTicketPublish = 0x11,
		//! インスタンスマップチケット処理パケット
		InstanceAreaTicketProcess = 0x12,
		//! インスタンスマップチケット破棄パケット
		InstanceAreaTicketDiscard = 0x13,
		//! インスタンスマップ脱出ポイント生成パケット
		SpawnInstanceAreaExitPoint = 0x14,
		//! ログイン時アイテムリスト通知パケット
		ItemList = 0x15,
		//! ログイン時アイテムショートカット通知パケット
		ItemShortcut = 0x16,
		//! アイテム使用パケット
		ItemUse = 0x17,
		//! アイテム追加パケット
		ItemAdd = 0x18,
		//! アイテム消費パケット
		ItemSubtract = 0x19,
		//! アイテム破棄リクエストパケット
		ItemSubtractRequest = 0x1A,
		//! アイテムショートカット保存リクエストパケット
		SaveItemShortcutRequest = 0x1B,
		//! アイテムショートカット保存結果パケット
		SaveItemShortcutResult = 0x1C,
		//! ログインリクエストパケット
		LogInRequest = 0x1D,
		//! ログインリクエスト結果パケット
		LogInResult = 0x1E,
		//! キャラクタ作成リクエストパケット
		CreateCharacterRequest = 0x1F,
		//! キャラクタ作成結果パケット
		CreateCharacterResult = 0x20,
		//! キャラクタパラメータパケット
		CharacterStatus = 0x21,
		//! 通知リストパケット
		NoticeList = 0x22,
		//! 通知パケット
		ReceiveNotice = 0x23,
		//! 会話開始パケット
		NPCTalk = 0x24,
		//! 選択肢を選択パケット
		NPCTalkSelection = 0x25,
		//! パーティ作成リクエストパケット
		PartyCreateRequest = 0x26,
		//! パーティ作成結果パケット
		PartyCreateResult = 0x27,
		//! パーティ勧誘リクエストパケット
		PartyInviteRequest = 0x28,
		//! パーティ勧誘結果パケット
		PartyInviteResult = 0x29,
		//! パーティ勧誘レスポンスパケット
		PartyInviteResponse = 0x2A,
		//! パーティ加入パケット
		PartyJoin = 0x2B,
		//! パーティメンバ加入パケット
		PartyJoinMember = 0x2C,
		//! パーティ離脱リクエストパケット
		PartyExitRequest = 0x2D,
		//! パーティ離脱結果パケット
		PartyExitResult = 0x2E,
		//! パーティ離脱パケット
		PartyExit = 0x2F,
		//! パーティメンバキックリクエストパケット
		PartyKickRequest = 0x30,
		//! パーティメンバキック結果パケット
		PartyKickResult = 0x31,
		//! パーティメンバキックパケット
		PartyKick = 0x32,
		//! パーティ解散リクエストパケット
		PartyDissolutionRequest = 0x33,
		//! パーティ解散結果パケット
		PartyDissolutionResult = 0x34,
		//! パーティ解散パケット
		PartyDissolution = 0x35,
		//! Pingパケット
		Ping = 0x36,
		//! プレイヤーリストパケット
		PlayerList = 0x37,
		//! プレイヤー生成パケット
		SpawnPlayer = 0x38,
		//! プレイヤー移動パケット
		MovePlayer = 0x39,
		//! プレイヤー退出パケット
		ExitPlayer = 0x3A,
		//! プレイヤーリスポン要求パケット
		RespawnRequest = 0x3B,
		//! プレイヤーリスポンパケット
		PlayerRespawn = 0x3C,
		//! クエストデータリストパケット
		QuestData = 0x3D,
		//! クエスト受注パケット
		QuestAccept = 0x3E,
		//! クエストアンパンキルパケット
		QuestAnpanKill = 0x3F,
		//! クエストステージ進行パケット
		QuestStageChange = 0x40,
		//! クエストクリアパケット
		QuestClear = 0x41,
		//! クエスト破棄リクエストパケット
		QuestRetireRequest = 0x42,
		//! クエスト破棄レスポンスパケット
		QuestRetireResponse = 0x43,
		//! アクティブクエスト保存パケット
		SaveActiveQuest = 0x44,
		//! スクリプトフラグパケット
		ScriptFlag = 0x45,
		//! スキル使用パケット
		SkillUse = 0x46,
		//! スキル使用失敗パケット
		SkillUseFailed = 0x47,
		//! スキル詠唱開始パケット
		SkillCast = 0x48,
		//! スキル詠唱完了パケット
		SkillCastFinish = 0x49,
		//! スキル発動パケット
		SkillActivate = 0x4A,
		//! リキャスト完了パケット
		SkillRecast = 0x4B,
		//! スキルリストパケット
		SkillList = 0x4C,
		//! スキルリスト保存リクエストパケット
		SaveSkillListRequest = 0x4D,
		//! スキルリスト保存レスポンスパケット
		SaveSkillListResponse = 0x4E,
		//! スキルツリーデータパケット
		SkillTreeData = 0x4F,
		//! スキルツリー開放要求パケット
		SkillTreeOpenRequest = 0x50,
		//! スキルツリー開放結果パケット
		SkillTreeOpenResult = 0x51,
		//! ログイン時の時間通知パケット
		Time = 0x52,
		//! 時間変化通知パケット
		TimeChange = 0x53,
		
	};
};

#endif		// #ifndef __PACKETID_H__
