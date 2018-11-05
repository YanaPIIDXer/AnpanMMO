#ifndef __PLAYERCHARACTER_H__
#define __PLAYERCHARACTER_H__

#include "CharacterBase.h"
#include "PlayerExp.h"

class PlayerCharacter;
typedef weak_ptr<PlayerCharacter> PlayerCharacterPtr;
class Client;

/**
 * �v���C���[�L�����N�^
 */
class PlayerCharacter : public CharacterBase
{

public:

	// �R���X�g���N�^
	PlayerCharacter(Client *pInClient, int MaxHp, int Atk, int Def, int InExp);

	// �f�X�g���N�^
	virtual ~PlayerCharacter() {}

	// �N���C�A���g�擾.
	Client *GetClient() const { return pClient; }

private:

	// �N���C�A���g
	Client *pClient;

	// �o���l.
	PlayerExp Exp;


	// ���x���A�b�v�R�[���o�b�N
	void OnLevelUp();

};

#endif		// #ifndef __PLAYERCHARACTER_H__
