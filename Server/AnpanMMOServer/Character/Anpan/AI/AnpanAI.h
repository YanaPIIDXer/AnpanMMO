/**
 * @file AnpanAI.h
 * @brief �A���p���`�h�N���X
 * @author YanaP
 */
#ifndef __ANPANAI_H__
#define __ANPANAI_H__

#include "AnpanAIPacketData.h"
#include "Hate.h"
#include "WeakPtrDefine.h"

class Anpan;
class AnpanAIStateBase;
struct SkillItem;

/**
 * @class AnpanAI
 * @brief �A���p���`�h
 */
class AnpanAI
{

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] pInParent �A���p��
	 */
	AnpanAI(Anpan *pInParent);

	/**
	 * @brief �f�X�g���N�^
	 */
	~AnpanAI();

	/**
	 * @fn void Poll(int DeltaTime)
	 * @brief ���t���[���̏���
	 * @param[in] DeltaTime �O�t���[������̌o�ߎ���
	 */
	void Poll(int DeltaTime);

	/**
	 * @fn void ChangeState(AnpanAIStateBase *pNewState)
	 * @brief �X�e�[�g�؂�ւ�
	 * @param[in] pNewState �؂�ւ���X�e�[�g
	 */
	void ChangeState(AnpanAIStateBase *pNewState);

	/**
	 * @fn void CreateMovePacketData(const Vector3D &Position, int Time)
	 * @brief �ړ��p�P�b�g�f�[�^�̐���
	 * @param[in] Position ���W
	 * @param[in] Time �ړ�����
	 */
	void CreateMovePacketData(const Vector3D &Position, int Time);

	/**
	 * @fn shared_ptr<AnpanMovePacketData> SweepMovePacketData()
	 * @brief �ړ��p�P�b�g�f�[�^�̎擾
	 * @return �ړ��p�P�b�g�f�[�^��shared_ptr
	 */
	shared_ptr<AnpanMovePacketData> SweepMovePacketData();

	/**
	 * @fn void CreateRotatePacketData(const Rotation &Rot, int Time)
	 * @brief ��]�p�P�b�g�f�[�^�̐���
	 * @param[in] Rot ��]
	 * @param[in] TIme ��]����
	 */
	void CreateRotatePacketData(const Rotation &Rot, int Time);

	/**
	 * @fn shared_ptr<AnpanRotatePacketData> SweepRotatePacketData()
	 * @brief ��]�p�P�b�g�f�[�^�̎擾
	 * @return ��]�p�P�b�g�f�[�^��shared_ptr
	 */
	shared_ptr<AnpanRotatePacketData> SweepRotatePacketData();

	/**
	 * @fn void SetSendStopPacket()
	 * @brief ��~�p�P�b�g�f�[�^�̐ݒ�.
	 */
	void SetSendStopPacket() { bIsNeedSendStopPacket = true; }

	/**
	 * @fn bool SweepSendStopPacketFlag()
	 * @brief ��~�p�P�b�g�̑��M���擾
	 * @return ��~�p�P�b�g�𑗂�K�v������Ȃ�true��Ԃ��B
	 */
	bool SweepSendStopPacketFlag();

	/**
	 * @fn const Hate &GetHate() const
	 * @brief �w�C�g�Ǘ����擾
	 * @return �w�C�g�Ǘ�
	 */
	const Hate &GetHate() const { return HateManager; }

	/**
	 * @fn void Stop()
	 * @brief ��~
	 */
	void Stop();

	/**
	 * @fn void OnSkillReceived(CharacterPtr pCharacter, const SkillItem *pSkill)
	 * @brief �X�L����H������B
	 * @param[in] pCharacter �X�L���g�p��
	 * @param[in] pSkill �H������X�L��
	 */
	void OnSkillReceived(CharacterPtr pCharacter, const SkillItem *pSkill);

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
