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

	// 初期化.
	void Initialize(int InMinHp, int InMaxHp, int InMinAtk, int InMaxAtk, int InMinDef, int InMaxDef, int InMinExp, int InMaxExp);

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

	// アンパンの最大数.
	static const int AnpanMax;

	// アンパンリスト
	AnpanMap AnpanList;

	// 次のＵＵＩＤ
	unsigned int NextUuid;

	// 生成時コールバック
	SpawnFunc OnSpawn;

	// 生成までの時間.
	int SpawnTime;

	// 最小ＨＰ
	int MinHp;

	// 最大ＨＰ
	int MaxHp;

	// 最小攻撃力.
	int MinAtk;

	// 最大攻撃力.
	int MaxAtk;

	// 最小防御力.
	int MinDef;

	// 最大防御力.
	int MaxDef;

	// 最小経験値.
	int MinExp;

	// 最大経験値.
	int MaxExp;


	// アンパン生成.
	void SpawnAnpan();

	// 更新処理.
	void Update(int DeltaTime);

};

#endif		// #ifndef __ANPANMANAGER_H__
