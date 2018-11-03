// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "BlueprintFunctions.h"
#include "UI/SimpleDialog.h"

// 単純なダイアログを表示.
USimpleDialog *UBlueprintFunctions::ShowSimpleDialog(UObject *pOuter, const FString &DisplayText)
{
	USimpleDialog *pDialog = USimpleDialog::Show(pOuter, DisplayText);
	return pDialog;
}
