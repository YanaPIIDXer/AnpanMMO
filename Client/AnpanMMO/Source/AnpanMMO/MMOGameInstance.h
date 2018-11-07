// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Connection/GameServerConnection.h"
#include "Character/Player/PlayerStatus.h"
#include "MMOGameInstance.generated.h"

class PacketBase;

/**
 * GameInstance
 */
UCLASS()
class ANPANMMO_API UMMOGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	// �R���X�g���N�^
	UMMOGameInstance(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UMMOGameInstance() {}

	// �I�����̏���.
	virtual void Shutdown() override;

	// �ڑ�.
	bool Connect(const FString &Host, int Port);

	// �ؒf.
	void Close();

	// �ڑ�����Ă��邩�H
	bool IsConnected() const { return (pConnection != nullptr && pConnection->IsConnected()); }

	// �p�P�b�g���M.
	void SendPacket(PacketBase *pPacket);

	// �X�e�[�^�X�L���b�V���擾.
	const PlayerStatus &GetStatusCache() const { return StatusCache; }

	
	// �p�P�b�g��Mdelegate
	FOnRecvPacketDelegate OnRecvPacketDelegate;

private:

	// �Q�[���T�[�o�ւ̐ڑ�.
	GameServerConnection *pConnection;

	// �X�e�[�^�X�L���b�V��
	PlayerStatus StatusCache;


	// �p�P�b�g����M�����B
	void OnRecvPacket(PacketID ID, MemoryStreamInterface *pStream);
	
};
