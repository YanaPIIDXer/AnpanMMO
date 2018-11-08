// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "Anpan.h"
#include "AnpanController.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Util.h"
#include "Packet/AnpanData.h"

const TCHAR *AAnpan::MeshPath = TEXT("/Game/Meshes/Anpan/Mesh/Anpan.Anpan");
const TCHAR *AAnpan::BlueprintPath = TEXT("/Game/Blueprints/System/Active/Anpan.Anpan");

// 生成.
AAnpan *AAnpan::Spawn(UWorld *pWorld, const AnpanData &Data)
{
	AAnpan *pAnpan = Util::SpawnFromBlueprint<AAnpan>(pWorld, BlueprintPath, FVector(Data.X, Data.Y, 100.0f), FRotator(0.0f, Data.Rotation, 0.0f));
	pAnpan->Initialize(Data.Hp, Data.MaxHp);
	pAnpan->Uuid = Data.Uuid;

	return pAnpan;
}

// コンストラクタ
AAnpan::AAnpan(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pController(nullptr)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pMeshComponent = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, "MeshComponent");

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshFinder(MeshPath);
	pMeshComponent->SetStaticMesh(MeshFinder.Object);
	pMeshComponent->AddWorldRotation(FRotator(0.0f, 90.0f, 0.0f));
	pMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	pMeshComponent->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel1);

	RootComponent = pMeshComponent;

	AIControllerClass = AAnpanController::StaticClass();
}

// 開始時の処理.
void AAnpan::BeginPlay()
{
	Super::BeginPlay();

	SpawnDefaultController();
}

// コントローラと紐付けられた。
void AAnpan::PossessedBy(AController *NewController)
{
	Super::PossessedBy(NewController);

	pController = Cast<AAnpanController>(NewController);
	check(pController != nullptr);
}

// 移動.
void AAnpan::Move(float X, float Y, int32 Time)
{
	pController->Move(X, Y, Time);
}

// 回転.
void AAnpan::Rotate(float Rotation, int32 Time)
{
	pController->Rotate(Rotation, Time);
}
