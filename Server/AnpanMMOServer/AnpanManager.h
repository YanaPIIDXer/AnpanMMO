#ifndef __ANPANMANAGER_H__
#define __ANPANMANAGER_H__

#include <boost/unordered_map.hpp>
#include <boost/function.hpp>
#include "WeakPtrDefine.h"

class PacketAnpanList;
class AnpanPopArea;
class Vector3D;

/**
 * アンパン管理クラス
 */
class AnpanManager
{

private:		// 別名定義.

	typedef shared_ptr<Anpan> AnpanSharedPtr;
	typedef unordered_map<unsigned int, AnpanSharedPtr> AnpanMap;
	typedef boost::function<void(unsigned int, AnpanPtr)> SpawnFunc;
	typedef std::vector<AnpanPopArea *> AnpanPopAreaList;

public:

	// コンストラクタ
	AnpanManager();

	// デストラクタ
	~AnpanManager();

	// 初期化.
	void Initialize(u32 AreaId);

	// 毎フレームの処理.
	void Poll(int DeltaTime);

	// 取得.
	AnpanPtr Get(u32 Uuid) const;

	// 生成時コールバックを設定.
	void SetSpawnCallback(const SpawnFunc &InOnSpawn) { OnSpawn = InOnSpawn; }

	// アンパンリストパケットを生成.
	void MakeListPacket(PacketAnpanList &Packet);

	// アンパンの数を取得.
	u32 GetCount() const { return AnpanList.size(); }

	// 外部からSpawnさせる。
	void Spawn(u32 MasterId, const Vector3D &Position);

	// CharacterPtrとして全取得.
	void GetAllAsCharacterPtr(std::vector<CharacterPtr> &OutList) const;

private:

	// アンパンリスト
	AnpanMap AnpanList;

	// 次のＵＵＩＤ
	unsigned int NextUuid;

	// 生成時コールバック
	SpawnFunc OnSpawn;

	// ポップエリアリスト
	AnpanPopAreaList PopAreaList;


	// アンパン生成.
	void SpawnAnpan(AnpanSharedPtr pAnpan);

	// 更新処理.
	void Update(int DeltaTime);

};

#endif		// #ifndef __ANPANMANAGER_H__
