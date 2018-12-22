// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Packet/PartyMemberData.h"

class MemoryStreamInterface;
class AActiveGameMode;

/**
 * �p�[�e�B���.
 */
class ANPANMMO_API PartyInformation
{

public:

	// �R���X�g���N�^
	PartyInformation();

	// �f�X�g���N�^
	~PartyInformation() {}

	// GameMode���Z�b�g�B
	void SetGameMode(AActiveGameMode *pInGameMode) { pGameMode = pInGameMode; }

	// �Q�����Ă��邩�H
	bool IsJoined() const { return (PartyId != 0); }

	// ���[�_�[���H
	bool IsLeader() const { return bIsLeader; }

	// �����o���X�g���擾.
	TArray<PartyMemberData> GetMemberList() const;

	// �쐬���ʂ���M�����B
	bool OnRecvCreateResult(MemoryStreamInterface *pStream);

	// ���U���ʂ���M�����B
	bool OnRecvDissolutionResult(MemoryStreamInterface *pStream);

	// ���E���ʂ���M�����B
	bool OnRecvExitResult(MemoryStreamInterface *pStream);

	// �Q������M�����B
	bool OnRecvJoin(MemoryStreamInterface *pStream);

	// �����o��������M�����B
	bool OnRecvJoinMember(MemoryStreamInterface *pStream);

	// �����o���E����M�����B
	bool OnRecvExitMember(MemoryStreamInterface *pStream);

	// �����o�L�b�N����M�����B
	bool OnRecvKickMember(MemoryStreamInterface *pStream);

	// ���U����M�����B
	bool OnRecvDissolution(MemoryStreamInterface *pStream);

private:

	// �p�[�e�B�h�c
	uint32 PartyId;

	// ���[�_�[���H
	bool bIsLeader;

	// GameMode
	TWeakObjectPtr<AActiveGameMode> pGameMode;

	// �����o���X�g
	TMap<uint32, PartyMemberData> MemberList;

};
