// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "TitleGameMode.h"
#include "Title/UI/TitleScreenWidget.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "UI/SimpleDialog.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketLogInResult.h"
#include "Packet/PacketCharacterStatus.h"

// コンストラクタ
ATitleGameMode::ATitleGameMode(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pScreenWidget(nullptr)
{
	AddPacketFunction(PacketID::LogInResult, std::bind(&ATitleGameMode::OnRecvLogInResult, this, _1));
	AddPacketFunction(PacketID::CharacterStatus, std::bind(&ATitleGameMode::OnRecvCharacterStatus, this, _1));
}

// 開始時の処理.
void ATitleGameMode::BeginPlay()
{
	Super::BeginPlay();

	pScreenWidget = UTitleScreenWidget::Show(this);
	pScreenWidget->OnConnect.BindUObject(this, &ATitleGameMode::OnConnectResult);
	pScreenWidget->OnReadyToGame.BindUObject(this, &ATitleGameMode::OnReadyToGame);
}


// 接続コールバック
void ATitleGameMode::OnConnectResult(bool bConnected)
{
	if (!bConnected)
	{
		// ↓何故か日本語が正しく表示されない・・・
		//USimpleDialog::Show(this, "接続に失敗しました。");
		USimpleDialog::Show(this, "Connection Failed...");
	}
}

// ログイン結果を受信した。
void ATitleGameMode::OnRecvLogInResult(MemoryStreamInterface *pStream)
{
	PacketLogInResult Packet;
	Packet.Serialize(pStream);

	bool bResult = (Packet.Result == PacketLogInResult::Success);
	OnLogInResult(bResult);

	if (bResult)
	{
		pScreenWidget->StartFade();
	}
}

// キャラクタステータスを受信した。
void ATitleGameMode::OnRecvCharacterStatus(MemoryStreamInterface *pStream)
{
	PacketCharacterStatus Packet;
	Packet.Serialize(pStream);
	UE_LOG(LogTemp, Log, TEXT("HP:%d MaxHP:%d Atk:%d Def:%d Exp:%d"), Packet.Hp, Packet.MaxHp, Packet.Atk, Packet.Def, Packet.Exp);
}

// ゲーム画面に進む準備が出来た。
void ATitleGameMode::OnReadyToGame()
{
	UGameplayStatics::OpenLevel(this, "Active");
}
