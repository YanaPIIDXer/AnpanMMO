/**
 * @file PlayerExp.h
 * @brief �v���C���[�o���l�N���X
 * @author YanaP
 */
#ifndef __PLAYEREXP_H__
#define __PLAYEREXP_H__

#include <boost/function.hpp>

/**
 * @class PlayerExp
 * @brief �v���C���[�̌o���l�Ǘ�.
 */
class PlayerExp
{

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] InExp �o���l
	 */
	PlayerExp(int InExp);

	/**
	 * @brief �f�X�g���N�^
	 */
	~PlayerExp() {}

	/**
	 * @fn void Add(int Value)
	 * @brief ����
	 * @param[in] Value ������
	 */
	void Add(int Value);

	/**
	 * @fn int Get() const
	 * @brief �擾
	 * @return �o���l
	 */
	int Get() const { return Exp; }

	/**
	 * @fn void SetLevelUpCallback(const function<void()> &InLevelUpCallback)
	 * @brief ���x���A�b�v�R�[���o�b�N��ݒ�
	 * @param[in] InLevelUpCallback ���x���A�b�v�R�[���o�b�N
	 */
	void SetLevelUpCallback(const function<void()> &InLevelUpCallback) { LevelUpCallback = InLevelUpCallback; }

private:

	// ���x���A�b�v�ɕK�v�Ȍo���l.
	static const int LevelUpExp;

	// �o���l
	int Exp;

	// ���x���A�b�v�R�[���o�b�N
	function<void()> LevelUpCallback;

};

#endif		// #ifndef __PLAYEREXP_H__
