#ifndef __PACKETHEADER_H__
#define __PACKETHEADER_H__

class MemoryStreamInterface;
#include "Packet/PacketID.h"

// パケットに付随するヘッダ
class PacketHeader
{

public:

	// ID取得
	PacketID GetPacketId(){ return (PacketID) PacketId; }

	// パケットサイズ取得
	u16 GetPacketSize(){ return PacketSize; }

	// シリアライズ
	bool Serialize(MemoryStreamInterface *Stream);

private:

	// パケットＩＤ
	u8 PacketId;

	// パケットサイズ
	u16 PacketSize;

};

#endif		// #ifndef __PACKETHEADER_H__
