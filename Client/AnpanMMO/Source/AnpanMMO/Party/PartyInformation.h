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

	// �쐬���ʂ���M�����B
	void OnRecvCreateResult(MemoryStreamInterface *pStream);

	// ���U���ʂ���M�����B
	void OnRecvDissolutionResult(MemoryStreamInterface *pStream);

	// �����o���X�g����M�����B
	void OnRecvMemberList(MemoryStreamInterface *pStream);

	// �����o��������M�����B
	void OnRecvJoinMember(MemoryStreamInterface *pStream);

private:

	// �p�[�e�B�h�c
	uint32 PartyId;

	// GameMode
	TWeakObjectPtr<AActiveGameMode> pGameMode;

	// �����o���X�g
	TArray<PartyMemberData> MemberList;

};
