#ifndef __CLIENTSTATEACTIVE_H__
#define __CLIENTSTATEACTIVE_H__

#include "ClientStateBase.h"

/**
 * �Q�[����State
 */
class ClientStateActive : public ClientStateBase
{

public:

	// �R���X�g���N�^
	ClientStateActive(Client *pInParent);

	// �f�X�g���N�^
	virtual ~ClientStateActive() {}

	// �J�n���̏���.
	virtual void BeginState();

	// �p�P�b�g���.
	virtual void AnalyzePacket(PacketID ID, MemoryStreamInterface *pStream);

private:

};

#endif		// #Ifndef __CLIENTSTATEACTIVE_H__
