// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "CharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "TargetCircle/TargetCircle.h"
#include "Master/MasterData.h"
#include "Skill/SkillRangeDecal.h"

// コンストラクタ
ACharacterBase::ACharacterBase(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, Hp(1)
	, MaxHp(1)
	, pTargetCircle(nullptr)
	, pSkillRangeDecal(nullptr)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	auto *pCollisionComponent = GetCapsuleComponent();
	pCollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	pCollisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);

	auto *pMeshComponent = GetMesh();
	pMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	pMeshComponent->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	pMeshComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	pMeshComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3, ECollisionResponse::ECR_Block);
	pMeshComponent->SetGenerateOverlapEvents(true);
	SetActorEnableCollision(true);

	OnDestroyed.AddDynamic(this, &ACharacterBase::OnDestroy);
}

// 破棄された.
void ACharacterBase::OnDestroy(AActor *pDestroyedActor)
{
	// 何故引数に破棄されたActorが渡されるのか。
	// 他のActorが渡されるケースが存在するのか・・・？
	// とりあえず自分自身以外のActorが渡されたら何もしないようにしておく。
	if (pDestroyedActor != this) { return; }

	DestroySkillRangeDecal();
}

// ダメージを与える。
void ACharacterBase::ApplyDamage(int32 Value)
{
	if (IsDead()) { return; }
	int32 BeforeHp = Hp;
	Hp = FMath::Max<int32>(Hp - Value, 0);

	OnDamaged(BeforeHp, Hp, Value);

	if (IsDead())
	{
		OnDead();
	}
}

// 回復.
void ACharacterBase::Heal(int32 Value)
{
	int32 BeforeHp = Hp;
	Hp = FMath::Min<int32>(Hp + Value, MaxHp);

	OnHeal(BeforeHp, Hp, Value);
}

// ターゲットサークルを生成.
void ACharacterBase::SpawnTargetCircle()
{
	FActorSpawnParameters Param;
	Param.bNoFail = true;
	Param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	pTargetCircle = GetWorld()->SpawnActor<ATargetCircle>(Param);
	check(pTargetCircle != nullptr);

	pTargetCircle->SetCharacter(this);
}

// ターゲットサークルを撤去.
void ACharacterBase::DestroyTargetCircle()
{
	if (pTargetCircle == nullptr) { return; }
	pTargetCircle->Destroy();
	pTargetCircle = nullptr;
}

// スキルキャストを受信した。
void ACharacterBase::OnSkillCast(uint32 SkillId)
{
	// スキルキャスト中の別スキル起動によるキャンセルでリークしてしまう可能性がある。
	// 一旦撤去する。
	DestroySkillRangeDecal();

	const SkillItem *pItem = MasterData::GetInstance().GetSkillMaster().Get(SkillId);
	check(pItem != nullptr);
	if (pItem->RangeType != SkillItem::NORMAL)
	{
		pSkillRangeDecal = ASkillRangeDecal::Spawn(GetWorld(), GetActorLocation(), GetActorRotation(), GetCharacterType(), SkillId);
	}
}

// スキルキャストが完了した。
void ACharacterBase::OnSkillCastFinished()
{
	DestroySkillRangeDecal();
}


// 初期化.
void ACharacterBase::Initialize(int32 InHp, int32 InMaxHp)
{
	Hp = InHp;
	MaxHp = InMaxHp;
}


// スキルの範囲デカールを破棄.
void ACharacterBase::DestroySkillRangeDecal()
{
	if (pSkillRangeDecal != nullptr)
	{
		pSkillRangeDecal->Destroy();
		pSkillRangeDecal = nullptr;
	}
}
