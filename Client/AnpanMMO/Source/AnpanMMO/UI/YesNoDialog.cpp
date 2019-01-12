// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "YesNoDialog.h"
#include "Util.h"

const TCHAR *UYesNoDialog::AssetPath = TEXT("/Game/Blueprints/UI/System/YesNoDialog.YesNoDialog");

// 表示.
UYesNoDialog *UYesNoDialog::Show(UObject *pOuter, const FString &DisplayText, int32 ZOrder)
{
	UYesNoDialog *pDialog = Util::LoadBlueprint<UYesNoDialog>(pOuter, AssetPath);
	check(pDialog != nullptr);

	pDialog->DisplayText = DisplayText;
	pDialog->AddToViewport(ZOrder);
	return pDialog;
}

// コンストラクタ
UYesNoDialog::UYesNoDialog(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// はいが選択された。
void UYesNoDialog::OnSelectedYes()
{
	RemoveFromParent();
	OnYes.Broadcast();
}

// いいえが選択された。
void UYesNoDialog::OnSelectedNo()
{
	RemoveFromParent();
	OnNo.Broadcast();
}
