#ifndef __PACKETSENDCHAT_H__
#define __PACKETSENDCHAT_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketSendChat  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return SendChat; }

	

	std::string Message;
	

	PacketSendChat()
	{
	}

	PacketSendChat(std::string InMessage)
	{
		Message = InMessage;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Message);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSENDCHAT_H__
