#ifndef __CLIENTSTATETITLE_H__
#define __CLIENTSTATETITLE_H__

#include "ClientStateBase.h"

class ClientStateTitle : public ClientStateBase
{

public:

	// コンストラクタ
	ClientStateTitle(Client *pInParent);

	// パケット解析.
	virtual void AnalyzePacket(MemoryStreamInterface *pStream);

private:

};

#endif		// #ifndef __CLIENTSTATETITLE_H__
