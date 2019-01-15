/**
 * @file BuffSpeedUp.h
 * @brief �X�s�[�h�A�b�v�o�t�N���X
 * @author YanaP
 */
#ifndef __BUFFSPEEDUP_H__
#define __BUFFSPEEDUP_H__

#include "BuffBase.h"
#include "Master/BuffMaster.h"

/**
 * @class BuffSpeedUp
 * @brief �X�s�[�h�A�b�v�o�t
 */
class BuffSpeedUp : public BuffBase
{

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] Time �p������
	 * @param[in] pInCharacter �L�����N�^
	 * @param[in] InSpeedRate �ړ����x�{��
	 */
	BuffSpeedUp(u32 Time, CharacterBase *pInCharacter, float InSpeedRate);

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~BuffSpeedUp() {}

	/**
	 * @fn virtual u8 GetType() const
	 * @brief �^�C�v���擾
	 * @return �^�C�v
	 */
	virtual u8 GetType() const { return BuffItem::SPEEDUP; }

private:

	// �ړ����x�{��.
	float SpeedRate;

};

#endif			// #ifndef __BUFFSPEEDUP_H__
