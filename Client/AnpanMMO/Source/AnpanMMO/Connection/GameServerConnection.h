// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Networking/Public/Networking.h"

/**
 * �Q�[���T�[�o�ڑ�.
 */
class GameServerConnection
{

public:

	// �R���X�g���N�^
	GameServerConnection();

	// �f�X�g���N�^
	~GameServerConnection();

	// �ڑ�.
	bool Connect(const FString &URL, int32 Port);

	// �ؒf.
	void Close();

private:

	// Socket
	FSocket *pSocket;

};
