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
		//! バフ追加パケット
		AddBuff = 0x08,
		//! バフ消失パケット
		RemoveBuff = 0x09,
		//! チャット送信パケット
		SendChat = 0x0A,
		//! チャット受信パケット
		ReceiveChat = 0x0B,
		//! 装備変更リクエストパケット
		ChangeEquipRequest = 0x0C,
		//! 装備変更結果パケット
		ChangeEquipResult = 0x0D,
		//! 準備完了パケット
		GameReady = 0x0E,
		//! エリア移動パケット
		AreaMove = 0x0F,
		//! エリア移動リクエストパケット
		AreaMoveRequest = 0x10,
		//! エリア移動レスポンスパケット
		AreaMoveResponse = 0x11,
		//! 経験値追加パケット
		AddExp = 0x12,
		//! レベルアップパケット
		LevelUp = 0x13,
		//! ゴールド変化パケット
		ChangeGold = 0x14,
		//! インスタンスマップチケット発行パケット
		InstanceAreaTicketPublish = 0x15,
		//! インスタンスマップチケット処理パケット
		InstanceAreaTicketProcess = 0x16,
		//! インスタンスマップチケット破棄パケット
		InstanceAreaTicketDiscard = 0x17,
		//! インスタンスマップ脱出ポイント生成パケット
		SpawnInstanceAreaExitPoint = 0x18,
		//! ログイン時アイテムリスト通知パケット
		ItemList = 0x19,
		//! ログイン時アイテムショートカット通知パケット
		ItemShortcut = 0x1A,
		//! アイテム使用パケット
		ItemUse = 0x1B,
		//! アイテム追加パケット
		ItemAdd = 0x1C,
		//! アイテム消費パケット
		ItemSubtract = 0x1D,
		//! アイテム破棄リクエストパケット
		ItemSubtractRequest = 0x1E,
		//! アイテムショートカット保存リクエストパケット
		SaveItemShortcutRequest = 0x1F,
		//! アイテムショートカット保存結果パケット
		SaveItemShortcutResult = 0x20,
		//! ログインリクエストパケット
		LogInRequest = 0x21,
		//! ログインリクエスト結果パケット
		LogInResult = 0x22,
		//! キャラクタ作成リクエストパケット
		CreateCharacterRequest = 0x23,
		//! キャラクタ作成結果パケット
		CreateCharacterResult = 0x24,
		//! キャラクタパラメータパケット
		CharacterStatus = 0x25,
		//! 通知リストパケット
		NoticeList = 0x26,
		//! 通知パケット
		ReceiveNotice = 0x27,
		//! 会話開始パケット
		NPCTalk = 0x28,
		//! 選択肢を選択パケット
		NPCTalkSelection = 0x29,
		//! パーティ作成リクエストパケット
		PartyCreateRequest = 0x2A,
		//! パーティ作成結果パケット
		PartyCreateResult = 0x2B,
		//! パーティ勧誘リクエストパケット
		PartyInviteRequest = 0x2C,
		//! パーティ勧誘結果パケット
		PartyInviteResult = 0x2D,
		//! パーティ勧誘レスポンスパケット
		PartyInviteResponse = 0x2E,
		//! パーティ加入パケット
		PartyJoin = 0x2F,
		//! パーティメンバ加入パケット
		PartyJoinMember = 0x30,
		//! パーティ離脱リクエストパケット
		PartyExitRequest = 0x31,
		//! パーティ離脱結果パケット
		PartyExitResult = 0x32,
		//! パーティ離脱パケット
		PartyExit = 0x33,
		//! パーティメンバキックリクエストパケット
		PartyKickRequest = 0x34,
		//! パーティメンバキック結果パケット
		PartyKickResult = 0x35,
		//! パーティメンバキックパケット
		PartyKick = 0x36,
		//! パーティ解散リクエストパケット
		PartyDissolutionRequest = 0x37,
		//! パーティ解散結果パケット
		PartyDissolutionResult = 0x38,
		//! パーティ解散パケット
		PartyDissolution = 0x39,
		//! Pingパケット
		Ping = 0x3A,
		//! プレイヤーリストパケット
		PlayerList = 0x3B,
		//! プレイヤー生成パケット
		SpawnPlayer = 0x3C,
		//! プレイヤー移動パケット
		MovePlayer = 0x3D,
		//! プレイヤー退出パケット
		ExitPlayer = 0x3E,
		//! プレイヤーリスポン要求パケット
		RespawnRequest = 0x3F,
		//! プレイヤーリスポンパケット
		PlayerRespawn = 0x40,
		//! クエストデータリストパケット
		QuestData = 0x41,
		//! クエスト受注パケット
		QuestAccept = 0x42,
		//! クエストアンパンキルパケット
		QuestAnpanKill = 0x43,
		//! クエストステージ進行パケット
		QuestStageChange = 0x44,
		//! クエストクリアパケット
		QuestClear = 0x45,
		//! クエスト破棄リクエストパケット
		QuestRetireRequest = 0x46,
		//! クエスト破棄レスポンスパケット
		QuestRetireResponse = 0x47,
		//! アクティブクエスト保存パケット
		SaveActiveQuest = 0x48,
		//! スクリプトフラグパケット
		ScriptFlag = 0x49,
		//! アイテム購入要求パケット
		BuyItemRequest = 0x4A,
		//! アイテム購入結果パケット
		BuyItemResult = 0x4B,
		//! アイテム売却要求パケット
		SellItemRequest = 0x4C,
		//! アイテム売却結果パケット
		SellItemResult = 0x4D,
		//! スキル使用パケット
		SkillUse = 0x4E,
		//! スキル使用失敗パケット
		SkillUseFailed = 0x4F,
		//! スキル詠唱開始パケット
		SkillCast = 0x50,
		//! スキル詠唱完了パケット
		SkillCastFinish = 0x51,
		//! スキル発動パケット
		SkillActivate = 0x52,
		//! リキャスト完了パケット
		SkillRecast = 0x53,
		//! スキルリストパケット
		SkillList = 0x54,
		//! スキルリスト保存リクエストパケット
		SaveSkillListRequest = 0x55,
		//! スキルリスト保存レスポンスパケット
		SaveSkillListResponse = 0x56,
		//! スキルツリーデータパケット
		SkillTreeData = 0x57,
		//! スキルツリー開放要求パケット
		SkillTreeOpenRequest = 0x58,
		//! スキルツリー開放結果パケット
		SkillTreeOpenResult = 0x59,
		//! ログイン時の時間通知パケット
		Time = 0x5A,
		//! 時間変化通知パケット
		TimeChange = 0x5B,
		
	};
};

#endif		// #ifndef __PACKETID_H__
