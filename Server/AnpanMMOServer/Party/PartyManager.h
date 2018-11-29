#ifndef __PARTYMANAGER_H__
#define __PARTYMANAGER_H__

#include "Party.h"

/**
 * パーティマネージャ
 */
class PartyManager : noncopyable
{

private:		// 別名定義.

	typedef shared_ptr<Party> PartySharedPtr;
	typedef boost::unordered_map<u32, PartySharedPtr> PartyList;

public:

	// デストラクタ
	~PartyManager() {}

	// 毎フレームの処理.
	void Poll();

	// 作成.
	void Create(PlayerCharacterPtr pCreatePlayer);

	// 取得.
	PartyPtr Get(u32 Uuid);

	// 既にどこかのパーティに参加済みか？
	bool IsAlreadyJoined(u32 Uuid);

private:

	// パーティリスト
	PartyList Partys;

	// ============ Singleton =============

public:

	static PartyManager &GetInstance() { return Instance; }

private:

	PartyManager();
	static PartyManager Instance;

};

#endif		// #ifndef __PARTYMANAGER_H__
