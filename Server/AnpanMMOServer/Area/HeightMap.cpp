#include "stdafx.h"
#include "HeightMap.h"
#include "Math/Vector3D.h"

const int HeightMap::RayDivisionCount = 32;
const float HeightMap::MinWidth = -10000.0f;
const float HeightMap::MaxWidth = 10000.0f;
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

// レイキャスト
bool HeightMap::Raycast(const Vector3D &Start, const Vector3D &End, Vector3D &OutHit) const
{
	Vector3D Ray = End - Start;
	Vector3D DivisionVec = Ray / RayDivisionCount;
	Vector3D Vec = Vector3D::Zero;
	for (int i = 0; i < RayDivisionCount; i++)
	{
		Vec += DivisionVec;
		Vector3D Point = Start + Vec;
		float Height = GetHeight(Point.X, Point.Y);
		if (Point.Z <= Height)
		{
			OutHit = Point;
			return true;
		}
	}

	OutHit = End;
	return false;
}
