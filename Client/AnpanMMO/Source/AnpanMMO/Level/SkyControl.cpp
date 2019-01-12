// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "SkyControl.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/LightComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Active/ActiveGameMode.h"
#include "Master/MasterData.h"

const float ASkyControl::ChangeTime = 6.0f;

// コンストラクタ
ASkyControl::ASkyControl(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, bRefleshMaterial(false)
	, bColorsDeterminedBySun(true)
	, SunBrightness(75.0f)
	, CloudSpeed(2.0f)
	, CloudOpacity(1.0f)
	, StarsBrightness(0.1f)
	, SunHeight(0.736771f)
	, HorizonFallOff(3.0f)
	, ZenithColor(0.034046f, 0.109247f, 0.295f, 1.0f)
	, HorizonColor(1.979559f, 2.586644f, 3.0f, 1.0f)
	, CloudColor(0.855778f, 0.91902f, 1.0f, 1.0f)
	, OverallColor(1.0f, 1.0f, 1.0f, 1.0f)
	, ChangeTimer(0.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pSkySphereMesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, "SkySphereMesh");
	ConstructorHelpers::FObjectFinder<UStaticMesh> SkySphereFinder(TEXT("/Engine/EngineSky/SM_SkySphere.SM_SkySphere"));
	pSkySphereMesh->SetStaticMesh(SkySphereFinder.Object);

	ConstructorHelpers::FObjectFinder<UMaterial> SrcMaterialFinder(TEXT("/Engine/EngineSky/M_Sky_Panning_Clouds2.M_Sky_Panning_Clouds2"));
	pSourceMaterial = SrcMaterialFinder.Object;

	ConstructorHelpers::FObjectFinder<UCurveLinearColor> HorizonCurveFinder(TEXT("/Engine/EngineSky/C_Sky_Horizon_Color.C_Sky_Horizon_Color"));
	pHorizonColorCurve = HorizonCurveFinder.Object;

	ConstructorHelpers::FObjectFinder<UCurveLinearColor> ZenithCurveFinder(TEXT("/Engine/EngineSky/C_Sky_Zenith_Color.C_Sky_Zenith_Color"));
	pZenithColorCurve = ZenithCurveFinder.Object;

	ConstructorHelpers::FObjectFinder<UCurveLinearColor> CloudCurveFinder(TEXT("/Engine/EngineSky/C_Sky_Cloud_Color.C_Sky_Cloud_Color"));
	pCloudColorCurve = CloudCurveFinder.Object;

	RootComponent = pSkySphereMesh;
}

// 開始時の処理.
void ASkyControl::BeginPlay()
{
	Super::BeginPlay();

	pSkyMaterial = pSkySphereMesh->CreateDynamicMaterialInstance(0, pSourceMaterial);

	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	// マップ単体で動作させる事も考慮してcheckではなく普通のNULLチェック。
	if (pGameMode != nullptr)
	{
		pGameMode->RegisterSkyControl(this);
	}
}

// 毎フレームの処理.
void ASkyControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	UpdateTime(DeltaTime);
	RefleshMaterial();
}

// マテリアルの更新.
void ASkyControl::RefleshMaterial()
{
	if (!bRefleshMaterial) { return; }
	bRefleshMaterial = false;

	if (pDirectionalLight != nullptr)
	{
		FLinearColor LightDirection = pDirectionalLight->GetActorRotation().Vector();
		pSkyMaterial->SetVectorParameterValue("Light direction", LightDirection);

		FLinearColor SunColor = pDirectionalLight->GetLightComponent()->LightColor;
		pSkyMaterial->SetVectorParameterValue("Sun color", SunColor);

		SunHeight = UKismetMathLibrary::MapRangeUnclamped(pDirectionalLight->GetActorRotation().Pitch, 0.0f, -90.0f, 0.0f, 1.0f);
	}
	else
	{
		FRotator Rot(0.0f, 0.0f, 0.0f);
		Rot.Pitch = UKismetMathLibrary::MapRangeUnclamped(SunHeight, -1.0f, 1.0f, 90.0f, -90.0f);
		Rot.Yaw = GetActorRotation().Yaw;
		FLinearColor LightDirection = Rot.Vector();
		pSkyMaterial->SetVectorParameterValue("Light direction", LightDirection);

		float Alpha = FMath::Clamp<float>(SunHeight + 0.2f, 0.0f, 1.0f);
		FLinearColor SunColor = FMath::Lerp<FLinearColor>(FLinearColor(1.0f, 0.221f, 0.04f, 1.0f), FLinearColor(0.954f, 0.901f, 0.74412f, 1.0f), Alpha);
		pSkyMaterial->SetVectorParameterValue("Sun color", SunColor);
	}

	if (bColorsDeterminedBySun)
	{
		FLinearColor Color = pHorizonColorCurve->GetClampedLinearColorValue(SunHeight);
		pSkyMaterial->SetVectorParameterValue("Horizon color", Color);

		Color = pZenithColorCurve->GetClampedLinearColorValue(SunHeight);
		pSkyMaterial->SetVectorParameterValue("Zenith color", Color);

		Color = pCloudColorCurve->GetClampedLinearColorValue(SunHeight);
		pSkyMaterial->SetVectorParameterValue("Cloud color", Color);

		float FallOff = FMath::Lerp<float>(3.0f, 7.0f, FMath::Abs<float>(SunHeight));
		pSkyMaterial->SetScalarParameterValue("Horizon falloff", FallOff);
	}
	else
	{
		pSkyMaterial->SetVectorParameterValue("Horizon color", HorizonColor);
		pSkyMaterial->SetVectorParameterValue("Zenith color", ZenithColor);
		pSkyMaterial->SetVectorParameterValue("Overall color", OverallColor);
		pSkyMaterial->SetVectorParameterValue("Cloud color", CloudColor);
		pSkyMaterial->SetScalarParameterValue("Horizon falloff", HorizonFallOff);
	}

	pSkyMaterial->SetScalarParameterValue("Cloud speed", CloudSpeed);
	pSkyMaterial->SetScalarParameterValue("Sun brightness", SunBrightness);
	float Height = UKismetMathLibrary::SelectFloat(FMath::Abs<float>(SunHeight), 0.0f, (SunHeight < 0.0f));
	pSkyMaterial->SetScalarParameterValue("Sun height", Height);
	pSkyMaterial->SetScalarParameterValue("Cloud opacity", CloudOpacity);
	pSkyMaterial->SetScalarParameterValue("Stars brightness", StarsBrightness);
}

// 太陽の方向を更新.
void ASkyControl::UpdateSunDirection()
{
	if (pDirectionalLight == nullptr) { return; }

	FLinearColor LightDirection = pDirectionalLight->GetActorRotation().Vector();
	pSkyMaterial->SetVectorParameterValue("Light direction", LightDirection);

	FLinearColor SunColor = pDirectionalLight->GetLightComponent()->LightColor;
	pSkyMaterial->SetVectorParameterValue("Sun color", SunColor);

	SunHeight = UKismetMathLibrary::MapRangeUnclamped(pDirectionalLight->GetActorRotation().Pitch, 0.0f, -90.0f, 0.0f, 1.0f);

	FLinearColor Color = pHorizonColorCurve->GetClampedLinearColorValue(SunHeight);
	pSkyMaterial->SetVectorParameterValue("Horizon color", Color);

	Color = pZenithColorCurve->GetClampedLinearColorValue(SunHeight);
	pSkyMaterial->SetVectorParameterValue("Zenith color", Color);

	Color = pCloudColorCurve->GetClampedLinearColorValue(SunHeight);
	pSkyMaterial->SetVectorParameterValue("Cloud color", Color);

	float FallOff = FMath::Lerp<float>(3.0f, 8.0f, FMath::Abs<float>(SunHeight));
	pSkyMaterial->SetScalarParameterValue("Horizon falloff", FallOff);

	float Height = UKismetMathLibrary::SelectFloat(FMath::Abs<float>(SunHeight), 0.0f, (SunHeight < 0.0f));
	pSkyMaterial->SetScalarParameterValue("Sun height", Height);
}

// 時間をセット。
void ASkyControl::SetTime(uint32 MasterId)
{
	const TimeInfoItem *pItem = MasterData::GetInstance().GetTimeInfoMaster().Get(MasterId);
	PrevLightAngle = pItem->LightAngle;
	NextLightAngle = pItem->LightAngle;
	if (pDirectionalLight != nullptr)
	{
		pDirectionalLight->SetActorRotation(FRotator(pItem->LightAngle, 0.0f, 0.0f));
	}
	PrevCloudSpeed = pItem->CloudSpeed;
	NextCloudSpeed = pItem->CloudSpeed;
	CloudSpeed = pItem->CloudSpeed;
	PrevCloudOpacity = pItem->CloudOpacity;
	NextCloudOpacity = pItem->CloudOpacity;
	CloudOpacity = pItem->CloudOpacity;
	PrevStarBrightness = pItem->StarsBrightness;
	NextStarBrightness = pItem->StarsBrightness;
	StarsBrightness = pItem->StarsBrightness;

	ChangeTimer = 0.0f;
	bRefleshMaterial = true;
}

// 時間を変更.
void ASkyControl::TimeChange(uint32 MasterId)
{
	const TimeInfoItem *pItem = MasterData::GetInstance().GetTimeInfoMaster().Get(MasterId);
	PrevLightAngle = NextLightAngle;
	NextLightAngle = pItem->LightAngle;
	PrevCloudSpeed = NextCloudSpeed;
	NextCloudSpeed = pItem->CloudSpeed;
	PrevCloudOpacity = NextCloudOpacity;
	NextCloudOpacity = pItem->CloudOpacity;
	PrevStarBrightness = NextStarBrightness;
	NextStarBrightness = pItem->StarsBrightness;

	ChangeTimer = ChangeTime;
}


// 時間を更新.
void ASkyControl::UpdateTime(float DeltaTime)
{
	if (ChangeTimer <= 0.0f) { return; }

	ChangeTimer = FMath::Max<float>(ChangeTimer - DeltaTime, 0.0f);
	float Rate = 1.0f - (ChangeTimer / ChangeTime);

	if (pDirectionalLight != nullptr)
	{
		pDirectionalLight->SetActorRotation(FRotator(FMath::Lerp<float>(PrevLightAngle, NextLightAngle, Rate), 0.0f, 0.0f));
	}
	CloudSpeed = FMath::Lerp(PrevCloudSpeed, NextCloudSpeed, Rate);
	CloudOpacity = FMath::Lerp(PrevCloudOpacity, NextCloudOpacity, Rate);
	StarsBrightness = FMath::Lerp(PrevStarBrightness, NextStarBrightness, Rate);
	bRefleshMaterial = true;
}
