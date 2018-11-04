// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "GameCharacter.h"
#include "GameCamera.generated.h"

/**
 * �v���C���[�J����
 */
UCLASS()
class ANPANMMO_API AGameCamera : public ACameraActor
{

	GENERATED_BODY()
	
public:

	// �R���X�g���N�^
	AGameCamera(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~AGameCamera() {}

	// ���t���[���̏���.
	virtual void Tick(float DeltaTime) override;

	// �v���C���[�L�������Z�b�g�B
	void SetGameCharacter(AGameCharacter *pInPlayer) { pPlayer = pInPlayer; }

private:
	
	// �v���C���[�L����
	TWeakObjectPtr<AGameCharacter> pPlayer;
	
};
