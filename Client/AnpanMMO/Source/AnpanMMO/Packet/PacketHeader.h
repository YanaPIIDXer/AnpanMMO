#ifndef __PACKETHEADER_H__
#define __PACKETHEADER_H__

class MemoryStreamInterface;
#include "Packet/PacketID.h"

// �p�P�b�g�ɕt������w�b�_
class PacketHeader
{

public:

	// ID�擾
	PacketID GetPacketId(){ return (PacketID) PacketId; }

	// �p�P�b�g�T�C�Y�擾
	u8 GetPacketSize(){ return PacketSize; }

	// �V���A���C�Y
	bool Serialize(MemoryStreamInterface *Stream);

private:

	// �p�P�b�g�h�c
	u8 PacketId;

	// �p�P�b�g�T�C�Y
	u8 PacketSize;

};

#endif		// #ifndef __PACKETHEADER_H__