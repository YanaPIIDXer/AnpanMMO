#ifndef __CHARACTERBASE_H__
#define __CHARACTERBASE_H__

#include <boost/enable_shared_from_this.hpp>
#include "CharacterParameter.h"
#include "Math/Vector3D.h"
#include "Math/Rotation.h"
#include "Area/AreaBase.h"
#include "Skill/SkillControl.h"
#include "Skill/SkillRecastManager.h"

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

	// ���t���[���̏���.
	void Poll(s32 DeltaTime);

	// �p�����[�^�擾.
	const CharacterParameter &GetParameter() const { return Parameter; }

	// ���W��ݒ�.
	void SetPosition(const Vector3D &MoveTarget);

	// ��]��ݒ�.
	void SetRotate(const Rotation &TargetRotation);

	// ���W�擾.
	const Vector3D &GetPosition() const { return Position; }

	// ��]�擾.
	const Rotation &GetRotation() const { return Rot; }

	// ����ł���H
	bool IsDead() const { return (Parameter.Hp <= 0); }

	// �_���[�W
	void ApplyDamage(weak_ptr<CharacterBase> pAttacker, int Value);

	// ��.
	void Heal(int Value);

	// ���ʃx�N�g�����擾.
	Vector3D GetCenterVec() const;

	// UUID���Z�b�g�B
	void SetUuid(u32 InUuid) { Uuid = InUuid; }

	// UUID���擾.
	u32 GetUuid() const { return Uuid; }

	// �L�����N�^�^�C�v���擾.
	virtual u8 GetCharacterType() const = 0;

	// �ړ�.
	void Move(const Vector3D &MoveValue);

	// ��].
	void Rotate(float RotateValue);

	// ���X�|��
	void Respawn();

	// �G���A���Z�b�g�B
	void SetArea(const AreaPtr &pInArea) { pArea = pInArea; }

	// �G���A���擾.
	AreaPtr GetArea() const { return pArea; }

	// ���L���X�g�J�n.
	void StartRecast(u32 SkillId);

protected:

	// ���W.
	Vector3D Position;

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

	// ���t���[���̏���.
	virtual void Update(s32 DeltaTime) {}

	// �X�L���R���g���[�����擾.
	SkillControl *GetSkillControl() { return &Skill; }

	// �X�L�����L���X�g�Ǘ����擾.
	SkillRecastManager *GetSkillRecast() { return &Recast; }

private:

	// �p�����[�^
	CharacterParameter Parameter;

	// UUID
	u32 Uuid;

	// �G���A
	AreaPtr pArea;

	// �X�L������.
	SkillControl Skill;

	// �X�L�����L���X�g�Ǘ�.
	SkillRecastManager Recast;

};

#endif		// #ifndef __CHARACTERBASE_H__
