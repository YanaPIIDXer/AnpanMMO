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

	// ���t���[���̏���.
	virtual void Poll(int DeltaTime);

private:

};

#endif		// #ifndef __ANPANAISTATENONACTIVE_H__
