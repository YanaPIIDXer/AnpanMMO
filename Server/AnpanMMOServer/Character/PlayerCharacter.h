#ifndef __PLAYERCHARACTER_H__
#define __PLAYERCHARACTER_H__

#include "CharacterBase.h"

class PlayerCharacter;
typedef weak_ptr<PlayerCharacter> PlayerCharacterPtr;

/**
 * �v���C���[�L�����N�^
 */
class PlayerCharacter : public CharacterBase
{

public:

	// �R���X�g���N�^
	PlayerCharacter(int MaxHp, int Atk, int Def);

	// �f�X�g���N�^
	virtual ~PlayerCharacter() {}

private:

};

#endif		// #ifndef __PLAYERCHARACTER_H__
