// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "SkillRangeDecal.h"
#include "Master/MasterData.h"
#include "Engine/World.h"
#include "Components/DecalComponent.h"
#include "Classes/Materials/Material.h"
#include "Classes/Materials/MaterialInstanceDynamic.h"

const TCHAR *ASkillRangeDecal::CircleMaterialPath = TEXT("/Game/Resources/Decal/CircleMaterial.CircleMaterial");
const TCHAR *ASkillRangeDecal::BoxMaterialPath = TEXT("/Game/Resources/Decal/BoxMaterial.BoxMaterial");
const FName ASkillRangeDecal::ColorParamName = TEXT("DecalColor");
const FName ASkillRangeDecal::AlphaParamName = TEXT("DecalAlpha");
const FLinearColor ASkillRangeDecal::AttackColor = FLinearColor(0.0f, 0.0f, 1.0f, 1.0f);
const FLinearColor ASkillRangeDecal::HealColor = FLinearColor(0.0f, 1.0f, 0.0f, 1.0f);
const FLinearColor ASkillRangeDecal::EnemyAttackColor = FLinearColor(1.0f, 0.0f, 0.0f, 1.0f);
const FLinearColor ASkillRangeDecal::EnemyHealColor = FLinearColor(1.0f, 1.0f, 0.0f, 1.0f);
const float ASkillRangeDecal::ScaleAnimationTime = 0.3f;

// Spawn
ASkillRangeDecal *ASkillRangeDecal::Spawn(UWorld *pWorld, const FVector &CharacterPos, const FRotator &CharacterRot, ECharacterType CharacterType, uint32 SkillId)
{
	FActorSpawnParameters Param;
	Param.bNoFail = true;
	Param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	ASkillRangeDecal * pDecal = pWorld->SpawnActor<ASkillRangeDecal>(CharacterPos, CharacterRot, Param);
	check(pDecal != nullptr);

	pDecal->Setup(CharacterType, SkillId);
	return pDecal;
}

// コンストラクタ
ASkillRangeDecal::ASkillRangeDecal(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pMaterial(nullptr)
	, Color(FLinearColor::White)
	, CurrentWidth(0.1f)
	, CurrentHeight(0.1f)
	, DecalWidth(1.0f)
	, DecalHeight(1.0f)
	, ElapsedTime(0.0f)
	, Alpha(0.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pDecalComponent = CreateDefaultSubobject<UDecalComponent>("DecalCompoennt");
	pDecalComponent->DecalSize = FVector(1000.0f, 100.0f, 100.0f);
	pDecalComponent->FadeScreenSize = 0.01f;
	RootComponent = pDecalComponent;
}

// 毎フレームの処理.
void ASkillRangeDecal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// スケーリングアニメーション
	ElapsedTime = FMath::Min(ElapsedTime + DeltaTime, ScaleAnimationTime);
	float Rate = ElapsedTime / ScaleAnimationTime;
	CurrentWidth = DecalWidth * Rate;
	CurrentHeight = DecalHeight * Rate;
	SetActorScale3D(FVector(1.0f, CurrentWidth * 0.01f, CurrentHeight * 0.01f));

	// αアニメーション
	Alpha += DeltaTime;
	pMaterial->SetScalarParameterValue(AlphaParamName, FMath::Sin(Alpha * 2.0f) * 1.5f + 0.5f);
}


// セットアップ
void ASkillRangeDecal::Setup(ECharacterType CharacterType, uint32 SkillId)
{
	const SkillItem *pItem = MasterData::GetInstance().GetSkillMaster().Get(SkillId);
	check(pItem != nullptr);

	UMaterial *pSourceMaterial = nullptr;

	switch (pItem->RangeType)
	{
		case SkillItem::RANGE_BOX:

			pSourceMaterial = LoadObject<UMaterial>(this, BoxMaterialPath, BoxMaterialPath);
			break;

		case SkillItem::RANGE_CIRCLE:

			pSourceMaterial = LoadObject<UMaterial>(this, CircleMaterialPath, CircleMaterialPath);
			break;
	}

	pMaterial = UMaterialInstanceDynamic::Create(pSourceMaterial, this);
	switch (CharacterType)
	{
		case ECharacterType::Player:
		case ECharacterType::Other:

			switch (pItem->SkillType)
			{
				case SkillItem::ATTACK:
				case SkillItem::DEBUFF:

					Color = AttackColor;
					break;

				case SkillItem::HEAL:
				case SkillItem::BUFF:

					Color = HealColor;
					break;
			}
			break;

		case ECharacterType::Anpan:

			switch (pItem->SkillType)
			{
				case SkillItem::ATTACK:
				case SkillItem::DEBUFF:

					Color = EnemyAttackColor;
					break;

				case SkillItem::HEAL:
				case SkillItem::BUFF:

					Color = EnemyHealColor;
					break;
			}
			break;
	}

	pMaterial->SetVectorParameterValue(ColorParamName, Color);
	pDecalComponent->SetMaterial(0, pMaterial);

	FVector CenterVec = GetActorRotation().Vector();
	CenterVec *= pItem->Distance;
	FVector Pos = GetActorLocation();
	Pos += CenterVec;
	SetActorLocation(Pos);

	FRotator Rot = GetActorRotation();
	Rot.Pitch -= 90.0f;
	SetActorRotation(Rot);

	DecalWidth = pItem->RangeX;
	if (pItem->RangeType == SkillItem::RANGE_BOX)
	{
		DecalHeight = pItem->RangeY;
	}
	else
	{
		DecalHeight = pItem->RangeX;
	}

	SetActorScale3D(FVector(1.0f, CurrentWidth * 0.01f, CurrentHeight * 0.01f));
}
