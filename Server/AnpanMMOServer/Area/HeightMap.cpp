#include "stdafx.h"
#include "HeightMap.h"
#include "Math/MathUtil.h"

const float HeightMap::MinWidth = -10000.0f;
const float HeightMap::MaxWidth = 10000.0f;
const float HeightMap::MinHeight = -10000.0f;
const float HeightMap::MaxHeight = 10000.0f;
const float HeightMap::MinDepth = -10000.0f;
const float HeightMap::MaxDepth = 10000.0f;

// コンストラクタ
HeightMap::HeightMap()
{
}

// ロード
bool HeightMap::Load(const std::string &FilePath)
{
	return Bmp.Load(FilePath);
}

// 高さを取得.
float HeightMap::GetHeight(float X, float Y) const
{
	float XRate = (X - MaxDepth) / (MinDepth - MaxDepth);
	float YRate = (Y - MaxWidth) / (MinWidth - MaxWidth);
	int XPixel = (int)(Bmp.GetWidth() * XRate);
	int YPixel = (int)(Bmp.GetHeight() * YRate);
	Color24 HeightColor = Bmp.GetPixel(XPixel, YPixel);

	float Height = 0.0f;
	Height += (HeightColor.G << 8);
	Height += HeightColor.B;
	if (HeightColor.R > 0)
	{
		Height *= -1.0f;
	}
	return Height;
}
