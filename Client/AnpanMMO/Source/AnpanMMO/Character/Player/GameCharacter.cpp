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

// コンストラクタ
AGameCharacter::AGameCharacter(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// 開始時の処理.
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

// 毎フレームの処理.
void AGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move.Poll(DeltaTime);
	Skill.Poll();
}

// 経験値を受信した。
void AGameCharacter::OnRecvExp(int32 Exp)
{
	Status.SetExp(Exp);
}

// レベルアップを受信した。
void AGameCharacter::OnRecvLevelUp(uint32 Level, int32 MaxHp, int32 Atk, int32 Def)
{
	Status.Set(Level, MaxHp, Atk, Def);
	UpdateMaxHp(MaxHp);
	OnLevelUp();
}

// 移動ベクトルの取得.
FVector AGameCharacter::GetMoveVector() const
{
	return GetMovementComponent()->GetLastInputVector();
}

// スキルが使用可能か？
bool AGameCharacter::IsSkillUsable(int32 SkillId) const
{
	AGameController *pController = Cast<AGameController>(Controller);
	check(pController != nullptr);

	const SkillItem *pItem = MasterData::GetInstance().GetSkillMaster().Get(SkillId);
	if (pItem == nullptr) { return false; }

	ACharacterBase *pTarget = pController->GetCurrentTarget();
	if (pTarget == nullptr) { return true; }		// ターゲットがいない時は自動で決めるので使用可。

	if (pItem->RangeType != SkillItem::NORMAL) { return true; }		// 範囲攻撃なら問答無用で使用可。

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

// スキル使用。
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

				// 前方の敵を自動ターゲット。
				{
					AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
					check(pGameMode != nullptr);
					pTarget = pGameMode->FindCenterTarget(pItem->Distance + 1000.0f);
					if (pTarget == nullptr) { return; }		// ターゲットが見つからなかった場合は中断。
				}
				break;

			case SkillItem::HEAL:
			case SkillItem::BUFF:

				// 回復・バフスキルだった場合は自分をターゲットに指定。
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

// 通常攻撃スキルを使用.
void AGameCharacter::UseNormalAttackSkill()
{
	uint32 SkillId = Status.GetSkillList()[0];
	UseSkill(SkillId);
}

// スキルキャストが完了した。
void AGameCharacter::OnSkillCastFinished()
{
	// 範囲攻撃のデカール制御を基底クラスで行う。
	Super::OnSkillCastFinished();

	Skill.OnCastFinished();
}

// スキルのオート移動が完了した。
void AGameCharacter::OnSkillActivate()
{
	Super::OnSkillActivate();

	Skill.OnActivate();
}

// スキルキャンセル
void AGameCharacter::OnSkillCancel()
{
	Skill.OnCancel();
}

// スキルツリーノードを開放.
void AGameCharacter::OpenSkillTreeNode(uint32 NodeId)
{
	Status.OpenSkillTreeNode(NodeId);
}

// スキルリストを受信した。
void AGameCharacter::OnRecvSkillList(uint32 SkillId1, uint32 SkillId2, uint32 SkillId3, uint32 SkillId4)
{
	Status.SetSkillList(Status.GetSkillList()[0], SkillId1, SkillId2, SkillId3, SkillId4);
}


// リスポンした。
void AGameCharacter::OnRespawn()
{
	SetHP(Status.GetMaxHp());

	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);
	pGameMode->GetMainHUD()->OnRespawn();
}
