#ifndef __PLAYEREXP_H__
#define __PLAYEREXP_H__

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

private:

	// ���x���A�b�v�ɕK�v�Ȍo���l.
	static const int LevelUpExp;

	// �o���l
	int Exp;

};

#endif		// #ifndef __PLAYEREXP_H__
