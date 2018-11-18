#ifndef __PLAYERMANAGER_H__
#define __PLAYERMANAGER_H__

#include <boost/unordered_map.hpp>

class PlayerCharacter;
typedef weak_ptr<PlayerCharacter> PlayerCharacterPtr;
class PacketBase;
class Client;
class PacketPlayerList;

/**
 * �v���C���[�Ǘ��N���X
 */
class PlayerManager
{

private:		// �ʖ���`.

	typedef unordered_map<u32, PlayerCharacterPtr> PlayerMap;

public:

	// �R���X�g���N�^
	PlayerManager();

	// �f�X�g���N�^
	~PlayerManager() {}

	// ���t���[���̏���.
	void Poll();

	// �ǉ�.
	void Add(u32 Uuid, PlayerCharacterPtr pPlayer);

	// �폜.
	void Remove(u32 Uuid);

	// �擾.
	PlayerCharacterPtr Get(u32 Uuid) const;

	// �ړ�����M�����B
	void OnRecvMove(u32 Uuid, float X, float Y, float Z, float Rot);

	// �p�P�b�g���u���[�h�L���X�g
	void BroadcastPacket(PacketBase *pPacket, Client *pIgnoreClient = NULL);

private:

	// �v���C���[�}�b�v
	PlayerMap PlayerList;


	// �v���C���[���X�g�p�P�b�g�𐶐�.
	void MakeListPacket(PacketPlayerList &Packet);

};

#endif		// #ifndef __PLAYERMANAGER_H__
