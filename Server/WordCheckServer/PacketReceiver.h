#ifndef __PACKETRECEIVER_H__
#define __PACKETRECEIVER_H__

#include <boost/function.hpp>
#include <boost/unordered_map.hpp>

class GameServerConnection;
class MemoryStreamInterface;

/**
 * �p�P�b�g����M����N���X
 */
class PacketReceiver
{

private:		// �ʖ���`.

	typedef function<void(MemoryStreamInterface *)> PacketFunc;
	typedef unordered_map<u8, PacketFunc> PacketFuncMap;

public:

	// �R���X�g���N�^
	PacketReceiver(GameServerConnection *pInParent);

	// �f�X�g���N�^
	~PacketReceiver() {}

	// �p�P�b�g��M.
	void RecvPacket(u8 ID, MemoryStreamInterface *pStream);

private:

	// �e.
	GameServerConnection *pParent;

	// �p�P�b�g��M�֐��}�b�v
	PacketFuncMap PacketFuncs;


	// �p�P�b�g��M�֐���ǉ�.
	void AddPacketFunc(u8 ID, const PacketFunc &Func);

	// �`���b�g�̃��[�h�`�F�b�N�v������M�����B
	void OnRecvChatWordCheckRequest(MemoryStreamInterface *pStream);

};

#endif		// #ifndef __PACKETRECEIVER_H__
