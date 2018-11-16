// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "WarpPoint.generated.h"

struct WarpDataItem;

/**
 * ���[�v�|�C���g�N���X
 */
UCLASS()
class ANPANMMO_API AWarpPoint : public AActor
{

	GENERATED_BODY()
	
public:	

	// Spawn
	static AWarpPoint *Spawn(UWorld *pWorld, float X, float Y, uint32 Id);

	// �R���X�g���N�^
	AWarpPoint(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~AWarpPoint() {}

	// ���t���[���̏���.
	virtual void Tick(float DeltaTime) override;

	// �Փ˃C�x���g
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent *pOverlappedComponent, AActor *pOtherActor, UPrimitiveComponent *pOtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

private:

	// �R���W�������a.
	static const float CollisionRadius;

	// �p�[�e�B�N���̃p�X
	static const TCHAR *ParticlePath;

	// �R���W�����p�̋��R���|�[�l���g
	UPROPERTY()
	USphereComponent *pCollisionComponent;

	// �p�[�e�B�N���V�X�e���R���|�[�l���g
	UPROPERTY()
	UParticleSystemComponent *pParticleComponent;

	// ���[�v�f�[�^
	TArray<const WarpDataItem *> WarpDatas;

	// ���������ꂽ���H
	bool bInitialized;


	// ������.
	void Initialize(uint32 Id);

};
