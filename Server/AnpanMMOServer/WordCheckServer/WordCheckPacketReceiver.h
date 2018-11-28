#ifndef __WORDCHECKPACKETRECEIVER_H__
#define __WORDCHECKPACKETRECEIVER_H__

#include <boost/function.hpp>
#include <boost/unordered_map.hpp>
#include "Packet/PacketID.h"

class WordCheckServerConnection;
class MemoryStreamInterface;

/**
 * �p�P�b�g����M����N���X
 */
class WordCheckPacketReceiver
{

private:		// �ʖ���`.

	typedef function<void(MemoryStreamInterface *)> PacketFunc;
	typedef unordered_map<PacketID, PacketFunc> PacketFuncMap;

public:

	// �R���X�g���N�^
	WordCheckPacketReceiver(WordCheckServerConnection *pInParent);

	// �f�X�g���N�^
	~WordCheckPacketReceiver() {}

	// �p�P�b�g��M.
	void RecvPacket(PacketID ID, MemoryStreamInterface *pStream);

private:

	// �e.
	WordCheckServerConnection *pParent;

	// �p�P�b�g��M�֐��}�b�v
	PacketFuncMap PacketFuncs;


	// �p�P�b�g��M�֐���ǉ�.
	void AddPacketFunc(PacketID ID, const PacketFunc &Func);

};

#endif		// #ifndef __WORDCHECKPACKETRECEIVER_H__
