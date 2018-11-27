#ifndef __PLAYERCHARACTER_H__
#define __PLAYERCHARACTER_H__

#include "Character/CharacterBase.h"
#include "PlayerExp.h"
#include "Packet/CharacterType.h"

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
	virtual ~PlayerCharacter();

	// �N���C�A���g�擾.
	Client *GetClient() const { return pClient; }

	// �o���l�ǉ�.
	void AddExp(int Value) { Exp.Add(Value); }

	// �o���l�擾.
	int GetExp() const { return Exp.Get(); }

	// ���O��ݒ�.
	void SetName(const std::string &InName) { Name = InName; }

	// ���O���擾.
	const std::string &GetName() const { return Name; }

	// �L�����N�^�^�C�v���擾.
	virtual u8 GetCharacterType() const { return CharacterType::Player; }

private:

	// �N���C�A���g
	Client *pClient;

	// �o���l.
	PlayerExp Exp;

	// ���O.
	std::string Name;


	// ���x���A�b�v�R�[���o�b�N
	void OnLevelUp();

	// �p�����[�^��ۑ�.
	void SaveParameter();

};

#endif		// #ifndef __PLAYERCHARACTER_H__
