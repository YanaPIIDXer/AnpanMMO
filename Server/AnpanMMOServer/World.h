#ifndef __WORLD_H__
#define __WORLD_H__

#include <boost/unordered_map.hpp>
#include "Character/Player/PlayerCharacter.h"
#include "PlayerManager.h"
#include "AnpanManager.h"

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

	// プレイヤー移動を受信した。
	void OnRecvMove(Client *pClient, MemoryStreamInterface *pStream);

	// 攻撃を受信した。
	void OnRecvAttack(Client *pClient, MemoryStreamInterface *pStream);

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
