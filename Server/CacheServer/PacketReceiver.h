#ifndef __PACKETRECEIVER_H__
#define __PACKETRECEIVER_H__

#include <boost/function.hpp>
#include <boost/unordered_map.hpp>
#include "Packet/PacketID.h"

class GameServerConnection;
class MemoryStreamInterface;

/**
 * �p�P�b�g����M����N���X
 */
class PacketReceiver
{

private:		// �ʖ���`.

	typedef function<void(MemoryStreamInterface *)> PacketFunc;
	typedef unordered_map<PacketID, PacketFunc> PacketFuncMap;

public:

	// �R���X�g���N�^
	PacketReceiver(GameServerConnection *pInParent);

	// �f�X�g���N�^
	~PacketReceiver() {}

	// �p�P�b�g��M.
	void RecvPacket(PacketID ID, MemoryStreamInterface *pStream);

private:

	// �e.
	GameServerConnection *pParent;

	// �p�P�b�g��M�֐��}�b�v
	PacketFuncMap PacketFuncs;


	// �p�P�b�g��M�֐���ǉ�.
	void AddPacketFunc(PacketID ID, const PacketFunc &Func);

	// ���O�C�����N�G�X�g����M�����B
	void OnRecvLogInRequest(MemoryStreamInterface *pStream);

	// �L�����N�^��񃊃N�G�X�g����M�����B
	void OnRecvCharacterDataRequest(MemoryStreamInterface *pStream);

	// �L�����N�^�ۑ����N�G�X�g����M�����B
	void OnRecvCharacterDataSave(MemoryStreamInterface *pStream);

};

#endif		// #ifndef __PACKETRECEIVER_H__