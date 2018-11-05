#ifndef __CHARACTERBASE_H__
#define __CHARACTERBASE_H__

#include "CharacterParameter.h"
#include "Math/Vector2D.h"

/**
 * �L�����N�^���N���X
 */
class CharacterBase
{

public:

	// �R���X�g���N�^
	CharacterBase();

	// �f�X�g���N�^
	virtual ~CharacterBase() {}

	// �p�����[�^�擾.
	const CharacterParameter &GetParameter() const { return Parameter; }

	// ���W�擾.
	const Vector2D &GetPosition() const { return Position; }

	// ����ł���H
	bool IsDead() const { return (Parameter.Hp <= 0); }

protected:

	// �p�����[�^�ݒ�.
	void SetParameter(int Hp, int MaxHp, int Atk, int Def)
	{
		Parameter.Hp = Hp;
		Parameter.MaxHp = MaxHp;
		Parameter.Atk = Atk;
		Parameter.Def = Def;
	}

	// ���W�ݒ�.
	void SetPosition(const Vector2D &InPosition) { Position = InPosition; }

private:

	// �p�����[�^
	CharacterParameter Parameter;

	// ���W.
	Vector2D Position;

};

#endif		// #ifndef __CHARACTERBASE_H__
