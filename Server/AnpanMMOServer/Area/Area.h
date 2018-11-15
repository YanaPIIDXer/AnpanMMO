#ifndef __AREA_H__
#define __AREA_H__

#include "PlayerManager.h"
#include "AnpanManager.h"

struct AreaItem;

/**
 * エリアクラス
 */
class Area
{

public:

	// コンストラクタ
	Area(const AreaItem *pItem);

	// デストラクタ
	~Area() {}

	// 毎フレームの処理.
	void Poll(int DeltaTime);
	
private:

	// プレイヤー管理.
	PlayerManager PlayerMgr;

	// アンパン管理.
	AnpanManager AnpanMgr;


	// アンパンが生成された。
	void OnSpawnAnpan(u32 Uuid, AnpanPtr pAnpan);

};

#endif		// #ifndef __AREA_H__
