// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleSystemComponent.h"
#include "WarpPoint.generated.h"

/**
 * ワープポイントクラス
 */
UCLASS()
class ANPANMMO_API AWarpPoint : public AActor
{

	GENERATED_BODY()
	
public:	

	// コンストラクタ
	AWarpPoint(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~AWarpPoint() {}

private:

	// パーティクルのパス
	static const TCHAR *ParticlePath;

	// パーティクルシステムコンポーネント
	UPROPERTY()
	UParticleSystemComponent *pParticleComponent;

};
