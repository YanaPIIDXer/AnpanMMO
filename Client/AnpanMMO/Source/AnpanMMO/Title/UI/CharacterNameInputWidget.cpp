// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "CharacterNameInputWidget.h"
#include "Packet/PacketCreateCharacterRequest.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "Util.h"

const TCHAR *UCharacterNameInputWidget::AssetPath = TEXT("/Game/Blueprints/UI/Title/CharacterNameInput.CharacterNameInput");

// 表示.
UCharacterNameInputWidget *UCharacterNameInputWidget::Show(UObject *pOuter, int32 ZOrder)
{
	UCharacterNameInputWidget *pWidget = Util::LoadBlueprint<UCharacterNameInputWidget>(pOuter, AssetPath);
	check(pWidget != nullptr);

	pWidget->AddToViewport(ZOrder);

	return pWidget;
}

// コンストラクタ
UCharacterNameInputWidget::UCharacterNameInputWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// リクエストパケット送信.
void UCharacterNameInputWidget::SendRequestPacket(const FString &Name, int32 Job)
{
	std::string NameStr = TCHAR_TO_UTF8(*Name);
	PacketCreateCharacterRequest Packet(NameStr, Job);

	auto *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	pInst->SendPacket(&Packet);
}
