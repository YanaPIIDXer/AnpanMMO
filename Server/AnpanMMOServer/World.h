#ifndef __WORLD_H__
#define __WORLD_H__

#include <boost/unordered_map.hpp>
#include "Character/Player/PlayerCharacter.h"
#include "PlayerManager.h"
#include "AnpanManager.h"

class PacketBase;
class MemoryStreamInterface;

/**
 * ワールドクラス
 */
class World : noncopyable
{

public:

	// 初期化.
	void Initialize();

	// 毎フレームの処理.
	void Poll(int DeltaTime);

	// プレイヤーキャラの追加.
	void AddPlayerCharacter(const PlayerCharacterPtr &pPlayer);

	// パケットをブロードキャスト
	void BroadcastPacket(PacketBase *pPacket);

	// プレイヤー移動を受信した。
	void OnRecvMove(Client *pClient, MemoryStreamInterface *pStream);

	// 攻撃を受信した。
	void OnRecvAttack(Client *pClient, MemoryStreamInterface *pStream);

	// リスポンリクエスト受信.
	void OnRecvRespawnRequest(Client *pClient, MemoryStreamInterface *pStream);

	// プレイヤーキャラクタを取得.
	PlayerCharacterPtr GetPlayer(u32 Uuid) const;

	// アンパンを取得.
	AnpanPtr GetAnpan(u32 Uuid) const;

private:

	// プレイヤー管理.
	PlayerManager PlayerMgr;
	
	// アンパン管理.
	AnpanManager AnpanMgr;


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
