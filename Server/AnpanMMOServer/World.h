#ifndef __WORLD_H__
#define __WORLD_H__

#include <boost/unordered_map.hpp>
#include "Character/PlayerCharacter.h"
#include "AnpanManager.h"

class PacketBase;
class MemoryStreamInterface;

/**
 * ���[���h�N���X
 */
class World : noncopyable
{

private:		// �ʖ���`.

	typedef unordered_map<u32, PlayerCharacterPtr> PlayerMap;

public:

	// ������.
	void Initialize();

	// ���t���[���̏���.
	void Poll();

	// �v���C���[�L�����̒ǉ�.
	void AddPlayerCharacter(const PlayerCharacterPtr &pPlayer);

	// �A���p������.
	void SpawnAnpan() { AnpanMgr.SpawnAnpan(); }

	// �U������M�����B
	void OnRecvAttack(Client *pClient, MemoryStreamInterface *pStream);

private:

	// �v���C���[�L�������X�g
	PlayerMap PlayerList;

	// �A���p���Ǘ�.
	AnpanManager AnpanMgr;


	// PlayerList�̍X�V.
	void UpdatePlayerList();

	// �p�P�b�g���u���[�h�L���X�g
	void BroadcastPacket(PacketBase *pPacket);

	// �A���p�����������ꂽ�B
	void OnSpawnAnpan(unsigned int Uuid, AnpanPtr pAnpan);

	// ========== Singleton =========
public:

	static World &GetInstance() { return Instance; }

private:

	// �R���X�g���N�^
	World();
	static World Instance;

};

#endif		// #ifndef __WORLD_H__
