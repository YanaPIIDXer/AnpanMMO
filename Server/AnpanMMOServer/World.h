#ifndef __WORLD_H__
#define __WORLD_H__

#include <vector>
#include "Character/PlayerCharacter.h"

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

private:

	// �v���C���[�L�������X�g
	std::vector<PlayerCharacterPtr> PlayerList;


	// PlayerList�̍X�V.
	void UpdatePlayerList();

	// ========== Singleton =========
public:

	static World &GetInstance() { return Instance; }

private:

	// �R���X�g���N�^
	World();
	static World Instance;

};

#endif		// #ifndef __WORLD_H__
