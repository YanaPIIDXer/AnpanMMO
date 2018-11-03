// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "SimpleDialog.h"
#include "Util.h"

const TCHAR *USimpleDialog::BlueprintPath = TEXT("/Game/Blueprints/UI/System/SimpleDialog.SimpleDialog");

// 表示.
USimpleDialog *USimpleDialog::Show(UObject *pOuter, const FString &InDisplayText)
{
	USimpleDialog *pDialog = Util::LoadBlueprint<USimpleDialog>(pOuter, BlueprintPath);
	check(pDialog != nullptr);

	pDialog->DisplayText = InDisplayText;
	pDialog->AddToViewport();

	return pDialog;
}

// コンストラクタ
USimpleDialog::USimpleDialog(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// OKボタンが押された。
void USimpleDialog::OnOK()
{
	OnDialogOK.Broadcast();
}
