#ifndef __PARTYMANAGER_H__
#define __PARTYMANAGER_H__

#include "Party.h"

/**
 * �p�[�e�B�}�l�[�W��
 */
class PartyManager : noncopyable
{

private:		// �ʖ���`.

	typedef shared_ptr<Party> PartySharedPtr;
	typedef boost::unordered_map<u32, PartySharedPtr> PartyList;

public:

	// �f�X�g���N�^
	~PartyManager() {}

	// ���t���[���̏���.
	void Poll();

	// �쐬.
	void Create(PlayerCharacterPtr pCreatePlayer);

	// �擾.
	PartyPtr Get(u32 Uuid);

	// ���ɂǂ����̃p�[�e�B�ɎQ���ς݂��H
	bool IsAlreadyJoined(u32 Uuid);

private:

	// �p�[�e�B���X�g
	PartyList Partys;

	// ============ Singleton =============

public:

	static PartyManager &GetInstance() { return Instance; }

private:

	PartyManager();
	static PartyManager Instance;

};

#endif		// #ifndef __PARTYMANAGER_H__
