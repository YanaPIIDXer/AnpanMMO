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

	// ������,
	virtual void Initialize();

	// ID�擾.
	virtual u32 GetId() const { return Uuid; }

	// �����\���H
	virtual bool IsAbleDelete() const;

	// �C���X�^���X�G���A���H
	virtual bool IsInstance() const { return true; }

protected:

	// �X�V.
	virtual void Update();

private:

	// UUID
	u32 Uuid;

	// �C���X�^���X���}�X�^�h�c
	u32 InfoMasterId;

	// �E�o�|�C���g�����ς݂��H
	bool bSpawnedExitPoint;

	// �E�o�|�C���g�h�c
	u32 ExitWarpPointId;

	// ����������Ă��邩�H
	bool bInitialized;

};

#endif		// #ifndef __INSTANCEAREA_H__
