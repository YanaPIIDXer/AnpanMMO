// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "TitleGameMode.h"
#include "MMOGameInstance.h"

// コンストラクタ
ATitleGameMode::ATitleGameMode(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// ゲームサーバへの接続.
void ATitleGameMode::ConnectToGameServer()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	if (!pInst->Connect("127.0.0.1", 4424))
	{
		UE_LOG(LogTemp, Log, TEXT("GameServer Connection Failed..."));
	}
}
