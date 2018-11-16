// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleSystemComponent.h"
#include "WarpPoint.generated.h"

/**
 * ���[�v�|�C���g�N���X
 */
UCLASS()
class ANPANMMO_API AWarpPoint : public AActor
{

	GENERATED_BODY()
	
public:	

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

};
