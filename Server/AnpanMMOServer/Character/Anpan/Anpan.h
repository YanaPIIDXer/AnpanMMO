#ifndef __ANPAN_H__
#define __ANPAN_H__

#include "Character/CharacterBase.h"

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

};

#endif		// #ifndef __ANPAN_H__