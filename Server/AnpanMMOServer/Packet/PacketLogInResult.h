#ifndef __PACKETLOGINRESULT_H__
#define __PACKETLOGINRESULT_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class PacketLogInResult  : public PacketBase
{
public:
	virtual u8 GetPacketID() const { return PacketID::LogInResult; }

	enum ResultCode
	{
		Success,
		DoubleLogIn,
		NoCharacter,
		Error,
	};

	u8 Result;
	s32 Uuid;
	u32 LastAreaId;
	

	PacketLogInResult()
	{
	}

	PacketLogInResult(u8 InResult, s32 InUuid, u32 InLastAreaId)
	{
		Result = InResult;
		Uuid = InUuid;
		LastAreaId = InLastAreaId;
		
	}

	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		pStream->Serialize(&Uuid);
		pStream->Serialize(&LastAreaId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETLOGINRESULT_H__
