// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "PlayerCamera.generated.h"

/**
 * プレイヤーカメラ
 */
UCLASS()
class ANPANMMO_API APlayerCamera : public ACameraActor
{

	GENERATED_BODY()
	
public:

	// コンストラクタ
	APlayerCamera(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~APlayerCamera() {}

private:
	
	
};
