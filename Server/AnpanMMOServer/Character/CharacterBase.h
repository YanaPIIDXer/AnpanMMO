#ifndef __CHARACTERBASE_H__
#define __CHARACTERBASE_H__

#include <boost/enable_shared_from_this.hpp>
#include "CharacterParameter.h"
#include "Math/Vector2D.h"
#include "Math/Rotation.h"

/**
 * �L�����N�^���N���X
 */
class CharacterBase : public enable_shared_from_this<CharacterBase>
{

public:

	// �R���X�g���N�^
	CharacterBase();

	// �f�X�g���N�^
	virtual ~CharacterBase() {}

	// �p�����[�^�擾.
	const CharacterParameter &GetParameter() const { return Parameter; }

	// ���W��ݒ�.
	void SetPosition(const Vector2D &MoveTarget);

	// ��]��ݒ�.
	void SetRotate(const Rotation &TargetRotation);

	// ���W�擾.
	const Vector2D &GetPosition() const { return Position; }

	// ��]�擾.
	const Rotation &GetRotation() const { return Rot; }

	// ����ł���H
	bool IsDead() const { return (Parameter.Hp <= 0); }

	// �_���[�W
	void ApplyDamage(weak_ptr<CharacterBase> pAttacker, int Value);

	// ���ʃx�N�g�����擾.
	Vector2D GetCenterVec() const;

	// UUID���Z�b�g�B
	void SetUuid(u32 InUuid) { Uuid = InUuid; }

	// UUID���擾.
	u32 GetUuid() const { return Uuid; }

	// �L�����N�^�^�C�v���擾.
	virtual u8 GetCharacterType() const = 0;

	// �ړ�.
	void Move(const Vector2D &MoveValue);

	// ��].
	void Rotate(float RotateValue);

	// ���X�|��
	void Respawn();

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

	// �_���[�W���󂯂��B
	virtual void OnDamaged(weak_ptr<CharacterBase> pAttacker, int DamageValue) {}

private:

	// �p�����[�^
	CharacterParameter Parameter;

	// UUID
	u32 Uuid;

};

#endif		// #ifndef __CHARACTERBASE_H__
