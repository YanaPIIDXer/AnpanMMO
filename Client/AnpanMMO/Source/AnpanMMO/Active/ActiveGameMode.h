// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MMOGameModeBase.h"
#include "Character/Anpan/AnpanManager.h"
#include "ActiveGameMode.generated.h"

/**
 * �Q�[����GameMode
 */
UCLASS()
class ANPANMMO_API AActiveGameMode : public AMMOGameModeBase
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	AActiveGameMode(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~AActiveGameMode() {}

	// �J�n���̏���.
	virtual void BeginPlay() override;

	// ���t���[���̏���.
	virtual void Tick(float DeltaTime) override;

protected:

private:

	// �A���p���Ǘ�.
	AnpanManager AnpanMgr;


	// �_���[�W����M�����B
	void OnRecvDamage(MemoryStreamInterface *pStream);

};
