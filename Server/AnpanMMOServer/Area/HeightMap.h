#ifndef __HEIGHTMAP_H__
#define __HEIGHTMAP_H__

#include "Bitmap.h"

class Vector3D;

/**
 * ハイトマップ
 */
class HeightMap
{

public:

	// コンストラクタ
	HeightMap();

	// デストラクタ
	~HeightMap() {}

	// ロード
	bool Load(const std::string &FilePath);

	// 高さを取得.
	float GetHeight(float X, float Z) const;

	// レイキャスト
	bool Raycast(const Vector3D &Start, const Vector3D &End, Vector3D &OutHit) const;

private:

	// レイ分割数.
	static const int RayDivisionCount;

	// 幅最小値.
	static const float MinWidth;

	// 幅最大値.
	static const float MaxWidth;

	// 奥行き最小値.
	static const float MinDepth;

	// 奥行き最大値.
	static const float MaxDepth;

	// ビットマップデータ
	Bitmap Bmp;

};

#endif		// #ifndef __HEIGHTMAP_H__
