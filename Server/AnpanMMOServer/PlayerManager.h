#ifndef __PLAYERMANAGER_H__
#define __PLAYERMANAGER_H__

#include <boost/unordered_map.hpp>
#include "Character/Player/PlayerCharacter.h"

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
	void Add(u8 Uuid, PlayerCharacterPtr pPlayer);

	// �擾.
	PlayerCharacterPtr Get(u8 Uuid) const;

private:

	// �v���C���[�}�b�v
	PlayerMap PlayerList;

};

#endif		// #ifndef __PLAYERMANAGER_H__
