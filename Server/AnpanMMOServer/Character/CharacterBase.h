/**
 * @file CharacterBase.h
 * @brief �L�����N�^���N���X
 * @author YanaP
 */
#ifndef __CHARACTERBASE_H__
#define __CHARACTERBASE_H__

#include <boost/enable_shared_from_this.hpp>
#include "CharacterParameter.h"
#include "Math/Vector3D.h"
#include "Math/Rotation.h"
#include "Area/AreaBase.h"
#include "Skill/SkillControl.h"
#include "Skill/SkillRecastManager.h"
#include "Buff/BuffManager.h"

struct SkillItem;

/**
 * @class CharacterBase
 * @brief �L�����N�^���N���X
 */
class CharacterBase : public enable_shared_from_this<CharacterBase>
{

public:

	/**
	 * @brief �R���X�g���N�^
	 */
	CharacterBase();

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~CharacterBase() {}

	/**
	 * @fn void Poll(s32 DeltaTime)
	 * @brief ���t���[���̏���
	 * @param[in] DeltaTime �O�t���[������̌o�ߎ���
	 */
	void Poll(s32 DeltaTime);

	/**
	 * @fn const CharacterParameter &GetParameter() const
	 * @brief �p�����[�^�擾
	 * @return �p�����[�^
	 */
	const CharacterParameter &GetParameter() const { return Parameter; }

	/**
	 * @fn void SetPosition(const Vector3D &MoveTarget)
	 * @brief ���W��ݒ�
	 * @param[in] MoveTarget �ړ�����W
	 */
	void SetPosition(const Vector3D &MoveTarget);

	/**
	 * @fn void SetRotate(const Rotation &TargetRotation)
	 * @brief ��]��ݒ�
	 * @param[in] TargetRotation ��]
	 */
	void SetRotate(const Rotation &TargetRotation);

	/**
	 * @fn const Vector3D &GetPosition() const
	 * @brief ���W���擾
	 * @return ���W
	 */
	const Vector3D &GetPosition() const { return Position; }

	/**
	 * @fn const Rotation &GetRotation() const
	 * @brief ��]���擾
	 * @return ��]
	 */
	const Rotation &GetRotation() const { return Rot; }

	/**
	 * @fn bool IsDead() const
	 * @brief ����ł���H
	 * @return ����ł���Ȃ�true
	 */
	bool IsDead() const { return (Parameter.GetHp() <= 0); }

	/**
	 * @fn void ApplyDamage(CharacterPtr pAttacker, u32 Value)
	 * @brief �_���[�W��^����
	 * @param[in] Value �_���[�W��
	 */
	void ApplyDamage(u32 Value);

	/**
	 * @fn void Heal(u32 Value)
	 * @brief ��
	 * @param[in] Value �񕜗�
	 */
	void Heal(u32 Value);

	/**
	 * @fn Vector3D GetCenterVec() const
	 * @brief ���ʃx�N�g�����擾
	 * @return ���ʃx�N�g��
	 */
	Vector3D GetCenterVec() const;

	/**
	 * @fn void SetUuid(u32 InUuid)
	 * @brief UUID���Z�b�g
	 * @param[in] InUuid UUID
	 */
	void SetUuid(u32 InUuid) { Uuid = InUuid; }

	/**
	 * @fn u32 GetUuid() const
	 * @brief UUID���擾
	 * @return UUID
	 */
	u32 GetUuid() const { return Uuid; }

	/**
	 * @fn u32 GetLevel() const
	 * @brief ���x�����擾
	 * @return ���x��
	 */
	u32 GetLevel() const { return Parameter.GetLevel(); }

	/**
	 * @fn virtual u8 GetCharacterType() const
	 * @brief �L�����N�^�^�C�v���擾
	 * @return �L�����N�^�^�C�v
	 */
	virtual u8 GetCharacterType() const = 0;

	/**
	 * @fn void Move(const vector3D &MoveValue)
	 * @brief �ړ�
	 * @param[in] MoveValue �ړ���
	 */
	void Move(const Vector3D &MoveValue);

	/**
	 * @fn void Rotate(float RotateValue)
	 * @brief ��]
	 * @param[in] RotateValue ��]��
	 */
	void Rotate(float RotateValue);

	/**
	 * @fn void Respawn()
	 * @brief ���X�|��
	 */
	void Respawn();

	/**
	 * @fn void SetArea(const AreaPtr &pInArea)
	 * @brief �G���A��ݒ�
	 * @param[in] pInArea �G���A�ւ�weak_ptr
	 */
	void SetArea(const AreaPtr &pInArea) { pArea = pInArea; }

	/**
	 * @fn AreaPtr GetArea() const
	 * @brief �G���A���擾
	 * @return �G���A�ւ�waek_ptr
	 */
	AreaPtr GetArea() const { return pArea; }

	/**
	 * @fn void UseSkill(u32 SkillId, CharacterPtr pTarget)
	 * @brief �X�L���g�p
	 * @param[in] SkillId �X�L���h�c
	 * @param[in] pTarget �^�[�Q�b�g�L�����ւ�weak_ptr
	 */
	void UseSkill(u32 SkillId, CharacterPtr pTarget);

	/**
	 * @fn void StartRecast(u32 SkillId)
	 * @brief ���L���X�g�J�n
	 * @param[in] SkillId �X�L���h�c
	 */
	void StartRecast(u32 SkillId);

	/**
	 * @fn bool IsSkillActive() const
	 * @brief �X�L���g�p�����H
	 * @return �X�L���g�p���Ȃ�true��Ԃ�
	 */
	bool IsSkillActive() const { return Skill.IsActive(); }

	/**
	 * @fn bool IsSkillCasting() const
	 * @brief �X�L���L���X�g�����H
	 * @return �L���X�g���Ȃ�true��Ԃ��B
	 */
	bool IsSkillCasting() const { return Skill.IsCasting(); }

	/**
	 * @fn bool IsRecasting(u32 SkillId) const
	 * @brief ���L���X�g�����H
	 * @param[in] SkillId �X�L���h�c
	 * @return ���L���X�g���Ȃ�true��Ԃ�
	 */
	bool IsRecasting(u32 SkillId) const { return Recast.IsRecast(SkillId); }

	/**
	 * @fn virtual int GetExp() const
	 * @brief �|�������̌o���l�擾
	 * @return �|�������̌o���l
	 */
	virtual int GetExp() const { return 0; }

	/**
	 * @fn virtual u32 GetDropId() const
	 * @brief �h���b�v�h�c���擾
	 * @return �h���b�v�h�c
	 */
	virtual u32 GetDropId() const { return 0; }

	/**
	 * @fn bool IsEquiped(u32 EquipId) const
	 * @brief �������Ă��邩�H
	 * @return �������Ă����true��Ԃ��B
	 */
	bool IsEquiped(u32 EquipId) const;

	/**
	 * @fn void AddBuff(u32 BuffId)
	 * @brief �o�t�ǉ�
	 * @param[in] BuffId �o�t�h�c
	 */
	void AddBuff(u32 BuffId);

	/**
	 * @fn virtual void OnBuffAdded(u32 BuffId)
	 * @brief �o�t���ǉ����ꂽ�B
	 * @param[in] BuffId �o�t�h�c
	 */
	virtual void OnBuffAdded(u32 BuffId) {}

	/**
	 * @fn virtual void OnBuffRemoved(u8 BuffType)
	 * @brief �o�t�����ł����B
	 * @param[in] BuffType
	 */
	virtual void OnBuffRemoved(u8 BuffType) {}

	/**
	 * @fn bool IsParalysis() const
	 * @brief ��჏�Ԃ��H
	 * @return ��჏�ԂȂ�true��Ԃ��B
	 */
	bool IsParalysis() const;

	/**
	 * @fn virtual void OnSkillReceived(CharacterPtr pCharacter, const SkillItem *pSkill)
	 * @brief �X�L����H������B
	 * @param[in] pCharacter �X�L���g�p��
	 * @param[in] pSkill �H������X�L��
	 */
	virtual void OnSkillReceived(CharacterPtr pCharacter, const SkillItem *pSkill) {}

protected:

	//! ���W.
	Vector3D Position;

	//! ��].
	Rotation Rot;

	//! �X�L������.
	SkillControl Skill;

	//! �X�L�����L���X�g�Ǘ�.
	SkillRecastManager Recast;


	/**
	 * @fn void SetParameter(u32 Level, u32 Hp, u32 MaxHp, u32 Str, u32 Def, u32 Int, u32 Mnd, u32 Vit)
	 * @brief �p�����[�^��ݒ�
	 * @param[in] Level ���x��
	 * @param[in] Hp �g�o
	 * @param[in] MaxHp �ő�g�o
	 * @param[in] Str STR
	 * @param[in] Def DEF
	 * @param[in] Int INT
	 * @param[in] Mnd MND
	 * @param[in] Vit VIT
	 * @param[in] bIsVitAffectMaxHp VIT���ő�g�o�ɉe�����邩�H
	 */
	void SetParameter(u32 Level, u32 Hp, u32 MaxHp, u32 Str, u32 Def, u32 Int, u32 Mnd, u32 Vit, bool bIsVitAffectMaxHp)
	{
		Parameter.Set(Level, Hp, MaxHp, Str, Def, Int, Mnd, Vit, bIsVitAffectMaxHp);
	}

	/**
	 * @fn virtual void Update(s32 DeltaTime)
	 * @brief ���t���[���̏���
	 * @param[in] DeltaTime �O�t���[������̌o�ߎ���
	 */
	virtual void Update(s32 DeltaTime) {}

	/**
	 * @fn void ChangeEquipData(u32 RightEquipId, u32 LeftEquipId)
	 * @brief �����؂�ւ�
	 * @param[in] RightEquipId �E�葕���h�c
	 * @param[in] LeftEquipId ���葕���h�c
	 */
	void ChangeEquipData(u32 RightEquipId, u32 LeftEquipId);

private:

	// �p�����[�^
	CharacterParameter Parameter;

	// UUID
	u32 Uuid;

	// �G���A
	AreaPtr pArea;

	// �o�t�Ǘ�.
	BuffManager BuffMgr;
};

#endif		// #ifndef __CHARACTERBASE_H__
