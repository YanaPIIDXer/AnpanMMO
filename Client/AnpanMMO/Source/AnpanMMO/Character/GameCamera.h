// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "GameCharacter.h"
#include "GameCamera.generated.h"

/**
 * プレイヤーカメラ
 */
UCLASS()
class ANPANMMO_API AGameCamera : public ACameraActor
{

	GENERATED_BODY()
	
public:

	// コンストラクタ
	AGameCamera(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~AGameCamera() {}

	// プレイヤーキャラをセット。
	void SetGameCharacter(AGameCharacter *pInPlayer) { pPlayer = pInPlayer; }

private:
	
	// プレイヤーキャラ
	TWeakObjectPtr<AGameCharacter> pPlayer;
	
};
