// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "TitleGameMode.h"
#include "Config.h"
#include "Packet/PacketLogInRequest.h"
#include "IdManager.h"
#include "Title/UI/TitleScreenWidget.h"
#include "Title/UI/CharacterNameInputWidget.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "UI/SimpleDialog.h"
#include "Master/MasterData.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketLogInResult.h"
#include "Packet/PacketCreateCharacterResult.h"
#include "Packet/PacketCharacterStatus.h"
#include "Packet/PacketSkillList.h"
#include "Packet/PacketSkillTreeData.h"
#include "Packet/PacketItemList.h"
#include "Packet/PacketItemShortcut.h"
#include "Packet/PacketScriptFlag.h"
#include "Packet/PacketQuestData.h"

// コンストラクタ
ATitleGameMode::ATitleGameMode(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pScreenWidget(nullptr)
	, pNameInputWidget(nullptr)
{
	AddPacketFunction(PacketID::LogInResult, std::bind(&ATitleGameMode::OnRecvLogInResult, this, _1));
	AddPacketFunction(PacketID::CreateCharacterResult, std::bind(&ATitleGameMode::OnRecvCreateCharacterResult, this, _1));
	AddPacketFunction(PacketID::CharacterStatus, std::bind(&ATitleGameMode::OnRecvCharacterStatus, this, _1));
	AddPacketFunction(PacketID::SkillList, std::bind(&ATitleGameMode::OnRecvSkillList, this, _1));
	AddPacketFunction(PacketID::SkillTreeData, std::bind(&ATitleGameMode::OnRecvSkillTreeData, this, _1));
	AddPacketFunction(PacketID::ItemList, std::bind(&ATitleGameMode::OnRecvItemList, this, _1));
	AddPacketFunction(PacketID::ItemShortcut, std::bind(&ATitleGameMode::OnRecvItemShortcut, this, _1));
	AddPacketFunction(PacketID::ScriptFlag, std::bind(&ATitleGameMode::OnRecvScriptFlag, this, _1));
	AddPacketFunction(PacketID::QuestData, std::bind(&ATitleGameMode::OnRecvQuestData, this, _1));
}

// 開始時の処理.
void ATitleGameMode::BeginPlay()
{
	Super::BeginPlay();

	auto *pController = UGameplayStatics::GetPlayerController(this, 0);
	pController->ConsoleCommand("r.SetRes 640x480w");
	pController->SetVirtualJoystickVisibility(false);

	pScreenWidget = UTitleScreenWidget::Show(this);
	pScreenWidget->OnConnect.BindUObject(this, &ATitleGameMode::OnConnectResult);
	pScreenWidget->OnReadyToGame.BindUObject(this, &ATitleGameMode::OnReadyToGame);
}

// ログインリクエストを送信.
void ATitleGameMode::SendLogInRequest()
{
	std::string FilePath = TCHAR_TO_UTF8(*Config::GetIdFilePath());
	IdManager IdMgr(FilePath);
	std::string Id = IdMgr.GetId();
	PacketLogInRequest Packet(Id);

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	pInst->SendPacket(&Packet);
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

	if (Packet.Result == PacketLogInResult::NoCharacter)
	{
		pNameInputWidget = UCharacterNameInputWidget::Show(this, 1);
		return;
	}

	bool bResult = (Packet.Result == PacketLogInResult::Success);
	OnLogInResult(bResult);

	if (bResult)
	{
		MasterData::GetInstance().Load();
		pScreenWidget->StartFade();
	}
	else
	{
		pScreenWidget->OnFailedLogIn();
	}

	// @TODO:暫定処理.
	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	pInst->SetAreaIdCache(Packet.LastAreaId);
}

// キャラクタ作成結果を受信した。
void ATitleGameMode::OnRecvCreateCharacterResult(MemoryStreamInterface *pStream)
{
	PacketCreateCharacterResult Packet;
	Packet.Serialize(pStream);

	switch (Packet.Result)
	{
		case PacketCreateCharacterResult::Success:

			// 名前入力Widgetを消す。
			pNameInputWidget->RemoveFromParent();
			pNameInputWidget = nullptr;

			// 改めてログイン要求.
			SendLogInRequest();
			break;

		case PacketCreateCharacterResult::EmptyName:

			USimpleDialog::Show(this, TEXT("Empty Name..."), 2);
			break;

		case PacketCreateCharacterResult::TooLongName:

			USimpleDialog::Show(this, TEXT("Too Long Name..."), 2);
			break;

		case PacketCreateCharacterResult::Error:

			USimpleDialog::Show(this, TEXT("Fatal Error..."), 2);
			break;
	}
}

// キャラクタステータスを受信した。
void ATitleGameMode::OnRecvCharacterStatus(MemoryStreamInterface *pStream)
{
	PacketCharacterStatus Packet;
	Packet.Serialize(pStream);

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	FString NameStr = UTF8_TO_TCHAR(Packet.Name.c_str());
	pInst->OnRecvStatus(Packet.Uuid, NameStr, Packet.Job, Packet.Level, Packet.MaxHp, Packet.Atk, Packet.Def, Packet.Exp, Packet.Gold);
}

// スキルリストを受信した。
void ATitleGameMode::OnRecvSkillList(MemoryStreamInterface *pStream)
{
	PacketSkillList Packet;
	Packet.Serialize(pStream);

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	pInst->OnRecvSkillList(Packet.NormalAttack, Packet.Skill1, Packet.Skill2, Packet.Skill3, Packet.Skill4);
}

// スキルツリーデータを受信した。
void ATitleGameMode::OnRecvSkillTreeData(MemoryStreamInterface *pStream)
{
	PacketSkillTreeData Packet;
	Packet.Serialize(pStream);

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	pInst->OnRecvSkillTreeData(Packet.Nodes);
}

// アイテムリストを受信した。
void ATitleGameMode::OnRecvItemList(MemoryStreamInterface *pStream)
{
	PacketItemList Packet;
	Packet.Serialize(pStream);

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	pInst->OnRecvItemList(Packet.Items);
}

// アイテムショートカットを受信した。
void ATitleGameMode::OnRecvItemShortcut(MemoryStreamInterface *pStream)
{
	PacketItemShortcut Packet;
	Packet.Serialize(pStream);

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	pInst->OnRecvItemShortcht(Packet.ItemId1, Packet.ItemId2);
}

// スクリプトフラグを受信した。
void ATitleGameMode::OnRecvScriptFlag(MemoryStreamInterface *pStream)
{
	PacketScriptFlag Packet;
	Packet.Serialize(pStream);

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	pInst->GetScript()->ConvertFlagFromBitFields(Packet.BitField1, Packet.BitField2, Packet.BitField3);
}

// クエストデータを受信した。
void ATitleGameMode::OnRecvQuestData(MemoryStreamInterface *pStream)
{
	PacketQuestData Packet;
	Packet.Serialize(pStream);

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	for (int32 i = 0; i < Packet.Quests.GetCurrentSize(); i++)
	{
		pInst->AddQuestData(Packet.Quests[i]);
	}
}

// ゲーム画面に進む準備が出来た。
void ATitleGameMode::OnReadyToGame()
{
	UGameplayStatics::OpenLevel(this, "Active");
}
