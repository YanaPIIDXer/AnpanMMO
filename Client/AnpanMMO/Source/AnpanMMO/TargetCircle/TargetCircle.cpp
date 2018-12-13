// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "TargetCircle.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Character/CharacterBase.h"

const TCHAR *ATargetCircle::AssetPath = TEXT("/Game/Resources/Meshes/TargetCircle/TargetCircle.TargetCircle");
const float ATargetCircle::HeightOffset = 10.0f;
const float ATargetCircle::RotateBySec = 60.0f;

// コンストラクタ
ATargetCircle::ATargetCircle(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pCharacter(nullptr)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pMeshCmp = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, "CircleMeshCmp");
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshFinder(AssetPath);
	pMeshCmp->SetStaticMesh(MeshFinder.Object);

	RootComponent = pMeshCmp;
}

// キャラクタをセット
void ATargetCircle::SetCharacter(ACharacterBase *pInCharacter)
{
	pCharacter = pInCharacter;
	float Scale = pCharacter->GetActorScale3D().X;
	SetActorScale3D(FVector(Scale, Scale, Scale));
}

// 毎フレームの処理.
void ATargetCircle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (pCharacter == nullptr)
	{
		Destroy();
		return;
	}

	FVector Pos = pCharacter->GetActorLocation();
	Pos.Z -= pCharacter->GetHalfHeight() + HeightOffset;
	SetActorLocation(Pos);

	float Rotate = RotateBySec * DeltaTime;
	FRotator Rot = GetActorRotation();
	Rot.Yaw += Rotate;
	SetActorRotation(Rot);
}

