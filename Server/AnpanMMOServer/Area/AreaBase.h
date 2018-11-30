#ifndef __AREABASE_H__
#define __AREABASE_H__

#include <boost/enable_shared_from_this.hpp>
#include "PlayerManager.h"
#include "AnpanManager.h"
#include "HeightMap.h"

struct AreaItem;
class PacketBase;

/**
 * エリア基底クラス
 */
class AreaBase : public enable_shared_from_this<AreaBase>
{

public:

	// コンストラクタ
	AreaBase(const AreaItem *pItem);

	// デストラクタ
	virtual ~AreaBase() {}

	// 毎フレームの処理.
	void Poll(int DeltaTime);

	// プレイヤーキャラの追加.
	void AddPlayerCharacter(const PlayerCharacterPtr &pPlayer);

	// プレイヤーキャラ削除,
	void RemovePlayerCharacter(u32 Uuid);

	// 移動を受信した。
	void OnRecvMove(u32 Uuid, float X, float Y, float Z, float Rotation);

	// 攻撃を受信した。
	void OnRecvAttack(u32 AttackerUuid, u32 DefencerUuid);

	// パケットのブロードキャスト
	void BroadcastPacket(PacketBase *pPacket, Client *pIgnoreClient = NULL);

	// 範囲を指定したパケットのブロードキャスト
	void BroadcastPacketWithRange(PacketBase *pPacket, const Vector3D &Center, float Range, Client *pIgnoreClient = NULL);

	// 高さを取得.
	float GetHeight(float X, float Y) const;

	// 移動可能かどうかをチェック
	bool CheckMovable(const Vector3D &Start, const Vector3D &End, float ClimbableHeight, Vector3D &OutHit) const;

	// ID取得.
	virtual u32 GetId() const = 0;

	// 消去可能か？
	virtual bool IsAbleDelete() const = 0;

	// インスタンスエリアか？
	virtual bool IsInstance() const { return false; }

protected:

	// プレイヤー管理.
	PlayerManager PlayerMgr;

	// アンパン管理.
	AnpanManager AnpanMgr;

private:

	// ハイトマップ
	HeightMap HeightData;


	// アンパンが生成された。
	void OnSpawnAnpan(u32 Uuid, AnpanPtr pAnpan);

};

#endif		// #ifndef __AREABASE_H__
