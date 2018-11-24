#ifndef __HEIGHTMAP_H__
#define __HEIGHTMAP_H__

#include "Bitmap.h"

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

private:

	// 幅最小値.
	static const float MinWidth;

	// 幅最大値.
	static const float MaxWidth;

	// 高さ最小値.
	static const float MinHeight;

	// 高さ最小値.
	static const float MaxHeight;

	// 奥行き最小値.
	static const float MinDepth;

	// 奥行き最大値.
	static const float MaxDepth;

	// ビットマップデータ
	Bitmap Bmp;

};

#endif		// #ifndef __HEIGHTMAP_H__
