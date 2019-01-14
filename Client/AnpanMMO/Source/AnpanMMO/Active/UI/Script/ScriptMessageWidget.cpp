// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "ScriptMessageWidget.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Util.h"

const TCHAR *UScriptMessageWidget::AssetPath = TEXT("/Game/Blueprints/UI/Active/Script/MessageWidget.MessageWidget");

// 生成.
UScriptMessageWidget *UScriptMessageWidget::Create(UObject *pOuter)
{
	UScriptMessageWidget *pWidget = Util::LoadBlueprint<UScriptMessageWidget>(pOuter, AssetPath);
	check(pWidget != nullptr);

	return pWidget;
}

// コンストラクタ
UScriptMessageWidget::UScriptMessageWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// 次へ進む。
void UScriptMessageWidget::ToNext()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	pInst->GetScript()->Resume();
}
