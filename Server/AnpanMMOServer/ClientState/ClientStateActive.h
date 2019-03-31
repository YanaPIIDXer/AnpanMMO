/**
 * @file ClientStateActive.h
 * @brief クライアントステート：ゲーム中
 * @author YanaP
 */
#ifndef __CLIENTSTATEACTIVE_H__
#define __CLIENTSTATEACTIVE_H__

#include "ClientStateBase.h"

/**
 * @class ClientStateActive
 * @brief ゲーム中State
 */
class ClientStateActive : public ClientStateBase
{
		
public:

	/**
	 * @brief コンストラクタ
	 * @param[in] pInParent クライアント
	 */
	ClientStateActive(Client *pInParent);

	/**
	 * @brief デストラクタ
	 */
	virtual ~ClientStateActive() {}

	/**
	 * @fn virtual void BeginState()
	 * @brief State開始時の処理
	 */
	virtual void BeginState();

private:

	// Pingを受信した。
	bool OnRecvPing(MemoryStreamInterface *pStream);

	// 移動を受信した。
	bool OnRecvMove(MemoryStreamInterface *pStream);

	// チャットを受信した。
	bool OnRecvChat(MemoryStreamInterface *pStream);

	// チャットのワードチェック結果を受信した。
	bool OnRecvChatWordCheckResult(MemoryStreamInterface *pStream);

	// エリア移動要求を受信した。
	bool OnRecvAreaMoveRequest(MemoryStreamInterface *pStream);

	// リスポン要求を受信した。
	bool OnRecvRespawnRequest(MemoryStreamInterface *pStream);

	// スキル使用を受信した。
	bool OnRecvSkillUse(MemoryStreamInterface *pStream);

	// パーティ作成要求を受信した。
	bool OnRecvPartyCraeteRequest(MemoryStreamInterface *pStream);

	// パーティ離脱要求を受信した。
	bool OnRecvPartyDissolutionRequest(MemoryStreamInterface *pStream);

	// パーティ離脱要求を受信した。
	bool OnRecvPartyExitRequest(MemoryStreamInterface *pStream);

	// パーティキック要求を受信した。
	bool OnRecvPartyKickRequest(MemoryStreamInterface *pStream);

	// パーティ勧誘要求を受信した。
	bool OnRecvPartyInviteRequest(MemoryStreamInterface *pStream);
	
	// パーティ勧誘レスポンスを受信した。
	bool OnRecvPartyInviteResponse(MemoryStreamInterface *pStream);

	// インスタンスマップチケットの処理を受信した。
	bool OnRecvInstanceAreaTicketProcess(MemoryStreamInterface *pStream);

	// NPCとの会話を受信した。
	bool OnRecvNPCTalk(MemoryStreamInterface *pStream);

	// NPCとの会話での選択肢を受信した。
	bool OnRecvNPCTalkSelection(MemoryStreamInterface *pStream);

	// スキルリスト保存リクエストを受信した。
	bool OnRecvSaveSkillListRequest(MemoryStreamInterface *pStream);

	// キャッシュサーバからスキルリスト保存レスポンスを受信した。
	bool OnRecvCacheSaveSkillListResponse(MemoryStreamInterface *pStream);

	// スキルツリー開放要求を受信した。
	bool OnRecvSkillTreeOpenRequest(MemoryStreamInterface *pStream);

	// アイテム使用を受信した。
	bool OnRecvItemUse(MemoryStreamInterface *pStream);

	// アイテム破棄リクエストを受信した。
	bool OnRecvItemSubtractRequest(MemoryStreamInterface *pStream);

	// アイテムショートカット保存リクエストを受信した。
	bool OnRecvSaveItemShortcutRequest(MemoryStreamInterface *pStream);

	// キャッシュサーバからアイテムショートカット保存結果を受信した。
	bool OnRecvCacheSaveItemShortcutResponse(MemoryStreamInterface *pStream);

	// クエスト破棄要求を受信した。
	bool OnRecvQuestRetireRequest(MemoryStreamInterface *pStream);

	// アクティブクエスト保存を受信した。
	bool OnRecvSaveActiveQuest(MemoryStreamInterface *pStream);

	// 装備変更リクエストを受信した。
	bool OnRecvChangeEquipRequest(MemoryStreamInterface *pStream);

	// キャッシュサーバから装備保存レスポンスを受信した。
	bool OnRecvCacheSaveEquipResponse(MemoryStreamInterface *pStream);

	// アイテム購入要求を受信した。
	bool OnRecvBuyItemRequest(MemoryStreamInterface *pStream);

	// アイテム売却要求を受信した。
	bool OnRecvSellItemRequest(MemoryStreamInterface *pStream);

	// ショップ終了を受信した。
	bool OnRecvExitShop(MemoryStreamInterface *pStream);

	// メールリストリクエストを受信した。
	bool OnRecvMailListRequest(MemoryStreamInterface *pStream);

	// キャッシュサーバからメールリストを受信した。
	bool OnRecvCacheMailList(MemoryStreamInterface *pStream);

	// メール開封を受信した。
	bool OnRecvMailRead(MemoryStreamInterface *pStream);

	// メール添付物受信リクエストを受信した。
	bool OnRecvMailAttachmentRecvRequest(MemoryStreamInterface *pStream);

	// キャッシュサーバからメール添付物受信結果を受信した。
	bool OnRecvCacheMailAttachmentRecvResult(MemoryStreamInterface *pStream);

};

#endif		// #Ifndef __CLIENTSTATEACTIVE_H__
