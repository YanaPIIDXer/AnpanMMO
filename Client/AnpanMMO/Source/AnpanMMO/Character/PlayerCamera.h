// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "PlayerCamera.generated.h"

/**
 * �v���C���[�J����
 */
UCLASS()
class ANPANMMO_API APlayerCamera : public ACameraActor
{

	GENERATED_BODY()
	
public:

	// �R���X�g���N�^
	APlayerCamera(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~APlayerCamera() {}

private:
	
	
};
