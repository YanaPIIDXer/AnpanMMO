/**
 * @file AnpanAIStateActive.h
 * @brief �A���p���`�h�X�e�[�g�F�A�N�e�B�u���
 * @author YanaP
 */
#ifndef __ANPANAISTATEACTIVE_H__
#define __ANPANAISTATEACTIVE_H__

#include "AnpanAIStateBase.h"
#include "WeakPtrDefine.h"

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

	// ���݂̍s��
	AIActionPtr pCurrentAction;

	// ���݂̃^�[�Q�b�g
	CharacterPtr pCurrentTarget;

	// �X�L���^�[�Q�b�g
	CharacterPtr pSkillTarget;

	// �ҋ@�^�C�}�[
	int WaitTimer;

	// �A�N�V����������������Ă��邩�H
	bool bInitializedAction;

	// �X�L����������.
	float SkillDistance;


	// �^�[�Q�b�g�̕����������B
	void RotateToTarget();

	// �^�[�Q�b�g�Ɍ������Ĉړ�����B
	void MoveToTarget();

	// �ڋ߂��Ă��邩�H
	bool IsApproached();

	// �^�[�Q�b�g���狗�������B
	void KeepDistanceToTarget();

	// �^�[�Q�b�g���狗������������H
	bool IsKeepedDistanceToTarget();

	// �X�L���g�p.
	void UseSkill();

	// ���̃A�N�V�����ɕύX.
	void ChangeToNextAction();

	// �A�N�V�����̏�����.
	void InitializeAction();

};


#endif		// #ifndef __ANPANAISTATEACTIVE_H__
