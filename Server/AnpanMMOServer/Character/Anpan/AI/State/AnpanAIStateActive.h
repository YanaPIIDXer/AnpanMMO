#ifndef __ANPANAISTATEACTIVE_H__
#define __ANPANAISTATEACTIVE_H__

#include "AnpanAIStateBase.h"

class CharacterBase;

/**
 * �A���p���`�h�X�e�[�g�F�A�N�e�B�u���.
 */
class AnpanAIStateActive : public AnpanAIStateBase
{
	
public:

	// �R���X�g���N�^
	AnpanAIStateActive(Anpan *pInParent);

	// �f�X�g���N�^
	virtual ~AnpanAIStateActive() {}

protected:

	// �X�V.
	virtual void Update(int DeltaTime);

private:

	// ����State
	enum EState
	{
		// ��]��.
		Rotating,

		// �ړ���.
		Moving,
	};

	// ���݂̃^�[�Q�b�g
	weak_ptr<CharacterBase> pCurrentTarget;

	// �s���^�C�}�[
	int ActionTimer;

	// ����State
	EState CurrentState;
	
	// �^�[�Q�b�g�̈ȑO�̍��W.
	Vector2D PrevTargetPos;

	// ��]���X�V.
	void UpdateRotate();

	// �ړ����X�V.
	void UpdateMove();

};


#endif		// #ifndef __ANPANAISTATEACTIVE_H__
