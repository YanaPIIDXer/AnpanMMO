#ifndef __PACKETBASE_H__
#define __PACKETBASE_H__

#include "PacketID.h"

class MemoryStreamInterface;

// �p�P�b�g���N���X
// �e��p�P�b�g�͂��̃N���X��h�����Ē�`����B
class PacketBase
{

public:

	// �f�X�g���N�^
	virtual ~PacketBase() {}

	// �p�P�b�g�h�c�擾
	virtual PacketID GetPacketID() const = 0;

	//�V���A���C�Y
	virtual bool Serialize(MemoryStreamInterface *pStream) = 0;

};

#endif		//#ifndef __PACKETBASE_H__