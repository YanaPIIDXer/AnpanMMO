/**
 * @file InstanceAreaTicket.cpp
 * @brief �C���X�^���X�G���A�`�P�b�g�N���X
 * @author YanaP
 */
#ifndef __INSTANCEAREATICKET_H__
#define __INSTANCEAREATICKET_H__

#include <boost/unordered_map.hpp>
#include "WeakPtrDefine.h"
#include "Math/Vector3D.h"

/**
 * @enum ETicketState
 * @brief �`�P�b�g�X�e�[�g
 */
enum ETicketState
{
	//! �����҂�
	TicketStateWait,

	//! �i��.
	TicketStateEnter,

	//! �j��.
	TicketStateDiscard,
};

/**
 * @struct InstanceAreaTicketInfo
 * @brief �`�P�b�g���
 */
struct InstanceAreaTicketInfo
{

public:

	//! �N���C�A���g
	ClientPtr pClient;

	//! �X�e�[�g
	ETicketState State;

};

/**
 * @class InstanceAreaTicket
 * @brief �C���X�^���X�}�b�v�`�P�b�g
 */
class InstanceAreaTicket
{

private:		// �ʖ���`.

	typedef boost::unordered_map<u32, InstanceAreaTicketInfo> InfoMap;

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] InUuid �t�t�h�c
	 * @param[in] InAreaId �G���A�}�X�^�h�c
	 * @param[in] InStartPosition �J�n���W
	 */
	InstanceAreaTicket(u32 InUuid, u32 InAreaId, const Vector3D &InStartPosition);

	/**
	 * @brief �f�X�g���N�^
	 */
	~InstanceAreaTicket() {}

	/**
	 * @fn void AddClient(ClientPtr pClient)
	 * @brief �N���C�A���g�ǉ�
	 * @param[in] pClient �N���C�A���g�ւ�weak_ptr
	 */
	void AddClient(ClientPtr pClient);

	/**
	 * @fn void RecvProcess(u32 Uuid, ETicketState Process)
	 * @brief ��������M����
	 * @param[in] Uuid �N���C�A���g�t�t�h�c
	 * @param[in] Process �������e
	 */
	void RecvProcess(u32 Uuid, ETicketState Process);

	/**
	 * @fn bool IsReady() const
	 * @brief �������������Ă��邩�H
	 * @return �������������Ă���Ȃ�true��Ԃ��B
	 */
	bool IsReady() const;

	/**
	 * @fn bool IsDiscard() const
	 * @brief �j������Ă��邩�H
	 * @return �j������Ă���Ȃ�true��Ԃ��B
	 */
	bool IsDiscard() const;

	/**
	 * @fn bool IsWaiting() const
	 * @brief �ҋ@�����H
	 * @return �ҋ@���Ȃ�true��Ԃ��B
	 */
	bool IsWaiting() const;

	/**
	 * @fn u32 GetAreaId() const
	 * @brief �G���A�h�c���擾
	 * @return �G���A�h�c
	 */
	u32 GetAreaId() const { return AreaId; }

	/**
	 * @fn void BroadcastPublishPacket()
	 * @brief ���s�`�P�b�g���o���T��
	 */
	void BroadcastPublishPacket();

	/**
	 * @fn void BroadcastDiscardPacket()
	 * @brief �j���`�P�b�g���o���T��
	 */
	void BroadcastDiscardPacket();

	/**
	 * @fn void EnterToInstanceArea(AreaPtr pArea)
	 * @brief �C���X�^���X�G���A�ɓ˂�����
	 * @param[in] pArea �C���X�^���X�G���A�ւ�weak_ptr
	 */
	void EnterToInstanceArea(AreaPtr pArea);

private:

	// UUID
	u32 Uuid;

	// �G���A�h�c
	u32 AreaId;

	// �J�n���W.
	Vector3D StartPosition;

	// ��񃊃X�g
	InfoMap InfoList;

};

#endif		// #ifndef __INSTANCEAREATICKET_H__
