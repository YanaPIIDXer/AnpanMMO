/**
 * @file ClientStateAreaChange.h
 * @brief クライアントステート：エリア切り替え
 * @author YanaP
 */
#ifndef __CLIENTSTATEAREACHANGE_H__
#define __CLIENTSTATEAREACHANGE_H__

#include "ClientStateBase.h"
#include "Math/Vector3D.h"

/**
 * エリア切り替え待ちステート
 */
class ClientStateAreaChange : public ClientStateBase
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] pInParent クライアント
	 */
	ClientStateAreaChange(Client *pInParent, u32 InAreaId, const Vector3D &InPosition);

	/**
	 * @brief デストラクタ
	 */
	virtual ~ClientStateAreaChange() {}

private:

	// エリアＩＤ
	u32 AreaId;

	// 座標.
	Vector3D Position;


	// Pingを受信した。
	bool OnRecvPing(MemoryStreamInterface *pStream);

	// ゲーム準備完了を受信した。
	bool OnRecvGameReady(MemoryStreamInterface *pStream);

};

#endif		// #ifndef __CLIENTSTATEAREACHANGE_H__
