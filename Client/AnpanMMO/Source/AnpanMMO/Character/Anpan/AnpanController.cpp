// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "AnpanController.h"
#include "Anpan.h"

// �R���X�g���N�^
AAnpanController::AAnpanController(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pAnpan(nullptr)
{
}

// Pawn���R�t����ꂽ�B
void AAnpanController::Possess(APawn *aPawn)
{
	Super::Possess(aPawn);

	pAnpan = Cast<AAnpan>(aPawn);
	check(pAnpan != nullptr);
}
