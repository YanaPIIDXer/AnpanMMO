// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "AttachableWidget.h"
#include "Kismet/GameplayStatics.h"

// コンストラクタ
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

// 開始時の処理.
void UAttachableWidget::NativeConstruct()
{
	Super::NativeConstruct();

	pController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	check(pController != nullptr);
}

// 毎フレームの処理.
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
		// ※最初のフレームに限り変な位置に表示される事があるので非表示.
		Visible = ESlateVisibility::Hidden;
	}
	else
	{
		Visible = ESlateVisibility::HitTestInvisible;
	}
	bFirstSkip = false;
}
