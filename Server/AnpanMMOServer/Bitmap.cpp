#include "stdafx.h"
#include "Bitmap.h"

const u32 Bitmap::RColorMask = 0x00FF0000;
const u32 Bitmap::GColorMask = 0x0000FF00;
const u32 Bitmap::BColorMask = 0x000000FF;

const Color24 Color24::Black(0, 0, 0);

// コンストラクタ
Bitmap::Bitmap()
	: pColorData(NULL)
{
}

// デストラクタ
Bitmap::~Bitmap()
{
	delete[] pColorData;
	pColorData = NULL;
}

// ロード
bool Bitmap::Load(const std::string &FilePath)
{
	std::ifstream FileStream(FilePath.c_str(), std::ios::in | std::ios::binary);
	if (!FileStream)
	{
		std::cout << FilePath << " Not Found..." << std::endl;
		return false;
	}

	// ヘッダの読み込み。
	if (!FileHeader.Read(FileStream)) { return false; }
	if (!InfoData.Read(FileStream)) { return false; }

	pColorData = new Color24[InfoData.Width * InfoData.Height];

	for (int Height = InfoData.Height - 1; Height >= 0; Height--)
	{
		for(int Width = 0; Width < InfoData.Width; Width++)
		{
			u32 BitData = 0;
			ReadFromStream(FileStream, &BitData);
			Color24 Col;
			Col.R = (BitData & RColorMask) >> 16;
			Col.G = (BitData & GColorMask) >> 8;
			Col.B = BitData & BColorMask;

			int Index = (Height * InfoData.Width) + Width;
			pColorData[Index] = Col;
		}
	}

	return true;
}

// ピクセルを取得.
Color24 Bitmap::GetPixel(int X, int Y) const
{
	if (X < 0 || X >= InfoData.Width || Y < 0 || Y >= InfoData.Height) { return Color24::Black; }
	int Index = (Y * InfoData.Width) + X;
	return pColorData[Index];
}
