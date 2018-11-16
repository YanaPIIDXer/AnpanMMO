#ifndef __ANPANPOPAREA_H__
#define __ANPANPOPAREA_H__

#include "Math/Vector2D.h"

struct AnpanPopAreaItem;

/**
 * アンパンが生成されるエリア
 */
class AnpanPopArea
{

public:

	// コンストラクタ
	AnpanPopArea(const AnpanPopAreaItem *pMasterItem);

	// デストラクタ
	~AnpanPopArea() {}

	// 毎フレームの処理.
	void Poll(int DeltaTime);

private:

	// 半径.
	float Range;

	// 座標.
	Vector2D Position;

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
	const unsigned int PopInterval;

	// 現在のインターバル
	unsigned int CurrentInterval;

};

#endif		// #ifndef __ANPANPOPAREA_H__
