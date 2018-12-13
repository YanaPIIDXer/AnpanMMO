#ifndef __PACKETSENDCHAT_H__
#define __PACKETSENDCHAT_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketSendChat  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return SendChat; }

	enum ChatType
	{
		Say,
		Shout,
	};

	u8 Type;
	std::string Message;
	

	PacketSendChat()
	{
	}

	PacketSendChat(u8 InType, std::string InMessage)
	{
		Type = InType;
		Message = InMessage;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Type);
		pStream->Serialize(&Message);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSENDCHAT_H__
