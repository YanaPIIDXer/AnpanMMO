#ifndef __INSTANCEAREATICKET_H__
#define __INSTANCEAREATICKET_H__

#include <boost/unordered_map.hpp>
#include "WeakPtrDefine.h"
#include "Math/Vector3D.h"

// �`�P�b�g�X�e�[�g
enum ETicketState
{
	// �����҂�
	TicketStateWait,

	// �i��.
	TicketStateEnter,

	// �j��.
	TicketStateDiscard,
};

// �`�P�b�g���.
struct InstanceAreaTicketInfo
{

public:

	// �N���C�A���g
	ClientPtr pClient;

	// �X�e�[�g
	ETicketState State;

};

/**
 * �C���X�^���X�}�b�v�`�P�b�g
 */
class InstanceAreaTicket
{

private:		// �ʖ���`.

	typedef boost::unordered_map<u32, InstanceAreaTicketInfo> InfoMap;

public:

	// �R���X�g���N�^
	InstanceAreaTicket(u32 InUuid, u32 InAreaId, const Vector3D &InStartPosition);

	// �f�X�g���N�^
	~InstanceAreaTicket() {}

	// �N���C�A���g�ǉ�.
	void AddClient(ClientPtr pClient);

	// ��������M�����B
	void RecvProcess(u32 Uuid, ETicketState Process);

	// �������������Ă��邩�H
	bool IsReady() const;

	// �j������Ă��邩�H
	bool IsDiscard() const;

	// �ҋ@�����H
	bool IsWaiting() const;

	// �G���A�h�c���擾.
	u32 GetAreaId() const { return AreaId; }

	// ���s�p�P�b�g���o���T���B
	void BroadcastPublishPacket();

	// �j���p�P�b�g���o���T���B
	void BroadcastDiscardPacket();

	// �C���X�^���X�G���A�ɓ˂����ށB
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
