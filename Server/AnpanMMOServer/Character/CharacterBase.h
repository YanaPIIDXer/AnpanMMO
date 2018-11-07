#ifndef __CHARACTERBASE_H__
#define __CHARACTERBASE_H__

#include "CharacterParameter.h"
#include "Math/Vector2D.h"
#include "Math/Rotation.h"

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

	// �ړ�.
	void Move(float X, float Y, float Rotation);

	// ���W�擾.
	const Vector2D &GetPosition() const { return Position; }

	// ��]�擾.
	const Rotation &GetRotation() const { return Rot; }

	// ����ł���H
	bool IsDead() const { return (Parameter.Hp <= 0); }

	// �_���[�W
	void ApplyDamage(int Value);

protected:

	// ���W.
	Vector2D Position;

	// ��].
	Rotation Rot;


	// �p�����[�^�ݒ�.
	void SetParameter(int Hp, int MaxHp, int Atk, int Def)
	{
		Parameter.Hp = Hp;
		Parameter.MaxHp = MaxHp;
		Parameter.Atk = Atk;
		Parameter.Def = Def;
	}

	// �p�����[�^�ǉ�.
	void AddParameter(int MaxHp, int Atk, int Def)
	{
		Parameter.MaxHp += MaxHp;
		Parameter.Atk += Atk;
		Parameter.Def += Def;
	}

	// ���W�ݒ�.
	void SetPosition(const Vector2D &InPosition) { Position = InPosition; }

	// ��]��ݒ�.
	void SetRotation(float Value) { Rot.Set(Value); }

private:

	// �p�����[�^
	CharacterParameter Parameter;

};

#endif		// #ifndef __CHARACTERBASE_H__
