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
	bool OnRecvLogInRequest(MemoryStreamInterface *pStream);

	// キャラクタ作成リクエストを受信した。
	bool OnRecvCreateCharacterRequest(MemoryStreamInterface *pStream);

	// キャッシュサーバからログイン結果を受信した。
	bool OnRecvCacheLogInResult(MemoryStreamInterface *pStream);

	// キャッシュサーバからキャラクタ作成結果を受信した。
	bool OnRecvCacheCreateCharacterResult(MemoryStreamInterface *pStream);

	// キャッシュサーバからキャラクタデータを受信した。
	bool OnRecvCacheCharacterDataResult(MemoryStreamInterface *pStream);

	// キャッシュサーバからスキルリストを受信した。
	bool OnRecvCacheSkillListResponse(MemoryStreamInterface *pStream);

	// キャッシュサーバからスキルツリー情報を受信した。
	bool OnRecvCacheSkillTreeResponse(MemoryStreamInterface *pStream);

	// キャッシュサーバからアイテムリストを受信した。
	bool OnRecvCacheItemListResponse(MemoryStreamInterface *pStream);

	// キャッシュサーバからアイテムショートカットを受信した。
	bool OnRecvCacheItemShortcutResponse(MemoryStreamInterface *pStream);

	// キャッシュサーバからスクリプトフラグを受信した。
	bool OnRecvCacheScriptFlagResponse(MemoryStreamInterface *pStream);

	// キャッシュサーバからクエストデータを受信した。
	bool OnRecvCacheQuestDataResponse(MemoryStreamInterface *pStream);

};

#endif		// #ifndef __CLIENTSTATETITLE_H__
