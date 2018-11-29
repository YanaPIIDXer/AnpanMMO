// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

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

private:

	// �p�[�e�B�h�c
	uint32 PartyId;

	// GameMode
	TWeakObjectPtr<AActiveGameMode> pGameMode;

};
