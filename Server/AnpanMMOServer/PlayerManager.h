#ifndef __PLAYERMANAGER_H__
#define __PLAYERMANAGER_H__

#include <boost/unordered_map.hpp>
#include "Math/Vector3D.h"

class PlayerCharacter;
typedef weak_ptr<PlayerCharacter> PlayerCharacterPtr;
class PacketBase;
class Client;
class PacketPlayerList;

/**
 * プレイヤー管理クラス
 */
class PlayerManager
{

private:		// 別名定義.

	typedef unordered_map<u32, PlayerCharacterPtr> PlayerMap;

public:

	// コンストラクタ
	PlayerManager();

	// デストラクタ
	~PlayerManager() {}

	// 毎フレームの処理.
	void Poll();

	// 追加.
	void Add(u32 Uuid, PlayerCharacterPtr pPlayer);

	// 削除.
	void Remove(u32 Uuid);

	// 取得.
	PlayerCharacterPtr Get(u32 Uuid) const;

	// 移動を受信した。
	void OnRecvMove(u32 Uuid, float X, float Y, float Z, float Rot);

	// パケットをブロードキャスト
	void BroadcastPacket(PacketBase *pPacket, Client *pIgnoreClient = NULL);

	// 範囲を指定したパケットのブロードキャスト
	void BroadcastPacketWithRange(PacketBase *pPacket, const Vector3D &Center, float Range, Client *pIgnoreClient = NULL);

	// プレイヤー数を取得.
	u32 GetCount() const { return PlayerList.size(); }

private:

	// プレイヤーマップ
	PlayerMap PlayerList;


	// プレイヤーリストパケットを生成.
	void MakeListPacket(PacketPlayerList &Packet);

};

#endif		// #ifndef __PLAYERMANAGER_H__
