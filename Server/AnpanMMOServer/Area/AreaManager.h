/**
 * @file AreaManager.cpp
 * @brief �G���A�Ǘ��N���X
 * @author YanaP
 */
#ifndef __AREAMANAGER_H__
#define __AREAMANAGER_H__

#include <boost/unordered_map.hpp>
#include "AreaBase.h"

class Client;
class MemoryStreamInterface;

/**
 * @brief �G���A�Ǘ�
 */
class AreaManager : public noncopyable
{

private:		// �ʖ���`.

	typedef shared_ptr<AreaBase> AreaSharedPtr;
	typedef unordered_map<u32, AreaSharedPtr> AreaMap;

public:

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~AreaManager() {}

	/**
	 * @fn void Initialize()
	 * @brief ������
	 */
	void Initialize();

	/**
	 * @fn AreaPtr Get(u32 ID) const
	 * @brief �擾
	 * @param[in] ID �G���A�h�c
	 * @return �G���A�ւ�weak_ptr
	 */
	AreaPtr Get(u32 ID) const;

	/**
	 * @fn void Poll(int DeltaTime)
	 * @brief ���t���[���̏���
	 * @param[in] DeltaTime �O�t���[������̌o�ߎ���
	 */
	void Poll(int DeltaTime);

	/**
	 * @fn AreaPtr CreateInstanceArea(u32 AreaId)
	 * @brief �C���X�^���X�G���A�𐶐�
	 * @param[in] AreaId �G���A�}�X�^�̂h�c
	 * @return AreaPtr �C���X�^���X�G���A�ւ�weak_ptr
	 */
	AreaPtr CreateInstanceArea(u32 AreaId);

private:

	// �G���A�}�b�v
	AreaMap Areas;

	// ���ɔ��s����C���X�^���X�}�b�v��UUID
	u32 NextInstanceAreaUuid;


	// ========== Singleton ===============

public:

	/**
	 * @fn static AreaManager &GetInstance()
	 * @brief �V���O���g���C���X�^���X���擾
	 * @return �C���X�^���X
	 */
	static AreaManager &GetInstance() { return Instance; }

private:

	AreaManager();
	static AreaManager Instance;

};

#endif		// #ifndef __AREAMANAGER_H__
