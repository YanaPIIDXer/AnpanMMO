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

	// �u�߂Â����v�Ɣ��肷�鋗��.
	static const float ApproachDist;

	// ���݂̃^�[�Q�b�g
	weak_ptr<CharacterBase> pCurrentTarget;


	// ��]���X�V.
	void UpdateRotate();

	// �ړ����X�V.
	void UpdateMove();

	// �^�[�Q�b�g�̕����������B
	void RotateToTarget();

	// �^�[�Q�b�g�Ɍ������Ĉړ�����B
	void MoveToTarget();

	// �ڋ߂��Ă��邩�H
	bool IsApproached();

};


#endif		// #ifndef __ANPANAISTATEACTIVE_H__
