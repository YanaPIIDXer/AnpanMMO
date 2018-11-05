#ifndef __WORLD_H__
#define __WORLD_H__

#include <vector>
#include "Character/PlayerCharacter.h"
#include "AnpanManager.h"

class PacketBase;

/**
 * ���[���h�N���X
 */
class World : noncopyable
{

public:

	// ���t���[���̏���.
	void Poll();

	// �v���C���[�L�����̒ǉ�.
	void AddPlayerCharacter(const PlayerCharacterPtr &pPlayer);

	// �A���p���Ǘ����擾.
	const AnpanManager &GetAnpanManager() const { return AnpanMgr; }

private:

	// �v���C���[�L�������X�g
	std::vector<PlayerCharacterPtr> PlayerList;

	// �A���p���Ǘ�.
	AnpanManager AnpanMgr;


	// PlayerList�̍X�V.
	void UpdatePlayerList();

	// �p�P�b�g���u���[�h�L���X�g
	void BroadcastPacket(PacketBase *pPacket);

	// ========== Singleton =========
public:

	static World &GetInstance() { return Instance; }

private:

	// �R���X�g���N�^
	World();
	static World Instance;

};

#endif		// #ifndef __WORLD_H__
