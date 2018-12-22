/**
 * @file Area.h
 * @brief �G���A�N���X
 * @author YanaP
 */
#ifndef __AREA_H__
#define __AREA_H__

#include "AreaBase.h"

struct AreaItem;

/**
 * @class Area
 * @brief �G���A�N���X
 */
class Area : public AreaBase
{

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] pItem �G���A�}�X�^�A�C�e��
	 */
	Area(const AreaItem *pItem);

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~Area() {}

	/**
	 * @fn virtual u32 GetId() const
	 * @brief ID�擾.
	 * @return ID
	 * @details �G���A�}�X�^�̂h�c�Ɠ���B
	 */
	virtual u32 GetId() const { return Id; }

	/**
	 * @fn virtual bool IsAbleDelete() const
	 * @brief �����\���H
	 * @return �������Ă͂����Ȃ��̂ŏ��false��Ԃ��B
	 */
	virtual bool IsAbleDelete() const { return false; }

private:

	// ID
	u32 Id;

};

#endif		// #ifndef __AREA_H__
