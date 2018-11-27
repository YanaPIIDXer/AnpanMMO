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

	// デストラクタ
	virtual ~ClientStateTitle() {}

private:

	// ログインリクエストを受信した。
	void OnRecvLogInRequest(MemoryStreamInterface *pStream);

	// キャラクタ作成リクエストを受信した。
	void OnRecvCreateCharacterRequest(MemoryStreamInterface *pStream);

	// キャッシュサーバからログイン結果を受信した。
	void OnRecvCacheLogInResult(MemoryStreamInterface *pStream);

	// キャッシュサーバからキャラクタ作成結果を受信した。
	void OnRecvCacheCreateCharacterResult(MemoryStreamInterface *pStream);

	// キャッシュサーバからキャラクタデータを受信した。
	void OnRecvCacheCharacterDataResult(MemoryStreamInterface *pStream);

};

#endif		// #ifndef __CLIENTSTATETITLE_H__
