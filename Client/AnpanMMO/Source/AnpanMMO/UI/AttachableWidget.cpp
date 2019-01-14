// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "AttachableWidget.h"
#include "Kismet/GameplayStatics.h"

// �R���X�g���N�^
UAttachableWidget::UAttachableWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, Visible(ESlateVisibility::Hidden)
	, DisplayPosition(FVector2D::ZeroVector)
	, pTargetActor(nullptr)
	, pController(nullptr)
	, Offset(FVector::ZeroVector)
	, bFirstSkip(true)
{
}

// �J�n���̏���.
void UAttachableWidget::NativeConstruct()
{
	Super::NativeConstruct();

	pController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	check(pController != nullptr);
}

// ���t���[���̏���.
void UAttachableWidget::NativeTick(const FGeometry &InGeometry, float InDeltaTime)
{
	Super::NativeTick(InGeometry, InDeltaTime);
	if (pTargetActor == nullptr)
	{
		Visible = ESlateVisibility::Hidden;
		return;
	}

	FVector Pos = pTargetActor->GetActorLocation() + Offset;
	bool bResult = pController->ProjectWorldLocationToScreen(Pos, DisplayPosition);
	if (!bResult || bFirstSkip)
	{
		// ���ŏ��̃t���[���Ɍ���ςȈʒu�ɕ\������鎖������̂Ŕ�\��.
		Visible = ESlateVisibility::Hidden;
	}
	else
	{
		Visible = ESlateVisibility::HitTestInvisible;
	}
	bFirstSkip = false;
}
