// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "SimpleDialog.h"
#include "Util.h"

const TCHAR *USimpleDialog::BlueprintPath = TEXT("/Game/Blueprints/UI/System/SimpleDialog.SimpleDialog");

// �\��.
USimpleDialog *USimpleDialog::Show(UObject *pOuter, const FString &InDisplayText, int32 ZOrder)
{
	USimpleDialog *pDialog = Util::LoadBlueprint<USimpleDialog>(pOuter, BlueprintPath);
	check(pDialog != nullptr);

	pDialog->DisplayText = InDisplayText;
	pDialog->AddToViewport(ZOrder);

	return pDialog;
}

// �R���X�g���N�^
USimpleDialog::USimpleDialog(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// OK�{�^���������ꂽ�B
void USimpleDialog::OnOK()
{
	OnDialogOK.Broadcast();
}
