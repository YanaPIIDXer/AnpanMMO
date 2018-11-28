#ifndef __PACKETRECEIVECHAT_H__
#define __PACKETRECEIVECHAT_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketReceiveChat  : public PacketBase
{
public:
	virtual PacketID GetPacketID() const { return ReceiveChat; }

	

	std::string Name;
	std::string Message;
	

	PacketReceiveChat()
	{
	}

	PacketReceiveChat(std::string InName, std::string InMessage)
	{
		Name = InName;
		Message = InMessage;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Name);
		pStream->Serialize(&Message);
		
		return true;
	}
};

#endif		// #ifndef __PACKETRECEIVECHAT_H__
