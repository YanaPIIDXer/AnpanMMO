// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "MMOGameModeBase.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"

// コンストラクタ
AMMOGameModeBase::AMMOGameModeBase(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
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
void AMMOGameModeBase::AddPacketFunction(PacketID ID, const PacketFunc &Func)
{
	PacketFunctions[ID] = Func;
}


// パケットを受信した。
void AMMOGameModeBase::OnRecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{
	auto It = PacketFunctions.find(ID);
	if (It != PacketFunctions.end())
	{
		It->second(pStream);
	}
}
