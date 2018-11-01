// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "TitleGameMode.h"
#include "Title/UI/TitleScreenWidget.h"

// コンストラクタ
ATitleGameMode::ATitleGameMode(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// 開始時の処理.
void ATitleGameMode::BeginPlay()
{
	Super::BeginPlay();

	auto *pWidget = UTitleScreenWidget::Create(this);
	pWidget->AddToViewport();
}
