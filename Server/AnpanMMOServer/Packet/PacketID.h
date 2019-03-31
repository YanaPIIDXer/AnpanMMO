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
		//! ＧＭメッセージ受信パケット
		ReceiveGMMessage = 0x0C,
		//! 装備変更リクエストパケット
		ChangeEquipRequest = 0x0D,
		//! 装備変更結果パケット
		ChangeEquipResult = 0x0E,
		//! 準備完了パケット
		GameReady = 0x0F,
		//! エリア移動パケット
		AreaMove = 0x10,
		//! エリア移動リクエストパケット
		AreaMoveRequest = 0x11,
		//! エリア移動レスポンスパケット
		AreaMoveResponse = 0x12,
		//! 経験値追加パケット
		AddExp = 0x13,
		//! レベルアップパケット
		LevelUp = 0x14,
		//! ゴールド変化パケット
		ChangeGold = 0x15,
		//! インスタンスマップチケット発行パケット
		InstanceAreaTicketPublish = 0x16,
		//! インスタンスマップチケット処理パケット
		InstanceAreaTicketProcess = 0x17,
		//! インスタンスマップチケット破棄パケット
		InstanceAreaTicketDiscard = 0x18,
		//! インスタンスマップ脱出ポイント生成パケット
		SpawnInstanceAreaExitPoint = 0x19,
		//! ログイン時アイテムリスト通知パケット
		ItemList = 0x1A,
		//! ログイン時アイテムショートカット通知パケット
		ItemShortcut = 0x1B,
		//! アイテム使用パケット
		ItemUse = 0x1C,
		//! アイテム追加パケット
		ItemAdd = 0x1D,
		//! アイテム消費パケット
		ItemSubtract = 0x1E,
		//! アイテム破棄リクエストパケット
		ItemSubtractRequest = 0x1F,
		//! アイテムショートカット保存リクエストパケット
		SaveItemShortcutRequest = 0x20,
		//! アイテムショートカット保存結果パケット
		SaveItemShortcutResult = 0x21,
		//! ログインリクエストパケット
		LogInRequest = 0x22,
		//! ログインリクエスト結果パケット
		LogInResult = 0x23,
		//! キャラクタ作成リクエストパケット
		CreateCharacterRequest = 0x24,
		//! キャラクタ作成結果パケット
		CreateCharacterResult = 0x25,
		//! キャラクタパラメータパケット
		CharacterStatus = 0x26,
		//! メールリスト要求パケット
		MailListRequest = 0x27,
		//! メールリストパケット
		MailList = 0x28,
		//! メール開封パケット
		MailRead = 0x29,
		//! 添付物受信パケット
		MailAttachmentRecv = 0x2A,
		//! 通知リストパケット
		NoticeList = 0x2B,
		//! 通知パケット
		ReceiveNotice = 0x2C,
		//! 会話開始パケット
		NPCTalk = 0x2D,
		//! 選択肢を選択パケット
		NPCTalkSelection = 0x2E,
		//! パーティ作成リクエストパケット
		PartyCreateRequest = 0x2F,
		//! パーティ作成結果パケット
		PartyCreateResult = 0x30,
		//! パーティ勧誘リクエストパケット
		PartyInviteRequest = 0x31,
		//! パーティ勧誘結果パケット
		PartyInviteResult = 0x32,
		//! パーティ勧誘レスポンスパケット
		PartyInviteResponse = 0x33,
		//! パーティ加入パケット
		PartyJoin = 0x34,
		//! パーティメンバ加入パケット
		PartyJoinMember = 0x35,
		//! パーティ離脱リクエストパケット
		PartyExitRequest = 0x36,
		//! パーティ離脱結果パケット
		PartyExitResult = 0x37,
		//! パーティ離脱パケット
		PartyExit = 0x38,
		//! パーティメンバキックリクエストパケット
		PartyKickRequest = 0x39,
		//! パーティメンバキック結果パケット
		PartyKickResult = 0x3A,
		//! パーティメンバキックパケット
		PartyKick = 0x3B,
		//! パーティ解散リクエストパケット
		PartyDissolutionRequest = 0x3C,
		//! パーティ解散結果パケット
		PartyDissolutionResult = 0x3D,
		//! パーティ解散パケット
		PartyDissolution = 0x3E,
		//! Pingパケット
		Ping = 0x3F,
		//! プレイヤーリストパケット
		PlayerList = 0x40,
		//! プレイヤー生成パケット
		SpawnPlayer = 0x41,
		//! プレイヤー移動パケット
		MovePlayer = 0x42,
		//! プレイヤー退出パケット
		ExitPlayer = 0x43,
		//! プレイヤーリスポン要求パケット
		RespawnRequest = 0x44,
		//! プレイヤーリスポンパケット
		PlayerRespawn = 0x45,
		//! クエストデータリストパケット
		QuestData = 0x46,
		//! クエスト受注パケット
		QuestAccept = 0x47,
		//! クエストアンパンキルパケット
		QuestAnpanKill = 0x48,
		//! クエストステージ進行パケット
		QuestStageChange = 0x49,
		//! クエストクリアパケット
		QuestClear = 0x4A,
		//! クエスト破棄リクエストパケット
		QuestRetireRequest = 0x4B,
		//! クエスト破棄レスポンスパケット
		QuestRetireResponse = 0x4C,
		//! アクティブクエスト保存パケット
		SaveActiveQuest = 0x4D,
		//! スクリプトフラグパケット
		ScriptFlag = 0x4E,
		//! アイテム購入要求パケット
		BuyItemRequest = 0x4F,
		//! アイテム購入結果パケット
		BuyItemResult = 0x50,
		//! アイテム売却要求パケット
		SellItemRequest = 0x51,
		//! アイテム売却結果パケット
		SellItemResult = 0x52,
		//! ショップ終了パケット
		ExitShop = 0x53,
		//! スキル使用パケット
		SkillUse = 0x54,
		//! スキル使用失敗パケット
		SkillUseFailed = 0x55,
		//! スキル詠唱開始パケット
		SkillCast = 0x56,
		//! スキル詠唱完了パケット
		SkillCastFinish = 0x57,
		//! スキル発動パケット
		SkillActivate = 0x58,
		//! リキャスト完了パケット
		SkillRecast = 0x59,
		//! スキルリストパケット
		SkillList = 0x5A,
		//! スキルリスト保存リクエストパケット
		SaveSkillListRequest = 0x5B,
		//! スキルリスト保存レスポンスパケット
		SaveSkillListResponse = 0x5C,
		//! スキルツリーデータパケット
		SkillTreeData = 0x5D,
		//! スキルツリー開放要求パケット
		SkillTreeOpenRequest = 0x5E,
		//! スキルツリー開放結果パケット
		SkillTreeOpenResult = 0x5F,
		//! ログイン時の時間通知パケット
		Time = 0x60,
		//! 時間変化通知パケット
		TimeChange = 0x61,
		
	};
};

#endif		// #ifndef __PACKETID_H__
