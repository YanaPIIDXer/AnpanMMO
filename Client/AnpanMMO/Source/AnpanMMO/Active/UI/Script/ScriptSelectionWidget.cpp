// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "ScriptSelectionWidget.h"
#include "Util.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Packet/PacketNPCTalkSelection.h"

const TCHAR *UScriptSelectionWidget::AssetPath = TEXT("/Game/Blueprints/UI/Active/Script/SelectionWidget.SelectionWidget");

// ����.
UScriptSelectionWidget *UScriptSelectionWidget::Create(UObject *pOuter)
{
	UScriptSelectionWidget *pWidget = Util::LoadBlueprint<UScriptSelectionWidget>(pOuter, AssetPath);
	check(pWidget != nullptr);

	return pWidget;
}

// �R���X�g���N�^
UScriptSelectionWidget::UScriptSelectionWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// ������.
void UScriptSelectionWidget::Init()
{
	InitEvent(Selections);
	Selections.Empty();
}

// �I������ǉ�.
void UScriptSelectionWidget::AddSelection(const FString &Item)
{
	Selections.Add(Item);
}


// �I��.
void UScriptSelectionWidget::Select(int32 Index)
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketNPCTalkSelection Packet(Index);
	pInst->SendPacket(&Packet);

	pInst->GetScript()->OnSelectedSelection(Index);
	Back();
}
