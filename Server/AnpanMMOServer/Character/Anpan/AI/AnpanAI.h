#ifndef __ANPANAI_H__
#define __ANPANAI_H__

class Anpan;
class AnpanAIStateBase;

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

private:

	// �e.
	Anpan *pParent;

	// �X�e�[�g
	AnpanAIStateBase *pState;

};

#endif		// #ifndef __ANPANAI_H__
