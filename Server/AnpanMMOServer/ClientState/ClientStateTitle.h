#ifndef __CLIENTSTATETITLE_H__
#define __CLIENTSTATETITLE_H__

#include "ClientStateBase.h"

/**
 * �^�C�g�����State
 */
class ClientStateTitle : public ClientStateBase
{

public:

	// �R���X�g���N�^
	ClientStateTitle(Client *pInParent);

private:

	// ���O�C�����N�G�X�g����M�����B
	void OnRecvLogInRequest(MemoryStreamInterface *pStream);

};

#endif		// #ifndef __CLIENTSTATETITLE_H__
