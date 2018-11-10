#ifndef __WORLD_H__
#define __WORLD_H__

#include <boost/unordered_map.hpp>
#include "Character/Player/PlayerCharacter.h"
#include "PlayerManager.h"
#include "AnpanManager.h"

class PacketBase;
class MemoryStreamInterface;

/**
 * ���[���h�N���X
 */
class World : noncopyable
{

public:

	// ������.
	void Initialize();

	// ���t���[���̏���.
	void Poll(int DeltaTime);

	// �v���C���[�L�����̒ǉ�.
	void AddPlayerCharacter(const PlayerCharacterPtr &pPlayer);

	// �p�P�b�g���u���[�h�L���X�g
	void BroadcastPacket(PacketBase *pPacket);

	// �v���C���[�ړ�����M�����B
	void OnRecvMove(Client *pClient, MemoryStreamInterface *pStream);

	// �U������M�����B
	void OnRecvAttack(Client *pClient, MemoryStreamInterface *pStream);

	// ���X�|�����N�G�X�g��M.
	void OnRecvRespawnRequest(Client *pClient, MemoryStreamInterface *pStream);

	// �v���C���[�L�����N�^���擾.
	PlayerCharacterPtr GetPlayer(u32 Uuid) const;

	// �A���p�����擾.
	AnpanPtr GetAnpan(u32 Uuid) const;

private:

	// �v���C���[�Ǘ�.
	PlayerManager PlayerMgr;
	
	// �A���p���Ǘ�.
	AnpanManager AnpanMgr;


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
