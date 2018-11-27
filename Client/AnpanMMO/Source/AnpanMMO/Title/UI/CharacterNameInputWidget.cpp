// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "CharacterNameInputWidget.h"
#include "StringPack.h"
#include "Packet/PacketCreateCharacterRequest.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"

// コンストラクタ
UCharacterNameInputWidget::UCharacterNameInputWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// リクエストパケット送信.
void UCharacterNameInputWidget::SendRequestPacket(const FString &Name)
{
	StringPack<32> NamePack(TCHAR_TO_UTF8(*Name));
	PacketCreateCharacterRequest Packet(NamePack);

	auto *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	pInst->SendPacket(&Packet);
}
