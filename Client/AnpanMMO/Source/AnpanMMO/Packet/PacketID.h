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
		//! 装備変更リクエストパケット
		ChangeEquipRequest = 0x0A,
		//! 装備変更結果パケット
		ChangeEquipResult = 0x0B,
		//! 準備完了パケット
		GameReady = 0x0C,
		//! エリア移動パケット
		AreaMove = 0x0D,
		//! エリア移動リクエストパケット
		AreaMoveRequest = 0x0E,
		//! エリア移動レスポンスパケット
		AreaMoveResponse = 0x0F,
		//! 経験値追加パケット
		AddExp = 0x10,
		//! レベルアップパケット
		LevelUp = 0x11,
		//! ゴールド変化パケット
		ChangeGold = 0x12,
		//! インスタンスマップチケット発行パケット
		InstanceAreaTicketPublish = 0x13,
		//! インスタンスマップチケット処理パケット
		InstanceAreaTicketProcess = 0x14,
		//! インスタンスマップチケット破棄パケット
		InstanceAreaTicketDiscard = 0x15,
		//! インスタンスマップ脱出ポイント生成パケット
		SpawnInstanceAreaExitPoint = 0x16,
		//! ログイン時アイテムリスト通知パケット
		ItemList = 0x17,
		//! ログイン時アイテムショートカット通知パケット
		ItemShortcut = 0x18,
		//! アイテム使用パケット
		ItemUse = 0x19,
		//! アイテム追加パケット
		ItemAdd = 0x1A,
		//! アイテム消費パケット
		ItemSubtract = 0x1B,
		//! アイテム破棄リクエストパケット
		ItemSubtractRequest = 0x1C,
		//! アイテムショートカット保存リクエストパケット
		SaveItemShortcutRequest = 0x1D,
		//! アイテムショートカット保存結果パケット
		SaveItemShortcutResult = 0x1E,
		//! ログインリクエストパケット
		LogInRequest = 0x1F,
		//! ログインリクエスト結果パケット
		LogInResult = 0x20,
		//! キャラクタ作成リクエストパケット
		CreateCharacterRequest = 0x21,
		//! キャラクタ作成結果パケット
		CreateCharacterResult = 0x22,
		//! キャラクタパラメータパケット
		CharacterStatus = 0x23,
		//! 通知リストパケット
		NoticeList = 0x24,
		//! 通知パケット
		ReceiveNotice = 0x25,
		//! 会話開始パケット
		NPCTalk = 0x26,
		//! 選択肢を選択パケット
		NPCTalkSelection = 0x27,
		//! パーティ作成リクエストパケット
		PartyCreateRequest = 0x28,
		//! パーティ作成結果パケット
		PartyCreateResult = 0x29,
		//! パーティ勧誘リクエストパケット
		PartyInviteRequest = 0x2A,
		//! パーティ勧誘結果パケット
		PartyInviteResult = 0x2B,
		//! パーティ勧誘レスポンスパケット
		PartyInviteResponse = 0x2C,
		//! パーティ加入パケット
		PartyJoin = 0x2D,
		//! パーティメンバ加入パケット
		PartyJoinMember = 0x2E,
		//! パーティ離脱リクエストパケット
		PartyExitRequest = 0x2F,
		//! パーティ離脱結果パケット
		PartyExitResult = 0x30,
		//! パーティ離脱パケット
		PartyExit = 0x31,
		//! パーティメンバキックリクエストパケット
		PartyKickRequest = 0x32,
		//! パーティメンバキック結果パケット
		PartyKickResult = 0x33,
		//! パーティメンバキックパケット
		PartyKick = 0x34,
		//! パーティ解散リクエストパケット
		PartyDissolutionRequest = 0x35,
		//! パーティ解散結果パケット
		PartyDissolutionResult = 0x36,
		//! パーティ解散パケット
		PartyDissolution = 0x37,
		//! Pingパケット
		Ping = 0x38,
		//! プレイヤーリストパケット
		PlayerList = 0x39,
		//! プレイヤー生成パケット
		SpawnPlayer = 0x3A,
		//! プレイヤー移動パケット
		MovePlayer = 0x3B,
		//! プレイヤー退出パケット
		ExitPlayer = 0x3C,
		//! プレイヤーリスポン要求パケット
		RespawnRequest = 0x3D,
		//! プレイヤーリスポンパケット
		PlayerRespawn = 0x3E,
		//! クエストデータリストパケット
		QuestData = 0x3F,
		//! クエスト受注パケット
		QuestAccept = 0x40,
		//! クエストアンパンキルパケット
		QuestAnpanKill = 0x41,
		//! クエストステージ進行パケット
		QuestStageChange = 0x42,
		//! クエストクリアパケット
		QuestClear = 0x43,
		//! クエスト破棄リクエストパケット
		QuestRetireRequest = 0x44,
		//! クエスト破棄レスポンスパケット
		QuestRetireResponse = 0x45,
		//! アクティブクエスト保存パケット
		SaveActiveQuest = 0x46,
		//! スクリプトフラグパケット
		ScriptFlag = 0x47,
		//! スキル使用パケット
		SkillUse = 0x48,
		//! スキル使用失敗パケット
		SkillUseFailed = 0x49,
		//! スキル詠唱開始パケット
		SkillCast = 0x4A,
		//! スキル詠唱完了パケット
		SkillCastFinish = 0x4B,
		//! スキル発動パケット
		SkillActivate = 0x4C,
		//! リキャスト完了パケット
		SkillRecast = 0x4D,
		//! スキルリストパケット
		SkillList = 0x4E,
		//! スキルリスト保存リクエストパケット
		SaveSkillListRequest = 0x4F,
		//! スキルリスト保存レスポンスパケット
		SaveSkillListResponse = 0x50,
		//! スキルツリーデータパケット
		SkillTreeData = 0x51,
		//! スキルツリー開放要求パケット
		SkillTreeOpenRequest = 0x52,
		//! スキルツリー開放結果パケット
		SkillTreeOpenResult = 0x53,
		//! ログイン時の時間通知パケット
		Time = 0x54,
		//! 時間変化通知パケット
		TimeChange = 0x55,
		
	};
};

#endif		// #ifndef __PACKETID_H__
