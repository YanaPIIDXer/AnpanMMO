#ifndef __ANPANMANAGER_H__
#define __ANPANMANAGER_H__

#include <boost/unordered_map.hpp>
#include <boost/function.hpp>
#include "Character/Anpan.h"

typedef weak_ptr<Anpan> AnpanPtr;
class PacketAnpanList;

/**
 * アンパン管理クラス
 */
class AnpanManager
{

private:		// 別名定義.

	typedef shared_ptr<Anpan> AnpanSharedPtr;
	typedef unordered_map<unsigned int, AnpanSharedPtr> AnpanMap;
	typedef boost::function<void(unsigned int, AnpanPtr)> SpawnFunc;

public:

	// コンストラクタ
	AnpanManager();

	// デストラクタ
	~AnpanManager() {}

	// 毎フレームの処理.
	void Poll();

	// アンパン生成.
	void SpawnAnpan();

	// 生成時コールバックを設定.
	void SetSpawnCallback(const SpawnFunc &InOnSpawn) { OnSpawn = InOnSpawn; }

	// アンパンリストパケットを生成.
	void MakeListPacket(PacketAnpanList &Packet);

private:

	// アンパンリスト
	AnpanMap AnpanList;

	// 次のＵＵＩＤ
	unsigned int NextUuid;

	// 生成時コールバック
	SpawnFunc OnSpawn;

};

#endif		// #ifndef __ANPANMANAGER_H__
