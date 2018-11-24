#include "stdafx.h"
#include "Bitmap.h"

const u32 Bitmap::RColorMask = 0x00FF0000;
const u32 Bitmap::GColorMask = 0x0000FF00;
const u32 Bitmap::BColorMask = 0x000000FF;

// �R���X�g���N�^
Bitmap::Bitmap()
	: pColorData(NULL)
{
}

// �f�X�g���N�^
Bitmap::~Bitmap()
{
	delete[] pColorData;
	pColorData = NULL;
}

// ���[�h
bool Bitmap::Load(const std::string &FilePath)
{
	std::ifstream FileStream(FilePath.c_str(), std::ios::in | std::ios::binary);
	if (!FileStream)
	{
		std::cout << FilePath << " Not Found..." << std::endl;
		return false;
	}

	// �w�b�_�̓ǂݍ��݁B
	if (!FileHeader.Read(FileStream)) { return false; }
	if (!InfoData.Read(FileStream)) { return false; }

	pColorData = new Color32[InfoData.Width * InfoData.Height];

	for (int Height = InfoData.Height - 1; Height >= 0; Height--)
	{
		for(int Width = 0; Width < InfoData.Width; Width++)
		{
			u32 BitData = 0;
			ReadFromStream(FileStream, &BitData);
			Color32 Col;
			Col.R = BitData & RColorMask;
			Col.G = BitData & GColorMask;
			Col.B = BitData & BColorMask;
			
			int Index = (Height * InfoData.Width) + Width;
			pColorData[Index] = Col;
		}
	}

	return true;
}

// �F���擾.
Color32 Bitmap::GetColor(int X, int Y) const
{
	int Index = (Y * InfoData.Width) + X;
	return pColorData[Index];
}
