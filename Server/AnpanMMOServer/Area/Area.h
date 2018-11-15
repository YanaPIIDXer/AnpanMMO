#ifndef __AREA_H__
#define __AREA_H__

#include "PlayerManager.h"
#include "AnpanManager.h"

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
	~Area() {}

	// 毎フレームの処理.
	void Poll(int DeltaTime);

	// プレイヤーキャラの追加.
	void AddPlayerCharacter(const PlayerCharacterPtr &pPlayer);

	// プレイヤーキャラ削除,
	void RemovePlayerCharacter(u32 Uuid);

	// 攻撃を受信した。
	void OnRecvAttack(u32 AttackerUuid, u32 DefencerUuid);
	
	// パケットのブロードキャスト
	void BroadcastPacket(PacketBase *pPacket);
	
private:

	// プレイヤー管理.
	PlayerManager PlayerMgr;

	// アンパン管理.
	AnpanManager AnpanMgr;


	// アンパンが生成された。
	void OnSpawnAnpan(u32 Uuid, AnpanPtr pAnpan);

};

#endif		// #ifndef __AREA_H__
