// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "AnpanController.h"
#include "Anpan.h"

// コンストラクタ
AAnpanController::AAnpanController(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pAnpan(nullptr)
{
}

// Pawnが紐付けられた。
void AAnpanController::Possess(APawn *aPawn)
{
	Super::Possess(aPawn);

	pAnpan = Cast<AAnpan>(aPawn);
	check(pAnpan != nullptr);
}
