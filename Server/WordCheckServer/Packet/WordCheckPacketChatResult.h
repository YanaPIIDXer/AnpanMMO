#ifndef __WORDCHECKPACKETCHATRESULT_H__
#define __WORDCHECKPACKETCHATRESULT_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"


class WordCheckPacketChatResult  : public ProcessPacketBase
{
public:
	virtual PacketID GetPacketID() const { return WordCheckChatResult; }

	

	std::string Message;
	

	WordCheckPacketChatResult()
	{
	}

	WordCheckPacketChatResult(u32 InClientId, std::string InMessage)
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

#endif		// #ifndef __WORDCHECKPACKETCHATRESULT_H__
