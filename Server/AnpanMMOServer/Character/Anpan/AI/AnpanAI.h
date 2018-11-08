#ifndef __ANPANAI_H__
#define __ANPANAI_H__

#include "AnpanAIPacketData.h"
#include "Hate.h"

class Anpan;
class AnpanAIStateBase;
class CharacterBase;

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
	shared_ptr<AnpanMovePacketData> SweepMovePacketData();

	// ��]�p�P�b�g�f�[�^�̐���.
	void CreateRotatePacketData(const Rotation &Rot, int Time);

	// ��]�p�P�b�g�f�[�^�̎擾.
	shared_ptr<AnpanRotatePacketData> SweepRotatePacketData();

	// ��~�p�P�b�g�̑��M���Z�b�g�B
	void SetSendStopPacket() { bIsNeedSendStopPacket = true; }

	// ��~�p�P�b�g�̑��M���擾.
	bool SweepSendStopPacketFlag();

	// �_���[�W���󂯂��B
	void OnDamaged(weak_ptr<CharacterBase> pAttacker, int DamageValue);

	// �w�C�g�Ǘ��擾.
	const Hate &GetHate() const { return HateManager; }

private:

	// �e.
	Anpan *pParent;

	// �X�e�[�g
	AnpanAIStateBase *pState;

	// �O��State
	AnpanAIStateBase *pPrevState;

	// �ړ��p�P�b�g�f�[�^
	shared_ptr<AnpanMovePacketData> pMovePacketData;

	// ��]�p�P�b�g�f�[�^
	shared_ptr<AnpanRotatePacketData> pRotatePacketData;

	// �w�C�g�Ǘ�.
	Hate HateManager;

	// ��~�p�P�b�g�𑗂�K�v�����邩�H
	bool bIsNeedSendStopPacket;

};

#endif		// #ifndef __ANPANAI_H__
