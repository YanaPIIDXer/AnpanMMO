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
	void ApplyDamage(CharacterPtr pAttacker, int Value);

	// ��.
	void Heal(int Value);

	// ���ʃx�N�g�����擾.
	Vector3D GetCenterVec() const;

	// UUID���Z�b�g�B
	void SetUuid(u32 InUuid) { Uuid = InUuid; }

	// UUID���擾.
	u32 GetUuid() const { return Uuid; }

	// ���x�����擾.
	u32 GetLevel() const { return Parameter.Level; }

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

	// �X�L���g�p.
	void UseSkill(u32 SkillId, CharacterPtr pTarget);

	// ���L���X�g�J�n.
	void StartRecast(u32 SkillId);

	// �X�L���g�p�����H
	bool IsSkillActive() const { return Skill.IsActive(); }

	// �X�L���L���X�g�����H
	bool IsSkillCasting() const { return Skill.IsCasting(); }

	// ���L���X�g�����H
	bool IsRecasting(u32 SkillId) const { return Recast.IsRecast(SkillId); }

	// �|�������̌o���l�擾.
	virtual int GetExp() const { return 0; }

	// �h���b�v�h�c�擾.
	virtual u32 GetDropId() const { return 0; }

protected:

	// ���W.
	Vector3D Position;

	// ��].
	Rotation Rot;

	// �X�L������.
	SkillControl Skill;

	// �X�L�����L���X�g�Ǘ�.
	SkillRecastManager Recast;


	// �p�����[�^�ݒ�.
	void SetParameter(u32 Level, int Hp, int MaxHp, int Atk, int Def)
	{
		Parameter.Level = Level;
		Parameter.Hp = Hp;
		Parameter.MaxHp = MaxHp;
		Parameter.Atk = Atk;
		Parameter.Def = Def;
	}

	// ���x���A�b�v
	void LevelUp(int MaxHp, int Atk, int Def)
	{
		Parameter.Level++;
		Parameter.MaxHp += MaxHp;
		Parameter.Atk += Atk;
		Parameter.Def += Def;
	}

	// �_���[�W���󂯂��B
	virtual void OnDamaged(weak_ptr<CharacterBase> pAttacker, int DamageValue) {}

	// ���t���[���̏���.
	virtual void Update(s32 DeltaTime) {}

private:

	// �p�����[�^
	CharacterParameter Parameter;

	// UUID
	u32 Uuid;

	// �G���A
	AreaPtr pArea;

};

#endif		// #ifndef __CHARACTERBASE_H__
