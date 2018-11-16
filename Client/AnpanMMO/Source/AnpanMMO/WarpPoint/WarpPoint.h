// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

private:

	// �p�[�e�B�N���̃p�X
	static const TCHAR *ParticlePath;

	// �p�[�e�B�N���V�X�e���R���|�[�l���g
	UPROPERTY()
	UParticleSystemComponent *pParticleComponent;

	// ���[�v�f�[�^
	TArray<const WarpDataItem *> WarpDatas;


	// ������.
	void Initialize(uint32 Id);

};
