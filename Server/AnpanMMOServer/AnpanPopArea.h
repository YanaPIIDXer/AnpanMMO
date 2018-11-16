#ifndef __ANPANPOPAREA_H__
#define __ANPANPOPAREA_H__

#include "Math/Vector2D.h"

struct AnpanPopAreaItem;

/**
 * �A���p�������������G���A
 */
class AnpanPopArea
{

public:

	// �R���X�g���N�^
	AnpanPopArea(const AnpanPopAreaItem *pMasterItem);

	// �f�X�g���N�^
	~AnpanPopArea() {}

	// ���t���[���̏���.
	void Poll(int DeltaTime);

private:

	// ���a.
	float Range;

	// ���W.
	Vector2D Position;

	// �ŏ�HP
	int MinHp;

	// �ő�HP
	int MaxHp;

	// �ŏ��U����.
	int MinAtk;

	// �ő�U����.
	int MaxAtk;

	// �ŏ��h���.
	int MinDef;

	// �ő�h���.
	int MaxDef;

	// �ŏ��o���l.
	int MinExp;

	// �ő�o���l.
	int MaxExp;

	// �C���^�[�o��
	const unsigned int PopInterval;

	// ���݂̃C���^�[�o��
	unsigned int CurrentInterval;

};

#endif		// #ifndef __ANPANPOPAREA_H__
