#ifndef __ANPANAI_H__
#define __ANPANAI_H__

#include "AnpanAIPacketData.h"

class Anpan;
class AnpanAIStateBase;

/**
 * �A���p���`�h�N���X
 */
class AnpanAI
{

public:

	// �R���X�g���N�^
	AnpanAI(Anpan *pInParent);

	// �f�X�g���N�^
	~AnpanAI();

	// ���t���[���̏���.
	void Poll(int DeltaTime);

	// �X�e�[�g�؂�ւ�.
	void ChangeState(AnpanAIStateBase *pNewState);

	// �ړ��p�P�b�g�f�[�^�̐���.
	void CreateMovePacketData(const Vector2D &Position, int Time);

	// �ړ��p�P�b�g�f�[�^�̎擾.
	AnpanMovePacketData *SweepMovePacketData();

	// ��]�p�P�b�g�f�[�^�̐���.
	void CreateRotatePacketData(const Rotation &Rot, int Time);

	// ��]�p�P�b�g�f�[�^�̎擾.
	AnpanRotatePacketData *SweepRotatePacketData();

private:

	// �e.
	Anpan *pParent;

	// �X�e�[�g
	AnpanAIStateBase *pState;

	// �ړ��p�P�b�g�f�[�^
	AnpanMovePacketData *pMovePacketData;

	// ��]�p�P�b�g�f�[�^
	AnpanRotatePacketData *pRotatePacketData;

};

#endif		// #ifndef __ANPANAI_H__
