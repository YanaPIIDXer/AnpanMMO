// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "Anpan.h"
#include "AnpanController.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/SphereComponent.h"
#include "Engine/StaticMesh.h"
#include "Util.h"
#include "Master/MasterData.h"
#include "Packet/AnpanData.h"

const float AAnpan::BaseRadius = 80.0f;
const TCHAR *AAnpan::MeshPath = TEXT("/Game/Meshes/Anpan/Mesh/Anpan.Anpan");
const TCHAR *AAnpan::BlueprintPath = TEXT("/Game/Blueprints/System/Active/Anpan.Anpan");

// 生成.
AAnpan *AAnpan::Spawn(UWorld *pWorld, const AnpanData &Data)
{
	const AnpanItem *pItem = MasterData::GetInstance().GetAnpanMaster().Get(Data.MasterId);

	// 足元の座標から中心の座標に変換する。
	float Z = Data.Z + (BaseRadius * pItem->Scale);
	AAnpan *pAnpan = Util::SpawnFromBlueprint<AAnpan>(pWorld, BlueprintPath, FVector(Data.X, Data.Y, Z), FRotator(0.0f, Data.Rotation, 0.0f));
	pAnpan->Initialize(Data.Hp, Data.MaxHp);
	pAnpan->Uuid = Data.Uuid;
	pAnpan->ScaleRate = pItem->Scale;

	pAnpan->SetActorScale3D(FVector(pItem->Scale, pItem->Scale, pItem->Scale));
	
	return pAnpan;
}

// コンストラクタ
AAnpan::AAnpan(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pController(nullptr)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USphereComponent *pDummyComponent = CreateDefaultSubobject<USphereComponent>("Dummy");
	pDummyComponent->bHiddenInGame = true;
	pDummyComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	RootComponent = pDummyComponent;

	pMeshComponent = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, "MeshComponent");

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshFinder(MeshPath);
	pMeshComponent->SetStaticMesh(MeshFinder.Object);
	pMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	pMeshComponent->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel1);
	pMeshComponent->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	pMeshComponent->SetupAttachment(RootComponent);

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
void AAnpan::Move(float X, float Y,  float Z,int32 Time)
{
	// 足元の座標から中心の座標に変換する。
	Z += (BaseRadius * GetActorScale3D().X);
	pController->Move(X, Y, Z, Time);
}

// 回転.
void AAnpan::Rotate(float Rotation, int32 Time)
{
	pController->Rotate(Rotation, Time);
}

// 停止.
void AAnpan::Stop(float X, float Y, float Z, float Rotation)
{
	pController->Stop(X, Y, Z, Rotation);
}


// 足元の座標を取得.
FVector AAnpan::GetFootPosition() const
{
	FVector Pos = GetActorLocation();
	Pos.Z -= (BaseRadius * GetActorScale3D().X);
	return Pos;
}
