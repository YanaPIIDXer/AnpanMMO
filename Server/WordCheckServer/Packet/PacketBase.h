#ifndef __PACKETBASE_H__
#define __PACKETBASE_H__

class MemoryStreamInterface;
#include "TypeDefs.h"

// �p�P�b�g���N���X
// �e��p�P�b�g�͂��̃N���X��h�����Ē�`����B
class PacketBase
{

public:

	// �f�X�g���N�^
	virtual ~PacketBase() {}

	// �p�P�b�g�h�c�擾
	virtual u8 GetPacketID() const = 0;

	//�V���A���C�Y
	virtual bool Serialize(MemoryStreamInterface *pStream) = 0;

};

#endif		//#ifndef __PACKETBASE_H__
