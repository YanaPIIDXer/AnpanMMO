#ifndef __AREA_H__
#define __AREA_H__

#include "AreaBase.h"

struct AreaItem;

/**
 * �G���A�N���X
 */
class Area : public AreaBase
{

public:

	// �R���X�g���N�^
	Area(const AreaItem *pItem);

	// �f�X�g���N�^
	virtual ~Area() {}

	// ID�擾.
	virtual u32 GetId() const { return Id; }

	// �����\���H
	virtual bool IsAbleDelete() const { return false; }

private:

	// ID
	u32 Id;

};

#endif		// #ifndef __AREA_H__
