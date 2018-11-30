#ifndef __INSTANCEAREATICKET_H__
#define __INSTANCEAREATICKET_H__

#include <boost/unordered_map.hpp>
#include "WeakPtrDefine.h"

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
	InstanceAreaTicket();

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

private:

	// ��񃊃X�g
	InfoMap InfoList;

};

#endif		// #ifndef __INSTANCEAREATICKET_H__
