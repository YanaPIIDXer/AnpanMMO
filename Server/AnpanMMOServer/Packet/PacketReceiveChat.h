#ifndef __PACKETRECEIVECHAT_H__
#define __PACKETRECEIVECHAT_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketReceiveChat  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::ReceiveChat; }

	

	u32 Uuid;
	std::string Name;
	std::string Message;
	

	PacketReceiveChat()
	{
	}

	PacketReceiveChat(u32 InUuid, std::string InName, std::string InMessage)
	{
		Uuid = InUuid;
		Name = InName;
		Message = InMessage;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		pStream->Serialize(&Name);
		pStream->Serialize(&Message);
		
		return true;
	}
};

#endif		// #ifndef __PACKETRECEIVECHAT_H__
