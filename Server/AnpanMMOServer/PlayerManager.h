#ifndef __PLAYERMANAGER_H__
#define __PLAYERMANAGER_H__

#include <boost/unordered_map.hpp>
#include "Character/Player/PlayerCharacter.h"

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
	void Add(u8 Uuid, PlayerCharacterPtr pPlayer);

	// 取得.
	PlayerCharacterPtr Get(u8 Uuid) const;

private:

	// プレイヤーマップ
	PlayerMap PlayerList;

};

#endif		// #ifndef __PLAYERMANAGER_H__
