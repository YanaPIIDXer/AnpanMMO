// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameCharacter.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Engine/World.h"
#include "Character/Anpan/Anpan.h"
#include "MMOGameInstance.h"
#include "Active/ActiveGameMode.h"
#include "Active/UI/MainHUD.h"
#include "Kismet/GameplayStatics.h"
#include "GameController.h"
#include "Master/MasterData.h"
#include "Packet/CharacterType.h"
#include "Packet/PacketSkillUse.h"

// �R���X�g���N�^
AGameCharacter::AGameCharacter(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// �J�n���̏���.
void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	Status = pInst->GetStatusCache();
	Initialize(Status.GetMaxHp(), Status.GetMaxHp());

	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);
	pGameMode->AddPlayerCharacter(Status.GetUuid(), this);

	const TArray<uint32> &SkillList = Status.GetSkillList();
	pGameMode->GetMainHUD()->OnRecvSkillList(SkillList[0], SkillList[1], SkillList[2], SkillList[3], SkillList[4]);

	Move.Initialize(this, pInst);

	Skill.SetOwner(this);
}

// ���t���[���̏���.
void AGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move.Poll(DeltaTime);
	Skill.Poll();
}

// �o���l����M�����B
void AGameCharacter::OnRecvExp(int32 Exp)
{
	Status.SetExp(Exp);
}

// ���x���A�b�v����M�����B
void AGameCharacter::OnRecvLevelUp(uint32 Level, int32 MaxHp, int32 Atk, int32 Def)
{
	Status.Set(Level, MaxHp, Atk, Def);
	UpdateMaxHp(MaxHp);
	OnLevelUp();
}

// �ړ��x�N�g���̎擾.
FVector AGameCharacter::GetMoveVector() const
{
	return GetMovementComponent()->GetLastInputVector();
}

// �X�L�����g�p�\���H
bool AGameCharacter::IsSkillUsable(int32 SkillId) const
{
	AGameController *pController = Cast<AGameController>(Controller);
	check(pController != nullptr);

	const SkillItem *pItem = MasterData::GetInstance().GetSkillMaster().Get(SkillId);
	if (pItem == nullptr) { return false; }

	ACharacterBase *pTarget = pController->GetCurrentTarget();
	if (pTarget == nullptr) { return true; }		// �^�[�Q�b�g�����Ȃ����͎����Ō��߂�̂Ŏg�p�B

	if (pItem->RangeType != SkillItem::NORMAL) { return true; }		// �͈͍U���Ȃ�ⓚ���p�Ŏg�p�B

	bool bUsable = false;
	switch (pItem->SkillType)
	{
		case SkillItem::ATTACK:
		case SkillItem::DEBUFF:

			bUsable = (pTarget->GetCharacterType() == ECharacterType::Anpan);
			break;

		case SkillItem::HEAL:
		case SkillItem::BUFF:

			bUsable = ((pTarget->GetCharacterType() == ECharacterType::Player) || (pTarget->GetCharacterType() == ECharacterType::Other));
			break;
	}

	return bUsable;
}

// �X�L���g�p�B
void AGameCharacter::UseSkill(int32 SkillId)
{
	if (!IsSkillUsable(SkillId)) { return; }

	AGameController *pController = Cast<AGameController>(Controller);
	check(pController != nullptr);

	ACharacterBase *pTarget = pController->GetCurrentTarget();
	const SkillItem *pItem = MasterData::GetInstance().GetSkillMaster().Get(SkillId);
	check(pItem != nullptr);
	if (pItem->RangeType == SkillItem::NORMAL && pTarget == nullptr)
	{
		switch (pItem->SkillType)
		{
			case SkillItem::ATTACK:
			case SkillItem::DEBUFF:

				// �O���̓G�������^�[�Q�b�g�B
				{
					AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
					check(pGameMode != nullptr);
					pTarget = pGameMode->FindCenterTarget(pItem->Distance + 1000.0f);
					if (pTarget == nullptr) { return; }		// �^�[�Q�b�g��������Ȃ������ꍇ�͒��f�B
				}
				break;

			case SkillItem::HEAL:
			case SkillItem::BUFF:

				// �񕜁E�o�t�X�L���������ꍇ�͎������^�[�Q�b�g�Ɏw��B
				pTarget = this;
				break;
		}
	}

	uint8 TargetType = 0;
	uint32 TargetUuid = 0;
	if (pTarget != nullptr)
	{
		TargetType = (pTarget->GetCharacterType() == ECharacterType::Anpan) ? CharacterType::Enemy : CharacterType::Player;
		TargetUuid = pTarget->GetUuid();
	}

	PacketSkillUse Packet(SkillId, TargetType, TargetUuid);
	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	pInst->SendPacket(&Packet);

	Skill.UseSkill(SkillId, pTarget);
}

// �ʏ�U���X�L�����g�p.
void AGameCharacter::UseNormalAttackSkill()
{
	uint32 SkillId = Status.GetSkillList()[0];
	UseSkill(SkillId);
}

// �X�L���L���X�g�����������B
void AGameCharacter::OnSkillCastFinished()
{
	// �͈͍U���̃f�J�[����������N���X�ōs���B
	Super::OnSkillCastFinished();

	Skill.OnCastFinished();
}

// �X�L���̃I�[�g�ړ������������B
void AGameCharacter::OnSkillActivate()
{
	Super::OnSkillActivate();

	Skill.OnActivate();
}

// �X�L���L�����Z��
void AGameCharacter::OnSkillCancel()
{
	Skill.OnCancel();
}

// �X�L���c���[�m�[�h���J��.
void AGameCharacter::OpenSkillTreeNode(uint32 NodeId)
{
	Status.OpenSkillTreeNode(NodeId);
}

// �X�L�����X�g����M�����B
void AGameCharacter::OnRecvSkillList(uint32 SkillId1, uint32 SkillId2, uint32 SkillId3, uint32 SkillId4)
{
	Status.SetSkillList(Status.GetSkillList()[0], SkillId1, SkillId2, SkillId3, SkillId4);
}


// ���X�|�������B
void AGameCharacter::OnRespawn()
{
	SetHP(Status.GetMaxHp());

	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);
	pGameMode->GetMainHUD()->OnRespawn();
}
