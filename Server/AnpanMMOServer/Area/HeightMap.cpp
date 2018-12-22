/**
 * @file HeightMap.cpp
 * @brief ハイトマップクラス
 * @author YanaP
 */
#include "stdafx.h"
#include "HeightMap.h"
#include "AreaConfig.h"
#include "Math/Vector3D.h"
#include <math.h>

const int HeightMap::RayDivisionCount = 32;

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
	float XRate = (1.0f - (X - AreaConfig::MaxDepth) / (AreaConfig::MinDepth - AreaConfig::MaxDepth));
	float YRate = (1.0f - (Y - AreaConfig::MaxWidth) / (AreaConfig::MinWidth - AreaConfig::MaxWidth));
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

// 移動可能かどうかをチェック
bool HeightMap::CheckMovable(const Vector3D &Start, const Vector3D &End, float ClimbableHeight, Vector3D &OutHit) const
{
	Vector3D Ray = End - Start;
	Vector3D DivisionVec = Ray / RayDivisionCount;
	Vector3D Vec = Vector3D::Zero;
	for (int i = 0; i <= RayDivisionCount; i++)
	{
		Vector3D Point = Start + Vec;
		float Height = GetHeight(Point.X, Point.Y);
		if (fabsf(Height - Point.Z) > ClimbableHeight)
		{
			if (i > 0)
			{
				// 一つ前に戻す。
				Point -= DivisionVec;
			}
			OutHit = Point;
			return true;
		}
		Vec += DivisionVec;
	}

	OutHit = End;
	return false;
}
