// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Networking/Public/Networking.h"
#include "Tickable.h"
#include "Buffer.h"

/**
 * �Q�[���T�[�o�ڑ�.
 */
class GameServerConnection : public FTickableGameObject
{

public:

	// �R���X�g���N�^
	GameServerConnection();

	// �f�X�g���N�^
	~GameServerConnection();

	// �ڑ�.
	bool Connect(const FString &Host, int32 Port);

	// �ؒf.
	void Close();

	// �ڑ�����Ă��邩�H
	bool IsConnected() const { return (pSocket != nullptr && pSocket->GetConnectionState() == ESocketConnectionState::SCS_Connected); }

	// ���t���[���̏���.
	virtual void Tick(float DeltaTime) override;

	// StatID�擾.
	virtual TStatId GetStatId() const override { return TStatId(); }

private:

	// Socket
	FSocket *pSocket;

	// ��M�o�b�t�@
	Buffer RecvBuffer;

	// ���M�o�b�t�@
	Buffer SendBuffer;


	// ���M����.
	void SendProc();

	// ��M����.
	void RecvProc();

};
