#ifndef __PARTY_H__
#define __PARTY_H__

#include <boost/unordered_map.hpp>
#include "WeakPtrDefine.h"

class PacketBase;

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
	bool Join(PlayerCharacterPtr pPlayer);

	// �E��.
	void Exit(u32 Uuid);

	// �����o���X�g�擾.
	std::vector<PlayerCharacterPtr> GetMemberList() const;

	// �����o���ő傩�H
	bool IsMaximumMember() const { return (MemberList.size() >= MaximumMember); }

	// �폜���Ă��������H
	bool IsAbleDelete() const;

	// UUID���擾.
	u32 GetUuid() const { return Uuid; }

	// �p�P�b�g���o���T���B
	void BroadcastPacket(PacketBase *pPacket);

private:

	// �����o�ő吔.
	static const u32 MaximumMember;

	// �����o�}�b�v
	MemberMap MemberList;

	// UUID
	u32 Uuid;

};

#endif		// #ifndef __PARTY_H__
