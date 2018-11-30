#ifndef __INSTANCEAREA_H__
#define __INSTANCEAREA_H__

#include "AreaBase.h"

struct AreaItem;

/**
 * �C���X�^���X�G���A
 */
class InstanceArea : public AreaBase
{

public:

	// �R���X�g���N�^
	InstanceArea(u32 InUuid, const AreaItem *pItem);

	// �f�X�g���N�^
	virtual ~InstanceArea() {}

	// ID�擾.
	virtual u32 GetId() const { return Uuid; }

	// �����\���H
	virtual bool IsAbleDelete() const;

	// �C���X�^���X�G���A���H
	virtual bool IsInstance() const { return true; }

private:

	// UUID
	u32 Uuid;

};

#endif		// #ifndef __INSTANCEAREA_H__
