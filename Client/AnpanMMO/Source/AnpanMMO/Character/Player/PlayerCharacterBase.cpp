// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PlayerCharacterBase.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/SkeletalMesh.h"
#include "Components/SphereComponent.h"

const TCHAR *APlayerCharacterBase::MeshPath = TEXT("/Game/Meshes/Player/Character/Mesh/SK_Mannequin.SK_Mannequin");

// �R���X�g���N�^
APlayerCharacterBase::APlayerCharacterBase(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
	USphereComponent *pDummyComponent = CreateDefaultSubobject<USphereComponent>("Dummy");
	pDummyComponent->bHiddenInGame = true;
	pDummyComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	RootComponent = pDummyComponent;

	pMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("MeshComponent");
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshFinder(MeshPath);
	pMeshComponent->SetSkeletalMesh(MeshFinder.Object);

	pMeshComponent->AttachTo(pDummyComponent);
	pMeshComponent->SetRelativeLocation(FVector(0, 0, -110.0f));
	pMeshComponent->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
}