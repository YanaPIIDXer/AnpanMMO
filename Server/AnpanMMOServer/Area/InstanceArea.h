/**
 * @file InstanceArea.cpp
 * @brief �C���X�^���X�G���A�N���X
 * @author YanaP
 */
#ifndef __INSTANCEAREA_H__
#define __INSTANCEAREA_H__

#include "AreaBase.h"

struct AreaItem;

/**
 * @brief �C���X�^���X�G���A
 */
class InstanceArea : public AreaBase
{

public:

	/**
	 * @brief �R���X�g���N�^
	 */
	InstanceArea(u32 InUuid, const AreaItem *pItem);

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~InstanceArea() {}

	/**
	 * @fn virtual void Initialize()
	 * @ brief ������
	 */
	virtual void Initialize();

	/**
	 * @fn virtual u32 GetId() const
	 * @brief �h�c�擾
	 * @details �C���X�^���X�G���A�Ɋ���U��ꂽ�t�t�h�c��Ԃ��B
	 * @return ID
	 */
	virtual u32 GetId() const { return Uuid; }

	/**
	 * @fn virtual bool IsAbleDelete() const
	 * @brief �����\���H
	 * @details �v���C���[�L���������Ȃ��Ȃ���������\�ɂȂ�B
	 * @return �����\�Ȃ�true��Ԃ��B
	 */
	virtual bool IsAbleDelete() const;

	/**
	 * @fn virtual bool IsInstance() const
	 * @brief �C���X�^���X�G���A���H
	 * @return �C���X�^���X�G���A�Ȃ̂�true��Ԃ��B
	 */
	virtual bool IsInstance() const { return true; }

protected:

	/**
	 * @fn virtual void Update()
	 * @brief �X�V����
	 */
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
