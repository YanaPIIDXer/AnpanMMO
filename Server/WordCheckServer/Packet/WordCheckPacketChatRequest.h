#ifndef __WORDCHECKPACKETCHATREQUEST_H__
#define __WORDCHECKPACKETCHATREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "WordCheckServerPacketID.h"


class WordCheckPacketChatRequest  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return WordCheckPacketID::WordCheckChatRequest; }

	

	u8 Type;
	std::string Message;
	

	WordCheckPacketChatRequest()
	{
	}

	WordCheckPacketChatRequest(u32 InClientId, u8 InType, std::string InMessage)
	{
		ClientId = InClientId;
		Type = InType;
		Message = InMessage;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Type);
		pStream->Serialize(&Message);
		
		return true;
	}
};

#endif		// #ifndef __WORDCHECKPACKETCHATREQUEST_H__
