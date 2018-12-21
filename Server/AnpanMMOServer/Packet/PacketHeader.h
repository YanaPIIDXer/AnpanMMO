#ifndef __PACKETHEADER_H__
#define __PACKETHEADER_H__

class MemoryStreamInterface;

// �p�P�b�g�ɕt������w�b�_
class PacketHeader
{

public:

	// ID�擾
	u8 GetPacketId(){ return PacketId; }

	// �p�P�b�g�T�C�Y�擾
	u16 GetPacketSize(){ return PacketSize; }

	// �V���A���C�Y
	bool Serialize(MemoryStreamInterface *Stream);

private:

	// �p�P�b�g�h�c
	u8 PacketId;

	// �p�P�b�g�T�C�Y
	u16 PacketSize;

};

#endif		// #ifndef __PACKETHEADER_H__
