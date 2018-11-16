// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
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

	// 毎フレームの処理.
	virtual void Tick(float DeltaTime) override;

	// 衝突イベント
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent *pOverlappedComponent, AActor *pOtherActor, UPrimitiveComponent *pOtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

private:

	// コリジョン半径.
	static const float CollisionRadius;

	// パーティクルのパス
	static const TCHAR *ParticlePath;

	// コリジョン用の球コンポーネント
	UPROPERTY()
	USphereComponent *pCollisionComponent;

	// パーティクルシステムコンポーネント
	UPROPERTY()
	UParticleSystemComponent *pParticleComponent;

	// ワープデータ
	TArray<const WarpDataItem *> WarpDatas;

	// 初期化されたか？
	bool bInitialized;


	// 初期化.
	void Initialize(uint32 Id);

};
