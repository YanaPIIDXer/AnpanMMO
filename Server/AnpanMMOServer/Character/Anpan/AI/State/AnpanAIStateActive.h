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

	// ���݂̃^�[�Q�b�g
	weak_ptr<CharacterBase> pCurrentTarget;

	// �ړ��^�C�}�[
	int MoveTimer;

};


#endif		// #ifndef __ANPANAISTATEACTIVE_H__
