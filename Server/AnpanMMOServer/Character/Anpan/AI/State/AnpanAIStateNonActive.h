/**
 * @file AnpanAIStateNonActive.h
 * @brief �A���p���`�h�X�e�[�g�F�m���A�N�e�B�u���
 * @author YanaP
 */
#ifndef __ANPANAISTATENONACTIVE_H__
#define __ANPANAISTATENONACTIVE_H__

#include "AnpanAIStateBase.h"

/**
 * @class AnpanAIStateNonActive
 * @brief �A���p���`�h�X�e�[�g�F�m���A�N�e�B�u���
 */
class AnpanAIStateNonActive : public AnpanAIStateBase
{

public:
	
	/**
	 * @brief �R���X�g���N�^
	 * @param[in] pInParent �A���p��
	 */
	AnpanAIStateNonActive(Anpan *pInParent);

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~AnpanAIStateNonActive() {}

	/**
	 * @fn virtual void OnDamaged()
	 * @brief �_���[�W���󂯂�
	 */
	virtual void OnDamaged();

protected:

	/**
	 * @fn virtual void Update(int DeltaTime)
	 * @brief ���t���[���̏���
	 * @param[in] DeltaTime �O�t���[������̌o�ߎ���
	 */
	virtual void Update(int DeltaTime);

private:

	// �����X�e�[�g
	enum EState
	{
		// �������.
		None,

		// ��~��.
		Stopping,

		// ��]��.
		Rotating,

		// �ړ���.
		Moving,
	};

	// ���݂̓����X�e�[�g
	EState CurrentState;

	// �X�e�[�g����.
	int StateTime;


	// ��~��Ԃ̍X�V.
	void UpdateStopping();

	// ��]��Ԃ̍X�V.
	void UpdateRotating();

	// �ړ���Ԃ̍X�V.
	void UpdateMoving();

};

#endif		// #ifndef __ANPANAISTATENONACTIVE_H__
