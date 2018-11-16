#ifndef __CLIENTSTATEAREACHANGE_H__
#define __CLIENTSTATEAREACHANGE_H__

#include "ClientStateBase.h"
#include "Math/Vector2D.h"

/**
 * エリア切り替え待ちステート
 */
class ClientStateAreaChange : public ClientStateBase
{

public:

	// コンストラクタ
	ClientStateAreaChange(Client *pInParent, u32 InAreaId, const Vector2D &InPosition);

	// デストラクタ
	virtual ~ClientStateAreaChange() {}

private:

	// エリアＩＤ
	u32 AreaId;

	// 座標.
	Vector2D Position;


	// ゲーム準備完了を受信した。
	void OnRecvGameReady(MemoryStreamInterface *pStream);

};

#endif		// #ifndef __CLIENTSTATEAREACHANGE_H__