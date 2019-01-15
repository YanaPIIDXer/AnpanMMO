/**
 * @file BuffAutoHeal.h
 * @brief �����񕜃o�t�N���X
 * @author YanaP
 */
#ifndef __BUFFAUTOHEAL_H__
#define __BUFFAUTOHEAL_H__

#include "BuffBase.h"
#include "Master/BuffMaster.h"

/**
 * @class BuffAutoHeal
 * @brief �����񕜃o�t
 */
class BuffAutoHeal : public BuffBase
{

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] Time �p������
	 * @param[in] pInCharacter �L�����N�^
	 * @param[in] InHealRate �񕜃��[�g
	 */
	BuffAutoHeal(u32 Time, CharacterBase *pInCharacter, float InHealRate);

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~BuffAutoHeal() {}

	/**
	 * @fn virtual u8 GetType() const
	 * @brief �^�C�v���擾
	 * @return �^�C�v
	 */
	virtual u8 GetType() const { return BuffItem::AUTO_HEAL; }

protected:

	/**
	 * @fn virtual void Update(u8 DeltaTime)
	 * @brief ���t���[���̏���
	 * @param[in] DeltaTime �O�t���[������̌o�ߎ���
	 */
	virtual void Update(u32 DeltaTime);

private:

	// �񕜃C���^�[�o��
	static const u32 HealInterval;

	// �񕜃��[�g
	float HealRate;

	// �񕜃^�C�}�[
	s32 HealTimer;

};

#endif		// #ifndef __BUFFAUTOHEAL_H__
