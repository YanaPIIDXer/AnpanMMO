// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Connection/GameServerConnection.h"
#include "MMOGameInstance.generated.h"

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

private:

	// �Q�[���T�[�o�ւ̐ڑ�.
	GameServerConnection *pConnection;
	
};
