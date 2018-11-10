#ifndef __ANPANAISTATENONACTIVE_H__
#define __ANPANAISTATENONACTIVE_H__

#include "AnpanAIStateBase.h"

/**
 * �A���p���`�h�X�e�[�g�F�m���A�N�e�B�u���.
 */
class AnpanAIStateNonActive : public AnpanAIStateBase
{

public:
	
	// �R���X�g���N�^
	AnpanAIStateNonActive(Anpan *pInParent);

	// �f�X�g���N�^
	virtual ~AnpanAIStateNonActive() {}

	// �_���[�W���󂯂��B
	virtual void OnDamaged();

protected:

	// �X�V����.
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
