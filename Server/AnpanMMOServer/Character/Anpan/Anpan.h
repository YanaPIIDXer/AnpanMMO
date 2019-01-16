/**
 * @file Anpan.h
 * @brief �A���p���N���X
 * @author YanaP
 */
#ifndef __ANPAN_H__
#define __ANPAN_H__

#include "Character/CharacterBase.h"
#include "AI/AnpanAI.h"
#include "WeakPtrDefine.h"
#include "Packet/CharacterType.h"

/**
 * @class Anpan
 * @brief �A���p���N���X
 */
class Anpan : public CharacterBase
{

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] InPosition ���W
	 * @param[in] InMasterId �}�X�^�h�c
	 */
	Anpan(const Vector3D &InPosition, u32 InMasterId);

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~Anpan() {}

	/**
	 * @fn virtual u8 GetCharacterType() const
	 * @brief �L�����N�^�^�C�v���擾
	 * @return �L�����N�^�^�C�v
	 */
	virtual u8 GetCharacterType() const { return CharacterType::Enemy; }

	/**
	 * @fn void AttackTo(CharacterPtr pTarget, u32 SkillId)
	 * @brief �U��
	 * @param[in] pTarget �U���Ώۂւ�weak_ptr
	 * @param[in] SkillId �X�L���h�c
	 */
	void AttackTo(CharacterPtr pTarget, u32 SkillId);

	/**
	 * @fn virtual int GetExp() const
	 * @brief �|�������̌o���l���擾
	 * @return �|�������̌o���l
	 */
	virtual int GetExp() const { return Exp; }
	
	/**
	 * @fn float GetRadius() const
	 * @brief ���a���擾
	 * @return ���a
	 */
	float GetRadius() const { return (BaseRadius * ScaleRate); }

	/**
	 * @fn u32 GetMasterId()
	 * @brief �}�X�^�h�c���擾
	 * @return �}�X�^�h�c
	 */
	u32 GetMasterId() const { return MasterId; }

	/**
	 * @fn virtual u32 GetDropId() const
	 * @brief �h���b�v�h�c���擾
	 * @return �h���b�v�h�c
	 */
	virtual u32 GetDropId() const { return DropId; }

	/**
	 * @fn virtual void OnBuffAdded(u32 BuffId)
	 * @brief �o�t���ǉ����ꂽ�B
	 * @param[in] BuffId �o�t�h�c
	 */
	virtual void OnBuffAdded(u32 BuffId);

protected:

	/**
	 * @fn virtual void Update(int DeltaTime)s
	 * @brief ���t���[���̏���
	 * @param[in] �O�t���[������̌o�ߎ���
	 */
	virtual void Update(int DeltaTime);

	/**
	 * @fn virtual void OnDamaged(CharacterPtr pAttacker, int DamageValue)
	 * @brief �_���[�W���󂯂�
	 * @param[in] pAttacker �_���[�W��^�����L�����ւ�weak_ptr
	 * @param[in] int DamageValue �_���[�W��
	 */
	virtual void OnDamaged(CharacterPtr pAttacker, int DamageValue);

private:

	// ���a.
	static const float BaseRadius;
	
	// AI
	AnpanAI AI;

	// �}�X�^�h�c
	u32 MasterId;

	// �|�����Ƃ��Ɋl���ł���o���l.
	int Exp;

	// �g�k�{��.
	float ScaleRate;

	// �h���b�v�h�c
	u32 DropId;

};

#endif		// #ifndef __ANPAN_H__
