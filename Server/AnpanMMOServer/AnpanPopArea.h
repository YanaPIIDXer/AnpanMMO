#ifndef __ANPANPOPAREA_H__
#define __ANPANPOPAREA_H__

#include <boost/function.hpp>
#include "Math/Vector2D.h"
#include "AnpanManager.h"

struct AnpanPopAreaItem;
class Anpan;

/**
 * アンパンが生成されるエリア
 */
class AnpanPopArea
{

private:		// 別名定義.

	typedef boost::function<void(shared_ptr<Anpan>)> SpawnFunc;

public:

	// コンストラクタ
	AnpanPopArea(const AnpanPopAreaItem *pMasterItem);

	// デストラクタ
	~AnpanPopArea() {}

	// 毎フレームの処理.
	void Poll(int DeltaTime);

	// 生成した時のコールバック設定.
	void SetSpawnFunction(const SpawnFunc &InSpawnFunction) { SpawnFunction = InSpawnFunction; }

private:

	// 半径.
	float Range;

	// 座標.
	Vector2D Position;

	// 最大生成数,
	u32 MaxCount;

	// 最小HP
	int MinHp;

	// 最大HP
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

	// インターバル
	const int PopInterval;

	// 現在のインターバル
	int CurrentInterval;

	// 生成時コールバック
	SpawnFunc SpawnFunction;

	// このポップエリアが生成したアンパンリスト
	std::vector<AnpanPtr> AnpanList;


	// アンパンを生成.
	void SpawnAnpan();

	// リスト更新.
	void UpdateList();

};

#endif		// #ifndef __ANPANPOPAREA_H__
