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

private:

	// �L�����N�^���[�h
	void LoadCharacter();

	// �Q�[��������������M.
	void OnRecvGameReady(MemoryStreamInterface *pStream);

};

#endif		// #Ifndef __CLIENTSTATEACTIVE_H__
