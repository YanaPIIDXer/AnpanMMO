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

	// 開始時の処理.
	virtual void BeginState();

private:

	// キャラクタロード
	void LoadCharacter();

	// ゲーム準備完了を受信した。
	void OnRecvGameReady(MemoryStreamInterface *pStream);

	// エリア移動要求を受信した。
	void OnRecvAreaMoveRequest(MemoryStreamInterface *pStream);

	// リスポン要求を受信した。
	void OnRecvRespawnRequest(MemoryStreamInterface *pStream);

};

#endif		// #Ifndef __CLIENTSTATEACTIVE_H__
