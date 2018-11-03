// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "BlueprintFunctions.h"
#include "UI/SimpleDialog.h"

// �P���ȃ_�C�A���O��\��.
USimpleDialog *UBlueprintFunctions::ShowSimpleDialog(UObject *pOuter, const FString &DisplayText)
{
	USimpleDialog *pDialog = USimpleDialog::Show(pOuter, DisplayText);
	return pDialog;
}
