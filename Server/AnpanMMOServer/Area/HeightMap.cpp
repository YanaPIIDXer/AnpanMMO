#include "stdafx.h"
#include "HeightMap.h"

const float HeightMap::MinWidth = -10000.0f;
const float HeightMap::MaxWidth = 10000.0f;
const float HeightMap::MinHeight = -10000.0f;
const float HeightMap::MaxHeight = 10000.0f;
const float HeightMap::MinDepth = -10000.0f;
const float HeightMap::MaxDepth = 10000.0f;

// �R���X�g���N�^
HeightMap::HeightMap()
{
}

// ���[�h
bool HeightMap::Load(const std::string &FilePath)
{
	return Bmp.Load(FilePath);
}

// �������擾.
float HeightMap::GetHeight(float X, float Y) const
{
	float XRate = (X - MaxDepth) / (MinDepth - MaxDepth);
	float YRate = (Y - MaxWidth) / (MinWidth - MaxWidth);
	int XPixel = (int)(Bmp.GetWidth() * XRate);
	int YPixel = (int)(Bmp.GetHeight() * YRate);
	u8 HeightPixel = Bmp.GetPixel(XPixel, YPixel).B;
	float PixelRate = HeightPixel / 255.0f;
	float Height = (MinHeight - MaxHeight) * PixelRate;
	return Height;
}
