// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleSystemComponent.h"
#include "WarpPoint.generated.h"

struct WarpDataItem;

/**
 * ワープポイントクラス
 */
UCLASS()
class ANPANMMO_API AWarpPoint : public AActor
{

	GENERATED_BODY()
	
public:	

	// Spawn
	static AWarpPoint *Spawn(UWorld *pWorld, float X, float Y, uint32 Id);

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

	// ワープデータ
	TArray<const WarpDataItem *> WarpDatas;


	// 初期化.
	void Initialize(uint32 Id);

};
