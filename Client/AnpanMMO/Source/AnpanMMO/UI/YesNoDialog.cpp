// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "YesNoDialog.h"
#include "Util.h"

const TCHAR *UYesNoDialog::AssetPath = TEXT("/Game/Blueprints/UI/System/YesNoDialog.YesNoDialog");

// �\��.
UYesNoDialog *UYesNoDialog::Show(UObject *pOuter, const FString &DisplayText, int32 ZOrder)
{
	UYesNoDialog *pDialog = Util::LoadBlueprint<UYesNoDialog>(pOuter, AssetPath);
	check(pDialog != nullptr);

	pDialog->DisplayText = DisplayText;
	pDialog->AddToViewport(ZOrder);
	return pDialog;
}

// �R���X�g���N�^
UYesNoDialog::UYesNoDialog(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// �͂����I�����ꂽ�B
void UYesNoDialog::OnSelectedYes()
{
	RemoveFromParent();
	OnYes.Broadcast();
}

// ���������I�����ꂽ�B
void UYesNoDialog::OnSelectedNo()
{
	RemoveFromParent();
	OnNo.Broadcast();
}
