// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "MMOGameModeBase.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"

// コンストラクタ
AMMOGameModeBase::AMMOGameModeBase(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pCurrentMenu(nullptr)
{
}

// 開始時の処理.
void AMMOGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	// マウスカーソルを表示する。
	UGameplayStatics::GetPlayerController(this, 0)->bShowMouseCursor = true;

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	pInst->OnRecvPacketDelegate.BindUObject(this, &AMMOGameModeBase::OnRecvPacket);
}


// パケット解析関数追加.
void AMMOGameModeBase::AddPacketFunction(uint8 ID, const PacketFunc &Func)
{
	PacketFunctions[ID] = Func;
}


// パケットを受信した。
void AMMOGameModeBase::OnRecvPacket(uint8 ID, MemoryStreamInterface *pStream)
{
	auto It = PacketFunctions.find(ID);
	if (It != PacketFunctions.end())
	{
		if (!It->second(pStream))
		{
			UE_LOG(LogTemp, Error, TEXT("PacketID:%X Serialize Failed..."), (int32)ID);
		}
	}

	if (pCurrentMenu != nullptr)
	{
		pCurrentMenu->OnRecvPacket(ID);
	}
}
