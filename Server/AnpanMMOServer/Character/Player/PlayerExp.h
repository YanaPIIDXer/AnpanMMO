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
	 * @fn void Add(u32 Value)
	 * @brief ����
	 * @param[in] Value ������
	 */
	void Add(u32 Value);

	/**
	 * @fn u32 Get() const
	 * @brief �擾
	 * @return �o���l
	 */
	u32 Get() const { return Exp; }

	/**
	 * @fn void SetLevelUpExp(u32 InLevelUpExp)
	 * @brief ���x���A�b�v�ɕK�v�Ȍo���l��ݒ�B
	 * @param[in] InLevelUpExp ���x���A�b�v�ɕK�v�Ȍo���l
	 */
	void SetLevelUpExp(u32 InLevelUpExp) { LevelUpExp = InLevelUpExp; }

	/**
	 * @fn void SetLevelUpCallback(const function<void()> &InLevelUpCallback)
	 * @brief ���x���A�b�v�R�[���o�b�N��ݒ�
	 * @param[in] InLevelUpCallback ���x���A�b�v�R�[���o�b�N
	 */
	void SetLevelUpCallback(const function<void()> &InLevelUpCallback) { LevelUpCallback = InLevelUpCallback; }

private:

	// �o���l
	u32 Exp;

	// ���x���A�b�v�ɕK�v�Ȍo���l.
	u32 LevelUpExp;

	// ���x���A�b�v�R�[���o�b�N
	function<void()> LevelUpCallback;

};

#endif		// #ifndef __PLAYEREXP_H__
