#ifndef __WORLD_H__
#define __WORLD_H__

#include <vector>
#include "Character/PlayerCharacter.h"
#include "AnpanManager.h"

class PacketBase;

/**
 * ワールドクラス
 */
class World : noncopyable
{

public:

	// 毎フレームの処理.
	void Poll();

	// プレイヤーキャラの追加.
	void AddPlayerCharacter(const PlayerCharacterPtr &pPlayer);

	// アンパン管理を取得.
	const AnpanManager &GetAnpanManager() const { return AnpanMgr; }

private:

	// プレイヤーキャラリスト
	std::vector<PlayerCharacterPtr> PlayerList;

	// アンパン管理.
	AnpanManager AnpanMgr;


	// PlayerListの更新.
	void UpdatePlayerList();

	// パケットをブロードキャスト
	void BroadcastPacket(PacketBase *pPacket);

	// ========== Singleton =========
public:

	static World &GetInstance() { return Instance; }

private:

	// コンストラクタ
	World();
	static World Instance;

};

#endif		// #ifndef __WORLD_H__
