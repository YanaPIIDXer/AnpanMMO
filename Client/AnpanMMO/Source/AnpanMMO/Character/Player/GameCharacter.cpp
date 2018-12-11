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

	Move.Initialize(this, pInst);
}

// 毎フレームの処理.
void AGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move.Poll(DeltaTime);
}

// 経験値を受信した。
void AGameCharacter::OnRecvExp(int32 Exp)
{
	Status.SetExp(Exp);
}

// レベルアップを受信した。
void AGameCharacter::OnRecvLevelUp(int32 MaxHp, int32 Atk, int32 Def)
{
	Status.Set(MaxHp, Atk, Def);
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
	
	ACharacterBase *pTarget = pController->GetCurrentTarget();
	if (pTarget == nullptr) { return true; }		// ターゲットがいない時は自動で決めるので使用可。

	const SkillItem *pItem = MasterData::GetInstance().GetSkillMaster().Get(SkillId);
	check(pItem != nullptr);

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

				// @TODO:前方の敵を自動ターゲット。
				break;

			case SkillItem::HEAL:
			case SkillItem::BUFF:

				// 回復・バフスキルだった場合はとりあえず自分をターゲットに指定。
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
}


// リスポンした。
void AGameCharacter::OnRespawn()
{
	SetHP(Status.GetMaxHp());

	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);
	pGameMode->GetMainHUD()->OnRespawn();
}
