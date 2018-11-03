// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "TitleGameMode.h"
#include "Title/UI/TitleScreenWidget.h"
#include "MMOGameInstance.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketLogInResult.h"
#include "Packet/PacketCharacterStatus.h"

// コンストラクタ
ATitleGameMode::ATitleGameMode(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// 開始時の処理.
void ATitleGameMode::BeginPlay()
{
	Super::BeginPlay();

	auto *pWidget = UTitleScreenWidget::Create(this);
	pWidget->AddToViewport();

	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	pInst->OnRecvPacketDelegate.BindUObject(this, &ATitleGameMode::OnRecvPacket);
}


// パケットを受信した。
void ATitleGameMode::OnRecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{
	switch (ID)
	{
		case PacketID::LogInResult:

			OnRecvLogInResult(pStream);
			break;

		case PacketID::CharacterStatus:

		{
			// @TODO:ゲーム中GameModeに移動する。
			PacketCharacterStatus Packet;
			Packet.Serialize(pStream);
			UE_LOG(LogTemp, Log, TEXT("HP:%d MaxHP:%d Atk:%d Def:%d Exp:%d"), Packet.Hp, Packet.MaxHp, Packet.Atk, Packet.Def, Packet.Exp);
			break;
		}

	}
}

// ログイン結果を受信した。
void ATitleGameMode::OnRecvLogInResult(MemoryStreamInterface *pStream)
{
	PacketLogInResult Packet;
	Packet.Serialize(pStream);

	OnLogInResult(Packet.Result == PacketLogInResult::Success);
}
