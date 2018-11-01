// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Networking/Public/Networking.h"
#include "Tickable.h"
#include "Buffer.h"

class PacketBase;

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

	// �p�P�b�g���M.
	void SendPacket(PacketBase *pPacket);

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

	// ��M�f�[�^�T�C�Y
	static const int32 RecvDataSize;


	// ���M����.
	void SendProc();

	// ��M����.
	void RecvProc();

};
