/**
 * @file InstanceAreaTicketManager.cpp
 * @brief �C���X�^���X�G���A�`�P�b�g�Ǘ��N���X
 * @author YanaP
 */
#ifndef __INSTANCEAREATICKETMANAGER_H__
#define __INSTANCEAREATICKETMANAGER_H__

#include <boost/unordered_map.hpp>

class InstanceAreaTicket;
class Vector3D;

/**
 * @class InstanceAreaTicketManager
 * @brief �C���X�^���X�G���A�`�P�b�g�Ǘ�
 * @details �V���O���g���N���X
 */
class InstanceAreaTicketManager : public noncopyable
{

private:		// �ʖ���`.

	typedef boost::unordered_map<u32, InstanceAreaTicket *> TicketMap;

public:

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~InstanceAreaTicketManager();

	/**
	 * @fn InstanceAreaTicket *Publish(u32 AreaId, const Vector3D &StartPosition)
	 * @brief ���s
	 * @param[in] AreaId �G���A�}�X�^�h�c
	 * @param[in] StartPosition �J�n���W
	 * @return �C���X�^���X�G���A�`�P�b�g
	 */
	InstanceAreaTicket *Publish(u32 AreaId, const Vector3D &StartPosition);

	/**
	 * @fn InstanceAreaTicket *Get(u32 Uuid)
	 * @brief �擾
	 * @param[in] Uuid �`�P�b�g�̂t�t�h�c
	 * @return �C���X�^���X�G���A�`�P�b�g
	 */
	InstanceAreaTicket *Get(u32 Uuid);

	/**
	 * @fn void Remove(u32 Uuid)
	 * @brief ����
	 * @param[in] Uuid �`�P�b�g�̂t�t�h�c
	 */
	void Remove(u32 Uuid);

private:

	// �`�P�b�g���X�g
	TicketMap TicketList;

	// ���ɔ��s����UUID
	u32 NextUuid;

	// =========== Singleton ============

public:

	static InstanceAreaTicketManager &GetInstance() { return Instance; }

private:

	InstanceAreaTicketManager();
	static InstanceAreaTicketManager Instance;

};

#endif		// #ifndef __INSTANCEAREATICKETMANAGER_H__
