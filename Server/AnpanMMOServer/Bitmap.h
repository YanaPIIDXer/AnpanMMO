#ifndef __BITMAP_H__
#define __BITMAP_H__

#include <fstream>
#include "EndianConverter.h"

// �X�g���[������ǂݍ��݁B
template <typename T>
static void ReadFromStream(std::ifstream &FileStream, T *pData)
{
	FileStream.read((char *)pData, sizeof(T));
	if (!EndianConverter::IsLittleEndian())
	{
		// ���g���G���f�B�A�����r�b�N�G���f�B�A��
		*pData = EndianConverter::Convert(*pData, true);
	}
}

// �r�b�g�}�b�v�t�@�C���w�b�_
struct BitmapFileHeader
{
	// �t�@�C���^�C�v
	u16 FileType;

	// �t�@�C���T�C�Y
	u32 FileSize;

	// �\��̈�.
	u16 Reserved1;
	u16 Reserved2;

	// �t�@�C���擪����摜�f�[�^�܂ł̃I�t�Z�b�g
	u32 Offset;


	// �ǂݍ���
	bool Read(std::ifstream &FileStream)
	{
		ReadFromStream(FileStream, &FileType);
		ReadFromStream(FileStream, &FileSize);
		ReadFromStream(FileStream, &Reserved1);
		ReadFromStream(FileStream, &Reserved2);
		ReadFromStream(FileStream, &Offset);
		
		return !FileStream.eof();
	}
};

// �r�b�g�}�b�v���w�b�_
struct BitmapInfoData
{
	// ���w�b�_�T�C�Y
	u32 Size;

	// �摜�̕�.
	s32 Width;

	// �摜�̍���
	s32 Height;

	// �v���[����.
	u16 Planes;
	
	// �F�r�b�g��.
	u16 BitCount;

	// ���k�`��.
	u32 Compression;

	// �摜�f�[�^�T�C�Y
	u32 ImageSize;

	// �����𑜓x.
	s32 XPixelPerMeter;

	// �����𑜓x.
	s32 YPixelPerMeter;

	// �i�[�p���b�g��.
	u32 UsedColors;

	// �d�v�F��.
	u32 ImportantColors;


	// �ǂݍ���
	bool Read(std::ifstream &FileStream)
	{
		ReadFromStream(FileStream, &Size);
		ReadFromStream(FileStream, &Width);
		ReadFromStream(FileStream, &Height);
		ReadFromStream(FileStream, &Planes);
		ReadFromStream(FileStream, &BitCount);
		ReadFromStream(FileStream, &Compression);
		ReadFromStream(FileStream, &ImageSize);
		ReadFromStream(FileStream, &XPixelPerMeter);
		ReadFromStream(FileStream, &YPixelPerMeter);
		ReadFromStream(FileStream, &UsedColors);
		ReadFromStream(FileStream, &ImportantColors);

		return !FileStream.eof();
	}

};

// 32bit�J���[�f�[�^
struct Color32
{

	// ��.
	u8 R;

	// ��.
	u8 G;

	// ��.
	u8 B;

	// �R���X�g���N�^
	Color32()
		: R(0)
		, G(0)
		, B(0) {}

	Color32(u8 InR, u8 InG, u8 InB)
		: R(InR)
		, G(InG)
		, B(InB) {}


	// ��.
	static const Color32 Black;

};

/**
 * �r�b�g�}�b�v�N���X
 */
class Bitmap
{

public:

	// �R���X�g���N�^
	Bitmap();

	// �f�X�g���N�^
	~Bitmap();

	// ���[�h
	bool Load(const std::string &FilePath);

	// �s�N�Z�����擾.
	Color32 GetPixel(int X, int Y) const;

	// �����擾.
	s32 GetWidth() const { return InfoData.Width; }

	// �������擾.
	s32 GetHeight() const { return InfoData.Height; }

private:

	// �Ԃ̃J���[�}�X�N
	static const u32 RColorMask;

	// �΂̃J���[�}�X�N
	static const u32 GColorMask;

	// �̃J���[�}�X�N
	static const u32 BColorMask;

	// �t�@�C���w�b�_
	BitmapFileHeader FileHeader;

	// ���w�b�_
	BitmapInfoData InfoData;

	// �J���[�f�[�^
	Color32 *pColorData;

};

#endif		// #ifndef __BITMAP_H__
