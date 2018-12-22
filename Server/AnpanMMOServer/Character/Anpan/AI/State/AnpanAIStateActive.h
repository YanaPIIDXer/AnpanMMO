/**
 * @file AnpanAIStateActive.h
 * @brief �A���p���`�h�X�e�[�g�F�A�N�e�B�u���
 * @author YanaP
 */
#ifndef __ANPANAISTATEACTIVE_H__
#define __ANPANAISTATEACTIVE_H__

#include "AnpanAIStateBase.h"

class CharacterBase;

/**
 * @class AnpanAIStateActive
 * @brief �A���p���`�h�X�e�[�g�F�A�N�e�B�u���.
 */
class AnpanAIStateActive : public AnpanAIStateBase
{
	
public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] pInParent �A���p��
	 */
	AnpanAIStateActive(Anpan *pInParent);

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~AnpanAIStateActive() {}

protected:

	/**
	 * @fn virtual void Update(int DeltaTime)
	 * @brief ���t���[���̏���
	 * @param[in] DeltaTime �O�t���[������̌o�ߎ���
	 */
	virtual void Update(int DeltaTime);

private:

	// �u�߂Â����v�Ɣ��肷�鋗��.
	static const float ApproachDist;

	// �U���C���^�[�o��
	static const int AttackInterval;

	// ���݂̃^�[�Q�b�g
	weak_ptr<CharacterBase> pCurrentTarget;

	// �U���^�C�}�[
	int AttackTimer;


	// ��]���X�V.
	void UpdateRotate();

	// �ړ����X�V.
	void UpdateMove();

	// �U�����X�V.
	void UpdateAttack(int DeltaTime);

	// �^�[�Q�b�g�̕����������B
	void RotateToTarget();

	// �^�[�Q�b�g�Ɍ������Ĉړ�����B
	void MoveToTarget();

	// �ڋ߂��Ă��邩�H
	bool IsApproached();

};


#endif		// #ifndef __ANPANAISTATEACTIVE_H__
