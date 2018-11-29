#ifndef __PARTY_H__
#define __PARTY_H__

#include "Character/Player/PlayerCharacter.h"

class Party;
typedef weak_ptr<Party> PartyPtr;

/**
 * �p�[�e�B�N���X
 */
class Party : public enable_shared_from_this<Party>
{

private:		// �ʖ���`.

	typedef boost::unordered_map<u32, PlayerCharacterPtr> MemberMap;

public:

	// �R���X�g���N�^
	Party(u32 InUuid);

	// �f�X�g���N�^
	~Party() {}

	// �Q��.
	void Join(PlayerCharacterPtr pPlayer);

	// �E��.
	void Secession(u32 Uuid);

	// �폜���Ă��������H
	bool IsAbleDelete() const;

	// UUID���擾.
	u32 GetUuid() const { return Uuid; }

private:

	// �����o�}�b�v
	MemberMap MemberList;

	// UUID
	u32 Uuid;

};

#endif		// #ifndef __PARTY_H__
