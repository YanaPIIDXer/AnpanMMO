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

	// パケット解析.
	virtual void AnalyzePacket(PacketID ID, MemoryStreamInterface *pStream);

private:

};

#endif		// #Ifndef __CLIENTSTATEACTIVE_H__
