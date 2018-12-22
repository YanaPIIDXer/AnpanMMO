/**
 * @file HeightMap.h
 * @brief �n�C�g�}�b�v�N���X
 * @author YanaP
 */
#ifndef __HEIGHTMAP_H__
#define __HEIGHTMAP_H__

#include "Bitmap.h"

class Vector3D;

/**
 * @class HeightMap
 * @brief �n�C�g�}�b�v
 */
class HeightMap
{

public:

	/**
	 * @brief �R���X�g���N�^
	 */
	HeightMap();

	/**
	 * @brief �f�X�g���N�^
	 */
	~HeightMap() {}

	/**
	 * @fn bool Load(const std::string &FilePath)
	 * @brief �ǂݍ���
	 * @param[in] FilePath �t�@�C���p�X
	 * @return ����������true��Ԃ�
	 */
	bool Load(const std::string &FilePath);

	/**
	 * @fn float GetHeight(float X, float Z) const
	 * @brief �������擾
	 * @param[in] X �w���W
	 * @param[in] Z �y���W
	 * @return ����
	 */
	float GetHeight(float X, float Z) const;

	/**
	 * @fn bool CheckMovable(const Vector3D &Start, const Vector3D &End, float ClimbableHeight, Vector3D &OutHit) const
	 * @brief �ړ��ł��邩�ǂ������`�F�b�N
	 * @details ���C�L���X�g�ɂ��`�F�b�N
	 * @param[in] Start �`�F�b�N�J�n�n�_
	 * @param[in] End �`�F�b�N�I���n�_
	 * @param[in] float ClimbableHeight �o�邱�Ƃ��ł��鍂��
	 * @param[out] OutHit ���C�����������n�_
	 * @return �ړ��\�Ȃ�true��Ԃ�
	 */
	bool CheckMovable(const Vector3D &Start, const Vector3D &End, float ClimbableHeight, Vector3D &OutHit) const;

private:

	// ���C������.
	static const int RayDivisionCount;

	// �r�b�g�}�b�v�f�[�^
	Bitmap Bmp;

};

#endif		// #ifndef __HEIGHTMAP_H__
