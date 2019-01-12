// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "SkillStateAutoMove.h"
#include "Skill/SkillControl.h"
#include "Character/CharacterBase.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Packet/PacketMovePlayer.h"

// �R���X�g���N�^
SkillStateAutoMove::SkillStateAutoMove(SkillControl *pInControl)
	: SkillStateBase(pInControl)
	, pOwner(nullptr)
	, pTarget(nullptr)
	, Distance(0.0f)
	, bSendMovePacket(false)
{
}

// State�J�n���̏���.
void SkillStateAutoMove::BeginState()
{
	pOwner = GetControl()->GetOwner();
	pTarget = GetControl()->GetTarget();
	Distance = GetControl()->GetSkillData().Distance;
}

// ���t���[���̏���.
void SkillStateAutoMove::Poll()
{
	if (pTarget == nullptr) { return; }		// �^�[�Q�b�g���������B

	FVector TargetVec = (pTarget->GetActorLocation() - pOwner->GetActorLocation());
	if (TargetVec.SizeSquared() > Distance * Distance)
	{
		TargetVec.Z = 0.0f;
		TargetVec.Normalize();
		pOwner->AddMovementInput(TargetVec);
		pOwner->SetActorRotation(TargetVec.Rotation());
		bSendMovePacket = false;
	}
	else if (!bSendMovePacket)
	{
		UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(pOwner.Get()));
		check(pInst != nullptr);

		FVector Pos = pOwner->GetActorLocation();
		PacketMovePlayer Packet(pOwner->GetUuid(), Pos.X, Pos.Y, Pos.Z, pOwner->GetActorRotation().Yaw);
		pInst->SendPacket(&Packet);

		bSendMovePacket = true;
	}
}
