#ifndef __ANPAN_H__
#define __ANPAN_H__

#include "Character/CharacterBase.h"
#include "Character/Anpan/AI/AnpanAI.h"

/**
 * �A���p���N���X
 */
class Anpan : public CharacterBase
{

public:

	// �R���X�g���N�^
	Anpan(const Vector2D &InPosition, int Hp, int Atk, int Def);

	// �f�X�g���N�^
	virtual ~Anpan() {}

private:

	// AI
	AnpanAI AI;

};

#endif		// #ifndef __ANPAN_H__
