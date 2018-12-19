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

	// �X�L�����X�g�ۑ��v������M�����B
	void OnRecvSaveSkillListRequest(MemoryStreamInterface *pStream);

	// �X�L���c���[���N�G�X�g����M�����B
	void OnRecvSkillTreeRequest(MemoryStreamInterface *pStream);

	// �X�L���c���[�ۑ��v������M����
	void OnRecvSkillTreeSaveRequest(MemoryStreamInterface *pStream);

	// �X�N���v�g�t���O�ǂݍ��݃��N�G�X�g����M�����B
	void OnRecvLoadScriptFlagRequest(MemoryStreamInterface *pStream);

	// �X�N���v�g�t���O�ۑ����N�G�X�g����M�����B
	void OnRecvSaveScriptFlagRequest(MemoryStreamInterface *pStream);

	// �A�C�e�����X�g���N�G�X�g����M�����B
	void OnRecvItemListRequest(MemoryStreamInterface *pStream);

	// �A�C�e�����ϓ�����M�����B
	void OnRecvItemCountChange(MemoryStreamInterface *pStream);

	// �A�C�e���V���[�g�J�b�g�ǂݍ��݃��N�G�X�g����M�����B
	void OnRecvItemShortcutRequest(MemoryStreamInterface *pStream);

	// �A�C�e���V���[�g�J�b�g�������݃��N�G�X�g����M�����B
	void OnRecvSaveItemShortcutRequest(MemoryStreamInterface *pStream);

	// �S�[���h�ۑ����N�G�X�g����M�����B
	void OnRecvSaveGold(MemoryStreamInterface *pStream);

	// �N�G�X�g�f�[�^���N�G�X�g����M�����B
	void OnRecvQuestDataRequest(MemoryStreamInterface *pStream);

	// �N�G�X�g�f�[�^�ۑ����N�G�X�g����M�����B
	void OnRecvSaveQuestDataRequest(MemoryStreamInterface *pStream);

	// �N�G�X�g�j�����N�G�X�g����M�����B
	void OnRecvRetireQuestDataRequest(MemoryStreamInterface *pStream);

	// �A�N�e�B�u�N�G�X�g�ۑ����N�G�X�g����M�����B
	void OnRecvSaveActiveQuestRequest(MemoryStreamInterface *pStream);

};

#endif		// #ifndef __PACKETRECEIVER_H__
