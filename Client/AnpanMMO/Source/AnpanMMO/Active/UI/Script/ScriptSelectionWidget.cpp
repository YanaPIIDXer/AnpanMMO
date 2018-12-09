// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "ScriptSelectionWidget.h"
#include "Util.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Packet/PacketNPCTalkSelection.h"

const TCHAR *UScriptSelectionWidget::AssetPath = TEXT("/Game/Blueprints/UI/Active/Script/SelectionWidget.SelectionWidget");

// 生成.
UScriptSelectionWidget *UScriptSelectionWidget::Create(UObject *pOuter)
{
	UScriptSelectionWidget *pWidget = Util::LoadBlueprint<UScriptSelectionWidget>(pOuter, AssetPath);
	check(pWidget != nullptr);

	return pWidget;
}

// コンストラクタ
UScriptSelectionWidget::UScriptSelectionWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// 初期化.
void UScriptSelectionWidget::Init()
{
	InitEvent(Selections);
	Selections.Empty();
}

// 選択肢を追加.
void UScriptSelectionWidget::AddSelection(const FString &Item)
{
	Selections.Add(Item);
}


// 選択.
void UScriptSelectionWidget::Select(int32 Index)
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketNPCTalkSelection Packet(Index);
	pInst->SendPacket(&Packet);

	pInst->GetScript()->OnSelectedSelection(Index);
	Back();
}
