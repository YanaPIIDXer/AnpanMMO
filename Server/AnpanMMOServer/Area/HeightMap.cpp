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
