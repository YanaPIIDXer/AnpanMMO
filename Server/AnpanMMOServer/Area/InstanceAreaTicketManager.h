#ifndef __INSTANCEAREATICKETMANAGER_H__
#define __INSTANCEAREATICKETMANAGER_H__

#include <boost/unordered_map.hpp>

class InstanceAreaTicket;

/**
 * �C���X�^���X�G���A�`�P�b�g�}�l�[�W��
 */
class InstanceAreaTicketManager : public noncopyable
{

private:		// �ʖ���`.

	typedef boost::unordered_map<u32, InstanceAreaTicket *> TicketMap;

public:

	// �f�X�g���N�^
	virtual ~InstanceAreaTicketManager();

	// ���s.
	InstanceAreaTicket *Publish();

	// �擾.
	InstanceAreaTicket *Get(u32 Uuid);

	// ����.
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
