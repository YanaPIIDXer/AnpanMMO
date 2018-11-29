#ifndef __PARTYMANAGER_H__
#define __PARTYMANAGER_H__

#include "Party.h"

/**
 * パーティマネージャ
 */
class PartyManager : noncopyable
{

private:		// 別名定義.

	typedef boost::unordered_map<u32, PartyPtr> PartyList;

public:

	// デストラクタ
	~PartyManager() {}

	// 毎フレームの処理.
	void Poll();

	// 追加.
	void Add(PartyPtr pParty);

private:

	// パーティリスト
	PartyList Partys;

	// 次に割り振るUUID
	u32 NextUuid;

	// ============ Singleton =============

public:

	static PartyManager &GetInstance() { return Instance; }

private:

	PartyManager();
	static PartyManager Instance;

};

#endif		// #ifndef __PARTYMANAGER_H__
