#ifndef __CLIENTSTATEACTIVE_H__
#define __CLIENTSTATEACTIVE_H__

#include "ClientStateBase.h"

/**
 * ゲーム中State
 */
class ClientStateActive : public ClientStateBase
{
		
public:

	// コンストラクタ
	ClientStateActive(Client *pInParent);

	// デストラクタ
	virtual ~ClientStateActive() {}

	// State開始時の処理.
	virtual void BeginState();

private:

	// Pingを受信した。
	void OnRecvPing(MemoryStreamInterface *pStream);

	// 移動を受信した。
	void OnRecvMove(MemoryStreamInterface *pStream);

	// チャットを受信した。
	void OnRecvChat(MemoryStreamInterface *pStream);

	// チャットのワードチェック結果を受信した。
	void OnRecvChatWordCheckResult(MemoryStreamInterface *pStream);

	// エリア移動要求を受信した。
	void OnRecvAreaMoveRequest(MemoryStreamInterface *pStream);

	// リスポン要求を受信した。
	void OnRecvRespawnRequest(MemoryStreamInterface *pStream);

	// スキル使用を受信した。
	void OnRecvSkillUse(MemoryStreamInterface *pStream);

	// パーティ作成要求を受信した。
	void OnRecvPartyCraeteRequest(MemoryStreamInterface *pStream);

	// パーティ離脱要求を受信した。
	void OnRecvPartyDissolutionRequest(MemoryStreamInterface *pStream);

	// パーティ離脱要求を受信した。
	void OnRecvPartyExitRequest(MemoryStreamInterface *pStream);

	// パーティキック要求を受信した。
	void OnRecvPartyKickRequest(MemoryStreamInterface *pStream);

	// パーティ勧誘要求を受信した。
	void OnRecvPartyInviteRequest(MemoryStreamInterface *pStream);
	
	// パーティ勧誘レスポンスを受信した。
	void OnRecvPartyInviteResponse(MemoryStreamInterface *pStream);

	// インスタンスマップチケットの処理を受信した。
	void OnRecvInstanceAreaTicketProcess(MemoryStreamInterface *pStream);

	// NPCとの会話を受信した。
	void OnRecvNPCTalk(MemoryStreamInterface *pStream);

	// NPCとの会話での選択肢を受信した。
	void OnRecvNPCTalkSelection(MemoryStreamInterface *pStream);

};

#endif		// #Ifndef __CLIENTSTATEACTIVE_H__
