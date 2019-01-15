/**
 * @file DebuffPoison.h
 * @brief �Ńf�o�t�N���X
 * @author YanaP
 */
#ifndef __DEBUFFPOISON_H__
#define __DEBUFFPOISON_H__

#include "BuffBase.h"
#include "Master/BuffMaster.h"

/**
 * @class DebuffPoison
 * @brief �Ńf�o�t
 */
class DebuffPoison : public BuffBase
{

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] Time �p������
	 * @param[in] pInCharacter �L�����N�^
	 * @param[in] InDamageRate �_���[�W���[�g
	 */
	DebuffPoison(u32 Time, CharacterBase *pInCharacter, float InDamageRate);

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~DebuffPoison() {}

	/**
	 * @fn virtual u8 GetType() const
	 * @brief �^�C�v���擾
	 * @return �^�C�v
	 */
	virtual u8 GetType() const { return BuffItem::POISON; }

protected:

	/**
	 * @fn virtual void Update(u32 DeltaTime)
	 * @brief ���t���[���̏���
	 * @param[in] DeltaTime �O�t���[������̌o�ߎ���
	 */
	virtual void Update(u32 DeltaTime);

private:

	// �_���[�W�C���^�[�o��
	static const u32 DamageInterval;

	// �_���[�W���[�g
	float DamageRate;

	// �_���[�W�^�C�}�[
	s32 DamageTimer;

};

#endif		// #ifndef __DEBUFFPOISON_H__
