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

	

	u8 Type;
	std::string Message;
	

	WordCheckPacketChatResult()
	{
	}

	WordCheckPacketChatResult(u32 InClientId, u8 InType, std::string InMessage)
	{
		ClientId = InClientId;
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

#endif		// #ifndef __WORDCHECKPACKETCHATRESULT_H__
