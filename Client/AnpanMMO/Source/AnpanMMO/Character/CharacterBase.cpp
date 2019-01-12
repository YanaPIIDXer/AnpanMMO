// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "CharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "TargetCircle/TargetCircle.h"
#include "Master/MasterData.h"
#include "Skill/SkillRangeDecal.h"

// �R���X�g���N�^
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

// �j�����ꂽ.
void ACharacterBase::OnDestroy(AActor *pDestroyedActor)
{
	// ���̈����ɔj�����ꂽActor���n�����̂��B
	// ����Actor���n�����P�[�X�����݂���̂��E�E�E�H
	// �Ƃ肠�����������g�ȊO��Actor���n���ꂽ�牽�����Ȃ��悤�ɂ��Ă����B
	if (pDestroyedActor != this) { return; }

	DestroySkillRangeDecal();
}

// �_���[�W��^����B
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

// ��.
void ACharacterBase::Heal(int32 Value)
{
	int32 BeforeHp = Hp;
	Hp = FMath::Min<int32>(Hp + Value, MaxHp);

	OnHeal(BeforeHp, Hp, Value);
}

// �^�[�Q�b�g�T�[�N���𐶐�.
void ACharacterBase::SpawnTargetCircle()
{
	FActorSpawnParameters Param;
	Param.bNoFail = true;
	Param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	pTargetCircle = GetWorld()->SpawnActor<ATargetCircle>(Param);
	check(pTargetCircle != nullptr);

	pTargetCircle->SetCharacter(this);
}

// �^�[�Q�b�g�T�[�N����P��.
void ACharacterBase::DestroyTargetCircle()
{
	if (pTargetCircle == nullptr) { return; }
	pTargetCircle->Destroy();
	pTargetCircle = nullptr;
}

// �X�L���L���X�g����M�����B
void ACharacterBase::OnSkillCast(uint32 SkillId)
{
	// �X�L���L���X�g���̕ʃX�L���N���ɂ��L�����Z���Ń��[�N���Ă��܂��\��������B
	// ��U�P������B
	DestroySkillRangeDecal();

	const SkillItem *pItem = MasterData::GetInstance().GetSkillMaster().Get(SkillId);
	check(pItem != nullptr);
	if (pItem->RangeType != SkillItem::NORMAL)
	{
		pSkillRangeDecal = ASkillRangeDecal::Spawn(GetWorld(), GetActorLocation(), GetActorRotation(), GetCharacterType(), SkillId);
	}
}

// �X�L���L���X�g�����������B
void ACharacterBase::OnSkillCastFinished()
{
	DestroySkillRangeDecal();
}


// ������.
void ACharacterBase::Initialize(int32 InHp, int32 InMaxHp)
{
	Hp = InHp;
	MaxHp = InMaxHp;
}


// �X�L���͈̔̓f�J�[����j��.
void ACharacterBase::DestroySkillRangeDecal()
{
	if (pSkillRangeDecal != nullptr)
	{
		pSkillRangeDecal->Destroy();
		pSkillRangeDecal = nullptr;
	}
}
