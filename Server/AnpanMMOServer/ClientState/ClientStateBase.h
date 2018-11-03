#ifndef __CLIENTSTATEBASE_H__
#define __CLIENTSTATEBASE_H__

#include <map>
#include <boost/function.hpp>
#include "Packet/PacketID.h"

class Client;
class MemoryStreamInterface;

/**
 * �N���C�A���g�X�e�[�g���N���X
 */
class ClientStateBase
{

private:		// �ʖ���`.

	typedef std::map<PacketID, boost::function<void(MemoryStreamInterface *)>> FunctionMap;

public:

	// �R���X�g���N�^
	ClientStateBase(Client *pInParent)
		: pParent(pInParent) {}

	// �f�X�g���N�^
	virtual ~ClientStateBase() {}

	// �J�n���̏���.
	virtual void BeginState() {}

	// �p�P�b�g���.
	void AnalyzePacket(PacketID ID, MemoryStreamInterface *pStream);
	
protected:

	// �e���擾.
	Client *GetParent() const { return pParent; }

	// �p�P�b�g��͊֐���ǉ�.
	void AddPacketFunction(PacketID ID, const boost::function<void(MemoryStreamInterface *)> &Func)
	{
		PacketFunctions[ID] = Func;
	}

private:

	// �e.
	Client *pParent;

	// �p�P�b�g��͊֐��Q.
	FunctionMap PacketFunctions;

};

#endif		// #ifndef __CLIENTSTATEBASE_H__
