#ifndef __CLIENTSTATEBASE_H__
#define __CLIENTSTATEBASE_H__

class Client;
class MemoryStreamInterface;
enum PacketID;

/**
 * �N���C�A���g�X�e�[�g���N���X
 */
class ClientStateBase
{

public:

	// �R���X�g���N�^
	ClientStateBase(Client *pInParent)
		: pParent(pInParent) {}

	// �f�X�g���N�^
	virtual ~ClientStateBase() {}

	// �p�P�b�g���.
	virtual void AnalyzePacket(PacketID ID, MemoryStreamInterface *pStream) {}
	
protected:

	// �e���擾.
	Client *GetParent() const { return pParent; }

private:

	// �e.
	Client *pParent;

};

#endif		// #ifndef __CLIENTSTATEBASE_H__
