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

private:

	// チャットを受信した。
	void OnRecvChat(MemoryStreamInterface *pStream);

	// エリア移動要求を受信した。
	void OnRecvAreaMoveRequest(MemoryStreamInterface *pStream);

	// リスポン要求を受信した。
	void OnRecvRespawnRequest(MemoryStreamInterface *pStream);

};

#endif		// #Ifndef __CLIENTSTATEACTIVE_H__
