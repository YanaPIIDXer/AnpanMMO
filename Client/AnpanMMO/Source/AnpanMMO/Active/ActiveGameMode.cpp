// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "ActiveGameMode.h"
#include "MMOGameInstance.h"
#include "Character/CharacterBase.h"
#include "Character/Anpan/Anpan.h"
#include "Active/UI/MainHUD.h"
#include "Level/LevelManager.h"
#include "Character/Player/GameCharacter.h"
#include "Character/Player/GameController.h"
#include "Kismet/GameplayStatics.h"
#include "Master/MasterData.h"
#include "Config.h"
#include "DLC/PakFileManager.h"
#include "UI/SimpleDialog.h"
#include "UI/Menu/GameMenuWidget.h"
#include "UI/Menu/OtherPlayerPopupMenu.h"
#include "UI/Menu/InstanceArea/InstanceAreaTicketMenuWidget.h"
#include "Components/CapsuleComponent.h"
#include "Packet/PacketGameReady.h"
#include "Packet/PacketAreaMove.h"
#include "Packet/PacketDamage.h"
#include "Packet/CharacterType.h"
#include "Packet/PacketAddExp.h"
#include "Packet/PacketLevelUp.h"
#include "Packet/PacketAreaMoveResponse.h"
#include "Packet/PacketPlayerRespawn.h"
#include "Packet/PacketReceiveChat.h"
#include "Packet/PacketPartyKickResult.h"
#include "Packet/PacketPartyInviteResult.h"
#include "Packet/PacketInstanceAreaTicketPublish.h"
#include "Packet/PacketInstanceAreaTicketDiscard.h"
#include "Packet/PacketSpawnInstanceAreaExitPoint.h"

// コンストラクタ
AActiveGameMode::AActiveGameMode(const FObjectInitializer &ObjectInitializer) 
	: Super(ObjectInitializer)
	, pMainHUD(nullptr)
	, pOtherPlayerMenu(nullptr)
	, bInitializedMainHUD(false)
{
	PrimaryActorTick.bCanEverTick = true;

	AddPacketFunction(PacketID::Ping, std::bind(&PingManager::OnRecvPing, &PingMgr, _1));
	AddPacketFunction(PacketID::AreaMove, std::bind(&AActiveGameMode::OnRecvAreaMove, this, _1));
	AddPacketFunction(PacketID::AnpanList, std::bind(&AnpanManager::OnRecvList, &AnpanMgr, _1));
	AddPacketFunction(PacketID::SpawnAnpan, std::bind(&AnpanManager::OnRecvSpawn, &AnpanMgr, _1));
	AddPacketFunction(PacketID::MoveAnpan, std::bind(&AnpanManager::OnRecvMove, &AnpanMgr, _1));
	AddPacketFunction(PacketID::RotateAnpan, std::bind(&AnpanManager::OnRecvRotate, &AnpanMgr, _1));
	AddPacketFunction(PacketID::StopAnpan, std::bind(&AnpanManager::OnRecvStop, &AnpanMgr, _1));
	AddPacketFunction(PacketID::Damage, std::bind(&AActiveGameMode::OnRecvDamage, this, _1));
	AddPacketFunction(PacketID::AddExp, std::bind(&AActiveGameMode::OnRecvAddExp, this, _1));
	AddPacketFunction(PacketID::LevelUp, std::bind(&AActiveGameMode::OnRecvLevelUp, this, _1));
	AddPacketFunction(PacketID::SpawnPlayer, std::bind(&PlayerManager::OnRecvSpawn, &PlayerMgr, _1));
	AddPacketFunction(PacketID::AreaMoveResponse, std::bind(&AActiveGameMode::OnRecvAreaMoveResponse, this, _1));
	AddPacketFunction(PacketID::PlayerList, std::bind(&PlayerManager::OnRecvList, &PlayerMgr, _1));
	AddPacketFunction(PacketID::MovePlayer, std::bind(&PlayerManager::OnRecvMove, &PlayerMgr, _1));
	AddPacketFunction(PacketID::PlayerRespawn, std::bind(&AActiveGameMode::OnRecvRespawn, this, _1));
	AddPacketFunction(PacketID::ExitPlayer, std::bind(&PlayerManager::OnRecvExit, &PlayerMgr, _1));
	AddPacketFunction(PacketID::ReceiveChat, std::bind(&AActiveGameMode::OnRecvChat, this, _1));
	AddPacketFunction(PacketID::PartyCreateResult, std::bind(&PartyInformation::OnRecvCreateResult, &PartyInfo, _1));
	AddPacketFunction(PacketID::PartyDissolutionResult, std::bind(&PartyInformation::OnRecvDissolutionResult, &PartyInfo, _1));
	AddPacketFunction(PacketID::PartyExitResult, std::bind(&PartyInformation::OnRecvExitResult, &PartyInfo, _1));
	AddPacketFunction(PacketID::PartyJoin, std::bind(&PartyInformation::OnRecvJoin, &PartyInfo, _1));
	AddPacketFunction(PacketID::PartyJoinMember, std::bind(&PartyInformation::OnRecvJoinMember, &PartyInfo, _1));
	AddPacketFunction(PacketID::PartyExit, std::bind(&PartyInformation::OnRecvExitMember, &PartyInfo, _1));
	AddPacketFunction(PacketID::PartyDissolution, std::bind(&PartyInformation::OnRecvDissolution, &PartyInfo, _1));
	AddPacketFunction(PacketID::PartyKickResult, std::bind(&AActiveGameMode::OnRecvPartyKickResult, this, _1));
	AddPacketFunction(PacketID::PartyKick, std::bind(&PartyInformation::OnRecvKickMember, &PartyInfo, _1));
	AddPacketFunction(PacketID::PartyInviteResult, std::bind(&AActiveGameMode::OnRecvPartyInviteResult, this, _1));
	AddPacketFunction(PacketID::NoticeList, std::bind(&NoticeManager::OnRecvNoticeList, &NoticeMgr, _1));
	AddPacketFunction(PacketID::ReceiveNotice, std::bind(&NoticeManager::OnRecvNotice, &NoticeMgr, _1));
	AddPacketFunction(PacketID::InstanceAreaTicketPublish, std::bind(&AActiveGameMode::OnRecvInstanceAreaTicketPublish, this, _1));
	AddPacketFunction(PacketID::InstanceAreaTicketDiscard, std::bind(&AActiveGameMode::OnRecvInstanceAreaTicketDiscard, this, _1));
	AddPacketFunction(PacketID::SpawnInstanceAreaExitPoint, std::bind(&AActiveGameMode::OnRecvSpawnInstanceAreaExitPoint, this, _1));
	AddPacketFunction(PacketID::Time, std::bind(&TimeManager::OnRecvTime, &TimeMgr, _1));
	AddPacketFunction(PacketID::TimeChange, std::bind(&TimeManager::OnRecvTimeChange, &TimeMgr, _1));

	pLevelManager = CreateDefaultSubobject<ULevelManager>("LevelManager");
}

// 開始時の処理.
void AActiveGameMode::BeginPlay()
{
	Super::BeginPlay();

	pMainHUD = UMainHUD::Show(this);

	PlayerMgr.SetWorld(GetWorld());
	AnpanMgr.SetWorld(GetWorld());
	WarpPointMgr.SetWorld(GetWorld());
	PartyInfo.SetGameMode(this);
	PingMgr.SetGameMode(this);
	NPCMgr.SetWorld(GetWorld());
	NoticeMgr.OnRecvNoticeDelegate.BindUObject<UMainHUD>(pMainHUD, &UMainHUD::OnRecvNotice);
	pLevelManager->OnLevelLoadFinished.BindUObject<AActiveGameMode>(this, &AActiveGameMode::OnLevelLoadFinished);

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	uint32 AreaId = pInst->GetAreaIdCache();
	StartLevelLoad(AreaId);
}

// 毎フレームの処理.
void AActiveGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bInitializedMainHUD)
	{
		pMainHUD->OnHUDInitialize();
		bInitializedMainHUD = true;
	}

	AnpanMgr.Poll();
	pLevelManager->Poll();
	PingMgr.Poll(DeltaTime);
}

// プレイヤーキャラ追加.
void AActiveGameMode::AddPlayerCharacter(uint32 Uuid, APlayerCharacterBase *pPlayer)
{
	PlayerMgr.Add(Uuid, pPlayer);
}

// マップロード開始.
void AActiveGameMode::StartLevelLoad(uint32 AreaId)
{
	const auto *pItem = MasterData::GetInstance().GetAreaMaster().Get(AreaId);
	check(pItem != nullptr);

	FString LevelName = pItem->LevelName;
	FString PakPath = Config::GetDLCDirectory() + "\\" + LevelName + ".pak";
	if (!PakFileManager::GetInstance().Mount(PakPath))
	{
		UE_LOG(LogTemp, Log, TEXT("%s DLC Mount Failed..."), *LevelName);
		// @TODO:失敗時の対応どうすんのよ？
		return;
	}

	FString LevelPath = "/" + LevelName + "/Levels/" + LevelName + "." + LevelName;
	pLevelManager->Load(LevelPath);
}

// レベルロードが完了した。
void AActiveGameMode::OnLevelLoadFinished()
{
	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	PacketGameReady Packet;
	pInst->SendPacket(&Packet);
}

// メインHUDを表示するかどうかを設定.
void AActiveGameMode::SetHiddenMainHUD(bool bHidden)
{
	auto *pController = Cast<AGameController>(UGameplayStatics::GetPlayerController(this, 0));
	check(pController != nullptr);

	if (bHidden)
	{
		pMainHUD->SetVisibility(ESlateVisibility::Hidden);
		pController->SetVirtualJoystickVisibility(false);
		pController->SetEnableMove(false);
	}
	else
	{
		pMainHUD->SetVisibility(ESlateVisibility::Visible);
		pController->SetVirtualJoystickVisibility(true);
		pController->SetEnableMove(true);
	}
}

// 他人のポップアップメニューを表示.
void AActiveGameMode::ShowOtherPlayerPopupMenu(AOtherPlayerCharacter *pCharacter)
{
	// 一旦消去.
	EraseOtherPlayerPopupMenu();

	pOtherPlayerMenu = UOtherPlayerPopupMenu::Show(this, pCharacter);
}

// 他人のポップアップメニューを消去.
void AActiveGameMode::EraseOtherPlayerPopupMenu()
{
	if (pOtherPlayerMenu == nullptr) { return; }

	pOtherPlayerMenu->RemoveFromParent();
	pOtherPlayerMenu = nullptr;
}

// 天球をセット。
void AActiveGameMode::RegisterSkyControl(ASkyControl *pSky)
{
	TimeMgr.SetSkyControl(pSky);
}


// エリア移動を受信した。
void AActiveGameMode::OnRecvAreaMove(MemoryStreamInterface *pStream)
{
	PacketAreaMove Packet;
	Packet.Serialize(pStream);

	AGameCharacter *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	check(pCharacter != nullptr);

	WarpPointMgr.Spawn(Packet.AreaId);
	NPCMgr.OnMapChanegd(Packet.AreaId);
	
	FVector Pos(Packet.X, Packet.Y, Packet.Z);
	
	// 足元の座標が送られてくるのでキャラの中心に変換。
	Pos.Z += pCharacter->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
	pCharacter->SetActorLocation(Pos);

	AGameController *pController = Cast<AGameController>(UGameplayStatics::GetPlayerController(this, 0));
	check(pController != nullptr);
	pController->SetEnableMove(true);

	pMainHUD->OnRecvMapChangeFinished();
}

// ダメージを受信した。
void AActiveGameMode::OnRecvDamage(MemoryStreamInterface *pStream)
{
	PacketDamage Packet;
	Packet.Serialize(pStream);

	ACharacterBase *pDamageCharacter = nullptr;
	switch (Packet.TargetType)
	{
		case CharacterType::Player:

			pDamageCharacter = PlayerMgr.Get(Packet.TargetUuid);
			break;

		case CharacterType::Enemy:
	
			pDamageCharacter = AnpanMgr.Get(Packet.TargetUuid);
			break;

	}
	check(pDamageCharacter != nullptr);
	pDamageCharacter->ApplyDamage(Packet.DamageValue);
}

// 経験値を受信した。
void AActiveGameMode::OnRecvAddExp(MemoryStreamInterface *pStream)
{
	PacketAddExp Packet;
	Packet.Serialize(pStream);

	auto *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	check(pCharacter != nullptr);
	pCharacter->OnRecvExp(Packet.Exp);
}

// レベルアップを受信した。
void AActiveGameMode::OnRecvLevelUp(MemoryStreamInterface *pStream)
{
	PacketLevelUp Packet;
	Packet.Serialize(pStream);

	auto *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	check(pCharacter != nullptr);
	pCharacter->OnRecvLevelUp(Packet.MaxHp, Packet.Atk, Packet.Def);
	pCharacter->OnRecvExp(Packet.ResultExp);

	pMainHUD->OnLevelUp();
}

// エリア移動結果を受信した。
void AActiveGameMode::OnRecvAreaMoveResponse(MemoryStreamInterface *pStream)
{
	PacketAreaMoveResponse Packet;
	Packet.Serialize(pStream);

	if (Packet.Result != PacketAreaMoveResponse::Success)
	{
		UE_LOG(LogTemp, Log, TEXT("Area Move Failed... ResultCode:%d"), Packet.Result);
		return;
	}

	// 各種マネージャの初期化.
	PlayerMgr.Reset();
	AnpanMgr.Reset();
	WarpPointMgr.Reset();
	NPCMgr.Reset();

	pMainHUD->OnStartMapChange();
}

// リスポンを受信した。
void AActiveGameMode::OnRecvRespawn(MemoryStreamInterface *pStream)
{
	PacketPlayerRespawn Packet;
	Packet.Serialize(pStream);

	auto *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	check(pCharacter != nullptr);
	pCharacter->Respawn();
}

// チャットを受信した。
void AActiveGameMode::OnRecvChat(MemoryStreamInterface *pStream)
{
	PacketReceiveChat Packet;
	Packet.Serialize(pStream);

	FString Name = UTF8_TO_TCHAR(Packet.Name.c_str());
	FString Message = UTF8_TO_TCHAR(Packet.Message.c_str());

	auto *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	check(pCharacter != nullptr);
	bool bIsSelf = (Packet.Uuid == pCharacter->GetStatus().GetUuid());

	pMainHUD->OnRecvChat(Name, Message, bIsSelf);
}

// パーティキック結果を受信した。
void AActiveGameMode::OnRecvPartyKickResult(MemoryStreamInterface *pStream)
{
	PacketPartyKickResult Packet;
	Packet.Serialize(pStream);

	FString DisplayText = "Kick Success.";
	switch (Packet.Result)
	{
		case PacketPartyKickResult::Error:

			DisplayText = "Kick Failed...";
			break;
	}

	USimpleDialog::Show(this, DisplayText);
}

// パーティ勧誘結果を受信した。
void AActiveGameMode::OnRecvPartyInviteResult(MemoryStreamInterface *pStream)
{
	PacketPartyInviteResult Packet;
	Packet.Serialize(pStream);

	FString DisplayMessage = "Party Invite Success!";
	switch (Packet.Result)
	{
		case PacketPartyInviteResult::AlreadyJoinOtherParty:

			DisplayMessage = "Already Joined Other Party...";
			break;

		case PacketPartyInviteResult::Error:

			DisplayMessage = "Party Invite Error...";
			break;

	}

	USimpleDialog::Show(this, DisplayMessage);
}

// インスタンスマップチケット発行を受信した。
void AActiveGameMode::OnRecvInstanceAreaTicketPublish(MemoryStreamInterface *pStream)
{
	PacketInstanceAreaTicketPublish Packet;
	Packet.Serialize(pStream);

	UInstanceAreaTicketMenuWidget::ShowWidget(this, Packet.TicketId);
}

// インスタンスマップチケット破棄を受信した。
void AActiveGameMode::OnRecvInstanceAreaTicketDiscard(MemoryStreamInterface *pStream)
{
	PacketInstanceAreaTicketDiscard Packet;
	Packet.Serialize(pStream);

	USimpleDialog::Show(this, "Instance Area Ticket Discard...");
}

// インスタンスエリア脱出ポイント生成を受信した。
void AActiveGameMode::OnRecvSpawnInstanceAreaExitPoint(MemoryStreamInterface *pStream)
{
	PacketSpawnInstanceAreaExitPoint Packet;
	Packet.Serialize(pStream);

	WarpPointMgr.SpawnFromWarpPointId(Packet.WarpPointId);
}
