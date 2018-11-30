#ifndef __INSTANCEAREATICKET_H__
#define __INSTANCEAREATICKET_H__

#include <boost/unordered_map.hpp>
#include "WeakPtrDefine.h"

/**
 * �C���X�^���X�}�b�v�`�P�b�g
 */
class InstanceAreaTicket
{

private:		// �ʖ���`.

	typedef boost::unordered_map<u32, ClientPtr> ClientMap;

public:

	// �R���X�g���N�^
	InstanceAreaTicket();

	// �f�X�g���N�^
	~InstanceAreaTicket() {}

	// �N���C�A���g�ǉ�.
	void AddClient(ClientPtr pClient);

private:

	// �N���C�A���g���X�g
	ClientMap ClientList;

};

#endif		// #ifndef __INSTANCEAREATICKET_H__
