#include "stdafx.h"
#include "PacketHeader.h"
#include <string>
#include "MemoryStream/MemoryStreamInterface.h"

// �V���A���C�Y
bool PacketHeader::Serialize(MemoryStreamInterface *Stream)
{
	if(!Stream->Serialize(&PacketId)) { return false; }
	return Stream->Serialize(&PacketSize);
}
