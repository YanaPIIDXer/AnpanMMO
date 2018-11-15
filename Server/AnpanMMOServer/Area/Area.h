#ifndef __AREA_H__
#define __AREA_H__

#include <boost/enable_shared_from_this.hpp>
#include "PlayerManager.h"
#include "AnpanManager.h"
#include "Math/Vector2D.h"

struct AreaItem;
class PacketBase;

class Area;
typedef weak_ptr<Area> AreaPtr;

/**
 * エリアクラス
 */
class Area : public enable_shared_from_this<Area>
{

public:

	// コンストラクタ
	Area(const AreaItem *pItem);

	// デストラクタ
	virtual ~Area() {}

	// 毎フレームの処理.
	void Poll(int DeltaTime);

	// プレイヤーキャラの追加.
	void AddPlayerCharacter(const PlayerCharacterPtr &pPlayer);

	// プレイヤーキャラ削除,
	void RemovePlayerCharacter(u32 Uuid);

	// 移動を受信した。
	void OnRecvMove(u32 Uuid, float X, float Y, float Rotation);

	// 攻撃を受信した。
	void OnRecvAttack(u32 AttackerUuid, u32 DefencerUuid);
	
	// パケットのブロードキャスト
	void BroadcastPacket(PacketBase *pPacket);

	// ID取得.
	u32 GetId() const { return Id; }
	
private:

	// ID
	u32 Id;

	// プレイヤー管理.
	PlayerManager PlayerMgr;

	// アンパン管理.
	AnpanManager AnpanMgr;


	// アンパンが生成された。
	void OnSpawnAnpan(u32 Uuid, AnpanPtr pAnpan);

};

#endif		// #ifndef __AREA_H__
