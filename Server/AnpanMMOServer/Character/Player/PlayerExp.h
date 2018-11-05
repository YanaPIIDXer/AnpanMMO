#ifndef __PLAYEREXP_H__
#define __PLAYEREXP_H__

#include <boost/function.hpp>

/**
 * �v���C���[�̌o���l�Ǘ�.
 */
class PlayerExp
{

public:

	// �R���X�g���N�^
	PlayerExp(int InExp);

	// �f�X�g���N�^
	~PlayerExp() {}

	// �o���l�ǉ�.
	void Add(int Value);

	// �擾.
	int Get() const { return Exp; }

	// ���x���A�b�v�R�[���o�b�N��ݒ�.
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
