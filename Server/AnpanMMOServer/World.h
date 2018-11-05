#ifndef __WORLD_H__
#define __WORLD_H__

#include <boost/unordered_map.hpp>
#include "Character/PlayerCharacter.h"
#include "AnpanManager.h"

class PacketBase;
class MemoryStreamInterface;

/**
 * ワールドクラス
 */
class World : noncopyable
{

private:		// 別名定義.

	typedef unordered_map<u32, PlayerCharacterPtr> PlayerMap;

public:

	// 初期化.
	void Initialize();

	// 毎フレームの処理.
	void Poll();

	// プレイヤーキャラの追加.
	void AddPlayerCharacter(const PlayerCharacterPtr &pPlayer);

	// アンパン生成.
	void SpawnAnpan() { AnpanMgr.SpawnAnpan(); }

	// 攻撃を受信した。
	void OnRecvAttack(Client *pClient, MemoryStreamInterface *pStream);

private:

	// プレイヤーキャラリスト
	PlayerMap PlayerList;

	// アンパン管理.
	AnpanManager AnpanMgr;


	// PlayerListの更新.
	void UpdatePlayerList();

	// パケットをブロードキャスト
	void BroadcastPacket(PacketBase *pPacket);

	// アンパンが生成された。
	void OnSpawnAnpan(unsigned int Uuid, AnpanPtr pAnpan);

	// ========== Singleton =========
public:

	static World &GetInstance() { return Instance; }

private:

	// コンストラクタ
	World();
	static World Instance;

};

#endif		// #ifndef __WORLD_H__
