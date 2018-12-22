// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class AActiveGameMode;

/**
 * Tick�Ǘ�.
 */
class ANPANMMO_API PingManager
{
public:

	// �R���X�g���N�^
	PingManager();

	// �f�X�g���N�^
	~PingManager() {}

	// �X�V.
	void Poll(float DeltaTime);

	// �Q�[�����[�h���Z�b�g
	void SetGameMode(AActiveGameMode *pInGameMode) { pGameMode = pInGameMode; }

	// Ping����M�����B
	bool OnRecvPing(MemoryStreamInterface *pStream);

private:

	// �C���^�[�o��
	static const float Interval;

	// �^�C�}�[
	float Timer;

	// GameMode
	TWeakObjectPtr<AActiveGameMode> pGameMode;

	// Ping����M�������H
	bool bRecvPing;

};
