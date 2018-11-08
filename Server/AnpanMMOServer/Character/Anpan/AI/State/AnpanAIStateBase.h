#ifndef __ANPANAISTATEBASE_H__
#define __ANPANAISTATEBASE_H__

class Anpan;

/**
 * �A���p���`�h�X�e�[�g���N���X
 */
class AnpanAIStateBase
{

public:

	// �R���X�g���N�^
	AnpanAIStateBase(Anpan *pInParent);

	// �f�X�g���N�^
	virtual ~AnpanAIStateBase() = 0;

	// ���t���[���̏���.
	virtual void Poll(int DeltaTime) {}

protected:

	// �e���擾.
	Anpan *GetParent() { return pParent; }

private:

	// �e.
	Anpan *pParent;

};

#endif		// #ifndef __ANPANAISTATEBASE_H__
