// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "ChatWindowWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "Packet/PacketSendChat.h"

// コンストラクタ
UChatWindowWidget::UChatWindowWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// チャット送信.
void UChatWindowWidget::SendChat(EChatType Type, const FString &Message)
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	u8 SendType = 0;
	switch (Type)
	{
		case EChatType::Say:

			SendType = PacketSendChat::Say;
			break;

		case EChatType::Showt:

			SendType = PacketSendChat::Shout;
			break;
	}

	std::string Msg = TCHAR_TO_UTF8(*Message);
	PacketSendChat Packet(SendType, Msg);
	pInst->SendPacket(&Packet);
}
