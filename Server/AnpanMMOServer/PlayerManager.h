#ifndef __PLAYERMANAGER_H__
#define __PLAYERMANAGER_H__

#include <boost/unordered_map.hpp>

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

private:

	// プレイヤーマップ
	PlayerMap PlayerList;


	// プレイヤーリストパケットを生成.
	void MakeListPacket(PacketPlayerList &Packet);

};

#endif		// #ifndef __PLAYERMANAGER_H__
