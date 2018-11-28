#ifndef __WORDCHECKPACKETCHATREQUEST_H__
#define __WORDCHECKPACKETCHATREQUEST_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class WordCheckPacketChatRequest  : public ProcessPacketBase
{
public:
	virtual PacketID GetPacketID() const { return WordCheckChatRequest; }

	

	std::string Message;
	

	WordCheckPacketChatRequest()
	{
	}

	WordCheckPacketChatRequest(u32 InClientId, std::string InMessage)
	{
		ClientId = InClientId;
		Message = InMessage;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Message);
		
		return true;
	}
};

#endif		// #ifndef __WORDCHECKPACKETCHATREQUEST_H__
