#ifndef __PARTYMANAGER_H__
#define __PARTYMANAGER_H__

#include "Party.h"

/**
 * �p�[�e�B�}�l�[�W��
 */
class PartyManager : noncopyable
{

private:		// �ʖ���`.

	typedef boost::unordered_map<u32, PartyPtr> PartyList;

public:

	// �f�X�g���N�^
	~PartyManager() {}

	// ���t���[���̏���.
	void Poll();

	// �ǉ�.
	void Add(PartyPtr pParty);

private:

	// �p�[�e�B���X�g
	PartyList Partys;

	// ���Ɋ���U��UUID
	u32 NextUuid;

	// ============ Singleton =============

public:

	static PartyManager &GetInstance() { return Instance; }

private:

	PartyManager();
	static PartyManager Instance;

};

#endif		// #ifndef __PARTYMANAGER_H__
