// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PlayerCharacterBase.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/SkeletalMesh.h"

const TCHAR *APlayerCharacterBase::MeshPath = TEXT("/Game/Resources/Meshes/Player/Character/Mesh/SK_Mannequin.SK_Mannequin");

// コンストラクタ
APlayerCharacterBase::APlayerCharacterBase(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pAnimClass(nullptr)
{
	auto *pMeshComponent = GetMesh();

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshFinder(MeshPath);
	pMeshComponent->SetSkeletalMesh(MeshFinder.Object);

	pMeshComponent->SetRelativeLocation(FVector(0, 0, -110.0f));
	pMeshComponent->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	pMeshComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
	pMeshComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel2, ECollisionResponse::ECR_Overlap);
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);
}


// 開始時の処理.
void APlayerCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	if (pAnimClass != nullptr)
	{
		GetMesh()->SetAnimInstanceClass(Cast<UClass>(pAnimClass));
	}
}

// リスポン
void APlayerCharacterBase::Respawn()
{
	OnRespawn();
}
