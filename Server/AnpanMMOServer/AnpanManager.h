#ifndef __ANPANMANAGER_H__
#define __ANPANMANAGER_H__

#include <boost/unordered_map.hpp>
#include <boost/function.hpp>
#include "Character/Anpan/Anpan.h"

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
	void Poll(int DeltaTime);

	// 取得.
	AnpanPtr Get(u32 Uuid) const;

	// 生成時コールバックを設定.
	void SetSpawnCallback(const SpawnFunc &InOnSpawn) { OnSpawn = InOnSpawn; }

	// アンパンリストパケットを生成.
	void MakeListPacket(PacketAnpanList &Packet);

private:

	// 生成インターバル
	static const int SpawnInterval;

	// アンパンリスト
	AnpanMap AnpanList;

	// 次のＵＵＩＤ
	unsigned int NextUuid;

	// 生成時コールバック
	SpawnFunc OnSpawn;

	// 生成までの時間.
	int SpawnTime;


	// アンパン生成.
	void SpawnAnpan();
};

#endif		// #ifndef __ANPANMANAGER_H__
