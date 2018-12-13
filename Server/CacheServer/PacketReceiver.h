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

	// ���O�C�����N�G�X�g����M�����B
	void OnRecvLogInRequest(MemoryStreamInterface *pStream);

	// �L�����N�^�쐬���N�G�X�g����M�����B
	void OnRecvCreateCharacterRequest(MemoryStreamInterface *pStream);

	// �L�����N�^��񃊃N�G�X�g����M�����B
	void OnRecvCharacterDataRequest(MemoryStreamInterface *pStream);

	// �L�����N�^�ۑ����N�G�X�g����M�����B
	void OnRecvCharacterDataSaveRequest(MemoryStreamInterface *pStream);

	// �X�L�����X�g�v������M�����B
	void OnRecvSkillListRequest(MemoryStreamInterface *pStream);

	// �X�N���v�g�t���O�ǂݍ��݃��N�G�X�g����M�����B
	void OnRecvLoadScriptFlagRequest(MemoryStreamInterface *pStream);

	// �X�N���v�g�t���O�ۑ����N�G�X�g����M�����B
	void OnRecvSaveScriptFlagRequest(MemoryStreamInterface *pStream);

	// �S�[���h�ۑ����N�G�X�g����M�����B
	void OnRecvSaveGold(MemoryStreamInterface *pStream);

};

#endif		// #ifndef __PACKETRECEIVER_H__
