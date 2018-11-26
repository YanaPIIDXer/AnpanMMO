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

	// 移動可能かどうかをチェック
	bool CheckMovable(const Vector3D &Start, const Vector3D &End, float ClimbableHeight, Vector3D &OutHit) const;

private:

	// レイ分割数.
	static const int RayDivisionCount;

	// ビットマップデータ
	Bitmap Bmp;

};

#endif		// #ifndef __HEIGHTMAP_H__
