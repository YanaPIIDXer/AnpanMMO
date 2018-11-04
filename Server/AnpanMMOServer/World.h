#ifndef __WORLD_H__
#define __WORLD_H__

#include <vector>
#include "Character/PlayerCharacter.h"

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

private:

	// プレイヤーキャラリスト
	std::vector<PlayerCharacterPtr> PlayerList;


	// PlayerListの更新.
	void UpdatePlayerList();

	// ========== Singleton =========
public:

	static World &GetInstance() { return Instance; }

private:

	// コンストラクタ
	World();
	static World Instance;

};

#endif		// #ifndef __WORLD_H__
