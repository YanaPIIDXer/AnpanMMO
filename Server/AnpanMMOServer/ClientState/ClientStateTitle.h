#ifndef __CLIENTSTATETITLE_H__
#define __CLIENTSTATETITLE_H__

#include "ClientStateBase.h"

/**
 * タイトル画面State
 */
class ClientStateTitle : public ClientStateBase
{

public:

	// コンストラクタ
	ClientStateTitle(Client *pInParent);

private:

	// ログインリクエストを受信した。
	void OnRecvLogInRequest(MemoryStreamInterface *pStream);

};

#endif		// #ifndef __CLIENTSTATETITLE_H__
