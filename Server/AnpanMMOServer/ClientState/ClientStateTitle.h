#ifndef __CLIENTSTATETITLE_H__
#define __CLIENTSTATETITLE_H__

#include "ClientStateBase.h"

class ClientStateTitle : public ClientStateBase
{

public:

	// �R���X�g���N�^
	ClientStateTitle(Client *pInParent);

	// �p�P�b�g���.
	virtual void AnalyzePacket(MemoryStreamInterface *pStream);

private:

};

#endif		// #ifndef __CLIENTSTATETITLE_H__
