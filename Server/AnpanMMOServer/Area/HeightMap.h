#ifndef __HEIGHTMAP_H__
#define __HEIGHTMAP_H__

#include "Bitmap.h"

/**
 * �n�C�g�}�b�v
 */
class HeightMap
{

public:

	// �R���X�g���N�^
	HeightMap();

	// �f�X�g���N�^
	~HeightMap() {}

	// ���[�h
	bool Load(const std::string &FilePath);

private:

	// ���ŏ��l.
	static const float MinWidth;

	// ���ő�l.
	static const float MaxWidth;

	// �����ŏ��l.
	static const float MinHeight;

	// �����ŏ��l.
	static const float MaxHeight;

	// ���s���ŏ��l.
	static const float MinDepth;

	// ���s���ő�l.
	static const float MaxDepth;

	// �r�b�g�}�b�v�f�[�^
	Bitmap Bmp;

};

#endif		// #ifndef __HEIGHTMAP_H__
