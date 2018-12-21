#ifndef __WORDCHECKPACKETCHATRESULT_H__
#define __WORDCHECKPACKETCHATRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "WordCheckServerPacketID.h"


class WordCheckPacketChatResult  : public ProcessPacketBase
{
public:
	virtual u8 GetPacketID() const { return WordCheckPacketID::WordCheckChatResult; }

	

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
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Type);
		pStream->Serialize(&Message);
		
		return true;
	}
};

#endif		// #ifndef __WORDCHECKPACKETCHATRESULT_H__
