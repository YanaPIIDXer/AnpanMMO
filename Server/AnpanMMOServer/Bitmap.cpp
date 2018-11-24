#include "stdafx.h"
#include "Bitmap.h"

// �R���X�g���N�^
Bitmap::Bitmap()
	: pColorPalette(NULL)
{
}

// �f�X�g���N�^
Bitmap::~Bitmap()
{
	delete[] pColorPalette;
	pColorPalette = NULL;
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

	std::cout << "==== " << FilePath << " ====" << std::endl;
	std::cout << "FileSize:" << FileHeader.FileSize << std::endl;
	std::cout << "Reserved1" << FileHeader.Reserved1 << std::endl;
	std::cout << "Reserved2" << FileHeader.Reserved2 << std::endl;
	std::cout << "HeaderSize:" << InfoData.Size << std::endl;
	std::cout << "Width:" << InfoData.Width << std::endl;
	std::cout << "Height:" << InfoData.Height << std::endl;
	std::cout << "UsedColors:" << InfoData.UsedColors << std::endl;
	std::cout << "==========================================" << std::endl;

	// �J���[�p���b�g�̓ǂݍ��݁B
	pColorPalette = new BitmapPaletteData[InfoData.UsedColors];
	for (unsigned int i = 0; i < InfoData.UsedColors; i++)
	{
		if (!pColorPalette->Read(FileStream)) { return false; }
	}

	return true;
}
