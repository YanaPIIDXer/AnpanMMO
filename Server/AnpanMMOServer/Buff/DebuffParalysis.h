/**
 * @file DebuffParalysis.h
 * @brief ��Ⴣf�o�t�N���X
 * @author YanaP
 */
#ifndef __DEBUFFPARALYSIS_H__
#define __DEBUFFPARALYSIS_H__

#include "BuffBase.h"
#include "Master/BuffMaster.h"

/**
 * @class DebuffParalysis
 * @brief ��Ⴣf�o�t
 */
class DebuffParalysis : public BuffBase
{

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] Time �p������
	 * @param[in] pInCharacter �L�����N�^
	 */
	DebuffParalysis(u32 Time, CharacterBase *pInCharacter);

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~DebuffParalysis() {}

	/**
	 * @fn virtual u8 GetType() const
	 * @brief �^�C�v���擾
	 * @return �^�C�v
	 */
	virtual u8 GetType() const { return BuffItem::PARALYSIS; }

};

#endif			// #ifndef __DEBUFFPARALYSIS_H__
