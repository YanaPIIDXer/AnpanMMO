#ifndef __CLIENTSTATETITLE_H__
#define __CLIENTSTATETITLE_H__

#include "ClientStateBase.h"
#include "Math/Vector3D.h"

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

	// 最終ログアウト地点.
	u32 LastAreaId;

	// 最終ログアウト位置.
	Vector3D LastPosition;


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

	// キャッシュサーバからスクリプトフラグを受信した。
	void OnRecvCacheScriptFlagResult(MemoryStreamInterface *pStream);

};

#endif		// #ifndef __CLIENTSTATETITLE_H__
