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
	void OnRecvCreateResult(MemoryStreamInterface *pStream);

	// ���U���ʂ���M�����B
	void OnRecvDissolutionResult(MemoryStreamInterface *pStream);

	// ���E���ʂ���M�����B
	void OnRecvExitResult(MemoryStreamInterface *pStream);

	// �Q������M�����B
	void OnRecvJoin(MemoryStreamInterface *pStream);

	// �����o��������M�����B
	void OnRecvJoinMember(MemoryStreamInterface *pStream);

	// �����o���E����M�����B
	void OnRecvExitMember(MemoryStreamInterface *pStream);

	// ���U����M�����B
	void OnRecvDissolution(MemoryStreamInterface *pStream);

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
