// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "ActiveGameMode.generated.h"

enum PacketID;
class MemoryStreamInterface;

/**
 * �Q�[����GameMode
 */
UCLASS()
class ANPANMMO_API AActiveGameMode : public AGameMode
{
	GENERATED_BODY()

public:

	// �R���X�g���N�^
	AActiveGameMode(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~AActiveGameMode() {}

	// �J�n���̏���.
	virtual void BeginPlay() override;

protected:

private:

	// �p�P�b�g����M�����B
	void OnRecvPacket(PacketID ID, MemoryStreamInterface *pStream);
	

	

};
