#ifndef __ANPANAI_H__
#define __ANPANAI_H__

class Anpan;

/**
 * �A���p���`�h�N���X
 */
class AnpanAI
{

public:

	// �R���X�g���N�^
	AnpanAI(Anpan *pInParent);

	// �f�X�g���N�^
	~AnpanAI() {}

private:

	// �e.
	Anpan *pParent;

};

#endif		// #ifndef __ANPANAI_H__
