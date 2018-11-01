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
	u8 GetPacketSize(){ return PacketSize; }

	// シリアライズ
	bool Serialize(MemoryStreamInterface *Stream);

private:

	// パケットＩＤ
	u8 PacketId;

	// パケットサイズ
	u8 PacketSize;

};

#endif		// #ifndef __PACKETHEADER_H__