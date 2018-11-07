// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PlayerCharacterBase.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/SkeletalMesh.h"

const TCHAR *APlayerCharacterBase::MeshPath = TEXT("/Game/Meshes/Player/Character/Mesh/SK_Mannequin.SK_Mannequin");

// コンストラクタ
APlayerCharacterBase::APlayerCharacterBase(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
	pMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("MeshComponent");
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshFinder(MeshPath);
	pMeshComponent->SetSkeletalMesh(MeshFinder.Object);
	pMeshComponent->SetWorldLocation(FVector(0, 0, -110.0f));
	pMeshComponent->SetWorldRotation(FRotator(0.0f, -90.0f, 0.0f));

	RootComponent = pMeshComponent;
}
