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
#include "UI/Menu/InstanceArea/InstanceAreaTicketMenuWidget.h"
#include "UI/Script/ScriptWidgetRoot.h"
#include "Components/CapsuleComponent.h"
#include "Packet/PacketGameReady.h"
#include "Packet/PacketAreaMove.h"
#include "Packet/PacketDamage.h"
#include "Packet/PacketHeal.h"
#include "Packet/CharacterType.h"
#include "Packet/PacketAddExp.h"
#include "Packet/PacketLevelUp.h"
#include "Packet/PacketAreaMoveResponse.h"
#include "Packet/PacketPlayerRespawn.h"
#include "Packet/PacketSkillCast.h"
#include "Packet/PacketSkillCastFinish.h"
#include "Packet/PacketSkillActivate.h"
#include "Packet/PacketSkillUseFailed.h"
#include "Packet/PacketSkillRecast.h"
#include "Packet/PacketReceiveChat.h"
#include "Packet/PacketPartyKickResult.h"
#include "Packet/PacketPartyInviteResult.h"
#include "Packet/PacketInstanceAreaTicketPublish.h"
#include "Packet/PacketInstanceAreaTicketDiscard.h"
#include "Packet/PacketSpawnInstanceAreaExitPoint.h"
#include "Packet/PacketChangeGold.h"
#include "Packet/PacketSkillTreeOpenResult.h"
#include "Packet/PacketSaveSkillListResponse.h"
#include "Packet/PacketItemAdd.h"
#include "Packet/PacketItemSubtract.h"
#include "Packet/PacketSaveItemShortcutResult.h"
#include "Packet/PacketQuestAccept.h"
#include "Packet/PacketQuestAnpanKill.h"
#include "Packet/PacketQuestStageChange.h"
#include "Packet/PacketQuestClear.h"
#include "Packet/PacketQuestRetireResponse.h"

// コンストラクタ
AActiveGameMode::AActiveGameMode(const FObjectInitializer &ObjectInitializer) 
	: Super(ObjectInitializer)
	, pMainHUD(nullptr)
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
	AddPacketFunction(PacketID::Heal, std::bind(&AActiveGameMode::OnRecvHeal, this, _1));
	AddPacketFunction(PacketID::AddExp, std::bind(&AActiveGameMode::OnRecvAddExp, this, _1));
	AddPacketFunction(PacketID::LevelUp, std::bind(&AActiveGameMode::OnRecvLevelUp, this, _1));
	AddPacketFunction(PacketID::SpawnPlayer, std::bind(&PlayerManager::OnRecvSpawn, &PlayerMgr, _1));
	AddPacketFunction(PacketID::AreaMoveResponse, std::bind(&AActiveGameMode::OnRecvAreaMoveResponse, this, _1));
	AddPacketFunction(PacketID::PlayerList, std::bind(&PlayerManager::OnRecvList, &PlayerMgr, _1));
	AddPacketFunction(PacketID::MovePlayer, std::bind(&PlayerManager::OnRecvMove, &PlayerMgr, _1));
	AddPacketFunction(PacketID::PlayerRespawn, std::bind(&AActiveGameMode::OnRecvRespawn, this, _1));
	AddPacketFunction(PacketID::ExitPlayer, std::bind(&PlayerManager::OnRecvExit, &PlayerMgr, _1));
	AddPacketFunction(PacketID::SkillCast, std::bind(&AActiveGameMode::OnRecvSkillCast, this, _1));
	AddPacketFunction(PacketID::SkillCastFinish, std::bind(&AActiveGameMode::OnRecvSkillCastFinish, this, _1));
	AddPacketFunction(PacketID::SkillActivate, std::bind(&AActiveGameMode::OnRecvSkillActivate, this, _1));
	AddPacketFunction(PacketID::SkillUseFailed, std::bind(&AActiveGameMode::OnRecvSkillUseFailed, this, _1));
	AddPacketFunction(PacketID::SkillRecast, std::bind(&AActiveGameMode::OnRecvSkillRecast, this, _1));
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
	AddPacketFunction(PacketID::ChangeGold, std::bind(&AActiveGameMode::OnRecvChangeGold, this, _1));
	AddPacketFunction(PacketID::SkillTreeOpenResult, std::bind(&AActiveGameMode::OnRecvSkillTreeOpenResult, this, _1));
	AddPacketFunction(PacketID::SaveSkillListResponse, std::bind(&AActiveGameMode::OnRecvSaveSkillListResponse, this, _1));
	AddPacketFunction(PacketID::ItemAdd, std::bind(&AActiveGameMode::OnRecvAddItem, this, _1));
	AddPacketFunction(PacketID::ItemSubtract, std::bind(&AActiveGameMode::OnRecvSubtractItem, this, _1));
	AddPacketFunction(PacketID::SaveItemShortcutResult, std::bind(&AActiveGameMode::OnRecvSaveItemShortcutResult, this, _1));
	AddPacketFunction(PacketID::QuestAccept, std::bind(&AActiveGameMode::OnRecvAcceptQuest, this, _1));
	AddPacketFunction(PacketID::QuestAnpanKill, std::bind(&AActiveGameMode::OnRecvQuestKilledAnpan, this, _1));
	AddPacketFunction(PacketID::QuestStageChange, std::bind(&AActiveGameMode::OnRecvProgressQuest, this, _1));
	AddPacketFunction(PacketID::QuestClear, std::bind(&AActiveGameMode::OnRecvClearQuest, this, _1));
	AddPacketFunction(PacketID::QuestRetireResponse, std::bind(&AActiveGameMode::OnRecvRetireQuestResponse, this, _1));

	pLevelManager = CreateDefaultSubobject<ULevelManager>("LevelManager");
	pScriptWidget = CreateDefaultSubobject<UScriptWidgetRoot>("ScriptWidget");
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
	pScriptWidget->Init();

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	pInst->GetScript()->SetGameMode(this);

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

// 天球をセット。
void AActiveGameMode::RegisterSkyControl(ASkyControl *pSky)
{
	TimeMgr.SetSkyControl(pSky);
}

// スクリプトの実行開始.
void AActiveGameMode::StartScript(const FString &ScriptFileName)
{
	pScriptWidget->Show();

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	pInst->GetScript()->RunScript(ScriptFileName);
}

// スクリプトのメッセージ表示.
void AActiveGameMode::ShowScriptMessage(const FString &Message)
{
	pScriptWidget->ShowMessage(Message);
}

// スクリプトの選択肢を追加。
void AActiveGameMode::AddScriptSelection(const FString &Item)
{
	pScriptWidget->AddSelection(Item);
}

// スクリプトの選択肢を表示.
void AActiveGameMode::ShowScriptSelection()
{
	pScriptWidget->ShowSelection();
}

// スクリプト終了.
void AActiveGameMode::FinishScript()
{
	pScriptWidget->CloseWidget();
}

// キャラから見た前方のターゲットを取得.
AAnpan *AActiveGameMode::FindCenterTarget(float Distance)
{
	return AnpanMgr.FindCenterTarget(Distance);
}


// キャラクタタイプからキャラクタを取得.
ACharacterBase *AActiveGameMode::GetCharacterFromType(uint8 CharacterType, uint32 Uuid)
{
	ACharacterBase *pCharacter = nullptr;
	switch (CharacterType)
	{
		case CharacterType::Player:

			pCharacter = PlayerMgr.Get(Uuid);
			break;

		case CharacterType::Enemy:

			pCharacter = AnpanMgr.Get(Uuid);
			break;
	}
	return pCharacter;
}

// エリア移動を受信した。
bool AActiveGameMode::OnRecvAreaMove(MemoryStreamInterface *pStream)
{
	PacketAreaMove Packet;
	if (!Packet.Serialize(pStream)) { return false; }

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

	return true;
}

// ダメージを受信した。
bool AActiveGameMode::OnRecvDamage(MemoryStreamInterface *pStream)
{
	PacketDamage Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	ACharacterBase *pCharacter = GetCharacterFromType(Packet.TargetType, Packet.TargetUuid);
	check(pCharacter != nullptr);
	pCharacter->ApplyDamage(Packet.DamageValue);

	return true;
}

// 回復を受信した。
bool AActiveGameMode::OnRecvHeal(MemoryStreamInterface *pStream)
{
	PacketHeal Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	ACharacterBase *pCharacter = GetCharacterFromType(Packet.TargetType, Packet.TargetUuid);
	check(pCharacter != nullptr);
	pCharacter->Heal(Packet.HealValue);

	return true;
}

// 経験値を受信した。
bool AActiveGameMode::OnRecvAddExp(MemoryStreamInterface *pStream)
{
	PacketAddExp Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	auto *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	check(pCharacter != nullptr);
	pCharacter->OnRecvExp(Packet.Exp);

	return true;
}

// レベルアップを受信した。
bool AActiveGameMode::OnRecvLevelUp(MemoryStreamInterface *pStream)
{
	PacketLevelUp Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	auto *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	check(pCharacter != nullptr);

	uint32 Prev = pCharacter->GetLevel();

	pCharacter->OnRecvLevelUp(Packet.Level, Packet.MaxHp, Packet.Str, Packet.Def, Packet.Int, Packet.Mnd, Packet.Vit);
	pCharacter->OnRecvExp(Packet.ResultExp);

	pMainHUD->OnLevelUp();

	FString SystemMsg = FString::Printf(TEXT("Level Up! %d -> %d"), Prev, Packet.Level);
	pMainHUD->ShowSystemMessage(SystemMsg);

	return true;
}

// エリア移動結果を受信した。
bool AActiveGameMode::OnRecvAreaMoveResponse(MemoryStreamInterface *pStream)
{
	PacketAreaMoveResponse Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (Packet.Result != PacketAreaMoveResponse::Success)
	{
		UE_LOG(LogTemp, Log, TEXT("Area Move Failed... ResultCode:%d"), Packet.Result);
		return true;
	}

	// 各種マネージャの初期化.
	PlayerMgr.Reset();
	AnpanMgr.Reset();
	WarpPointMgr.Reset();
	NPCMgr.Reset();

	pMainHUD->OnStartMapChange();

	return true;
}

// リスポンを受信した。
bool AActiveGameMode::OnRecvRespawn(MemoryStreamInterface *pStream)
{
	PacketPlayerRespawn Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	auto *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	check(pCharacter != nullptr);
	pCharacter->Respawn();

	return true;
}

// スキルキャストを受信した。
bool AActiveGameMode::OnRecvSkillCast(MemoryStreamInterface *pStream)
{
	PacketSkillCast Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	ACharacterBase *pCharacter = GetCharacterFromType(Packet.CharacterType, Packet.CharacterUuid);
	check(pCharacter != nullptr);

	pCharacter->OnSkillCast(Packet.SkillId);

	return true;
}

// スキルキャスト完了を受信した。
bool AActiveGameMode::OnRecvSkillCastFinish(MemoryStreamInterface *pStream)
{
	PacketSkillCastFinish Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	ACharacterBase *pCharacter = GetCharacterFromType(Packet.CharacterType, Packet.CharacterUuid);
	check(pCharacter != nullptr);

	pCharacter->OnSkillCastFinished();

	return true;
}

// スキル発動を受信した。
bool AActiveGameMode::OnRecvSkillActivate(MemoryStreamInterface *pStream)
{
	PacketSkillActivate Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	ACharacterBase *pCharacter = GetCharacterFromType(Packet.CharacterType, Packet.CharacterUuid);
	check(pCharacter != nullptr);

	pCharacter->OnSkillActivate();

	if (pCharacter == UGameplayStatics::GetPlayerCharacter(this, 0))
	{
		pMainHUD->OnStartRecast(Packet.SkillId);
	}

	return true;
}

// スキル発動失敗を受信した。
bool AActiveGameMode::OnRecvSkillUseFailed(MemoryStreamInterface *pStream)
{
	PacketSkillUseFailed Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	auto *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	check(pCharacter != nullptr);
	pCharacter->OnSkillCancel();

	return true;
}

// スキルのリキャスト完了を受信した。
bool AActiveGameMode::OnRecvSkillRecast(MemoryStreamInterface *pStream)
{
	PacketSkillRecast Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	pMainHUD->OnRecvSkillRecastFinished(Packet.SkillId);

	return true;
}

// チャットを受信した。
bool AActiveGameMode::OnRecvChat(MemoryStreamInterface *pStream)
{
	PacketReceiveChat Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	FString Name = UTF8_TO_TCHAR(Packet.Name.c_str());
	FString Message = UTF8_TO_TCHAR(Packet.Message.c_str());

	auto *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	check(pCharacter != nullptr);
	bool bIsSelf = (Packet.Uuid == pCharacter->GetStatus().GetUuid());

	pMainHUD->OnRecvChat(Name, Message, bIsSelf);

	return true;
}

// パーティキック結果を受信した。
bool AActiveGameMode::OnRecvPartyKickResult(MemoryStreamInterface *pStream)
{
	PacketPartyKickResult Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	FString DisplayText = "Kick Success.";
	switch (Packet.Result)
	{
		case PacketPartyKickResult::Error:

			DisplayText = "Kick Failed...";
			break;
	}

	USimpleDialog::Show(this, DisplayText);

	return true;
}

// パーティ勧誘結果を受信した。
bool AActiveGameMode::OnRecvPartyInviteResult(MemoryStreamInterface *pStream)
{
	PacketPartyInviteResult Packet;
	if (!Packet.Serialize(pStream)) { return false; }

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

	return true;
}

// インスタンスマップチケット発行を受信した。
bool AActiveGameMode::OnRecvInstanceAreaTicketPublish(MemoryStreamInterface *pStream)
{
	PacketInstanceAreaTicketPublish Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	UInstanceAreaTicketMenuWidget::ShowWidget(this, Packet.TicketId);

	return true;
}

// インスタンスマップチケット破棄を受信した。
bool AActiveGameMode::OnRecvInstanceAreaTicketDiscard(MemoryStreamInterface *pStream)
{
	PacketInstanceAreaTicketDiscard Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	USimpleDialog::Show(this, "Instance Area Ticket Discard...");

	return true;
}

// インスタンスエリア脱出ポイント生成を受信した。
bool AActiveGameMode::OnRecvSpawnInstanceAreaExitPoint(MemoryStreamInterface *pStream)
{
	PacketSpawnInstanceAreaExitPoint Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	WarpPointMgr.SpawnFromWarpPointId(Packet.WarpPointId);

	return true;
}

// ゴールド変化を受信した。
bool AActiveGameMode::OnRecvChangeGold(MemoryStreamInterface *pStream)
{
	PacketChangeGold Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	auto *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	check(pCharacter != nullptr);

	uint32 Current = pCharacter->GetGold();
	if (Current < Packet.Gold)
	{
		FString SystemMsg = FString::Printf(TEXT("Add Gold:%d"), Packet.Gold - Current);
		pMainHUD->ShowSystemMessage(SystemMsg);
	}

	pCharacter->SetGold(Packet.Gold);

	return true;
}

// スキルツリー開放結果を受信した。
bool AActiveGameMode::OnRecvSkillTreeOpenResult(MemoryStreamInterface *pStream)
{
	PacketSkillTreeOpenResult Packet;
	Packet.Serialize(pStream);

	FString ErrorMsg = "Error...";
	switch (Packet.Result)
	{
		case PacketSkillTreeOpenResult::AlreadyOpened:

			ErrorMsg = "Already Opened...";
			break;

		case PacketSkillTreeOpenResult::NotEnoughCost:

			ErrorMsg = "Not Enogth Cost...";
			break;

		case PacketSkillTreeOpenResult::NotEnoughLevel:

			ErrorMsg = "Not Enogth Level...";
			break;

		case PacketSkillTreeOpenResult::NotOpenedParent:

			ErrorMsg = "Not Opened Parent...";
			break;
	}

	if (Packet.Result != PacketSkillTreeOpenResult::Success)
	{
		USimpleDialog::Show(this, ErrorMsg, 100);
		return true;
	}

	auto *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	check(pCharacter != nullptr);

	pCharacter->OpenSkillTreeNode(Packet.NodeId);

	USimpleDialog::Show(this, "Node Open!", 100);

	return true;
}

// スキルリスト保存レスポンスを受信した。
bool AActiveGameMode::OnRecvSaveSkillListResponse(MemoryStreamInterface *pStream)
{
	PacketSaveSkillListResponse Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (Packet.Result != PacketSaveSkillListResponse::Success)
	{
		USimpleDialog::Show(this, "Error...", 100);
		return true;
	}

	USimpleDialog::Show(this, "Saved!", 100);

	auto *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	check(pCharacter != nullptr);

	pCharacter->OnRecvSkillList(Packet.SkillId1, Packet.SkillId2, Packet.SkillId3, Packet.SkillId4);

	pMainHUD->OnRecvSkillList(pCharacter->GetStatus().GetSkillList()[0], Packet.SkillId1, Packet.SkillId2, Packet.SkillId3, Packet.SkillId4);

	return true;
}

// アイテム追加を受信した。
bool AActiveGameMode::OnRecvAddItem(MemoryStreamInterface *pStream)
{
	PacketItemAdd Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	auto *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	check(pCharacter != nullptr);

	pCharacter->AddItem(Packet.ItemId, Packet.Count);
	
	const ItemItem *pItem = MasterData::GetInstance().GetItemMaster().Get(Packet.ItemId);
	FString SystemMsg = FString::Printf(TEXT("Add Item:%s * %d"), *pItem->Name, Packet.Count);
	pMainHUD->ShowSystemMessage(SystemMsg);

	return true;
}

// アイテム消滅を受信した。
bool AActiveGameMode::OnRecvSubtractItem(MemoryStreamInterface *pStream)
{
	PacketItemSubtract Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	auto *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	check(pCharacter != nullptr);

	pCharacter->SubtractItem(Packet.ItemId, Packet.Count);

	return true;
}

// アイテムショートカット保存結果を受信した。
bool AActiveGameMode::OnRecvSaveItemShortcutResult(MemoryStreamInterface *pStream)
{
	PacketSaveItemShortcutResult Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (Packet.Result != PacketSaveItemShortcutResult::Success)
	{
		USimpleDialog::Show(this, "Item Shortcut Save Failed...", 100);
		return true;
	}

	auto *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	check(pCharacter != nullptr);

	pCharacter->UpdateItemShortcut(Packet.ItemId1, Packet.ItemId2);

	USimpleDialog::Show(this, "Item Shortcut Saved!", 100);

	return true;
}

// クエスト受注を受信した。
bool AActiveGameMode::OnRecvAcceptQuest(MemoryStreamInterface *pStream)
{
	PacketQuestAccept Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	QuestData Data(Packet.QuestId, 0, 0, QuestData::Active);
	pInst->AddQuestData(Data);

	return true;
}

// クエスト進行を受信した。
bool AActiveGameMode::OnRecvProgressQuest(MemoryStreamInterface *pStream)
{
	PacketQuestStageChange Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	pInst->ProgressQuest(Packet.QuestId, Packet.StageNo);

	return true;
}

// クエストでのアンパン殺害を受信した。
bool AActiveGameMode::OnRecvQuestKilledAnpan(MemoryStreamInterface *pStream)
{
	PacketQuestAnpanKill Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	pInst->QuestKillAnpan(Packet.QuestId);

	return true;
}

// クエストクリアを受信した。
bool AActiveGameMode::OnRecvClearQuest(MemoryStreamInterface *pStream)
{
	PacketQuestClear Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	pInst->ClearQuest(Packet.QuestId);

	return true;
}

// クエスト破棄レスポンスを受信した。
bool AActiveGameMode::OnRecvRetireQuestResponse(MemoryStreamInterface *pStream)
{
	PacketQuestRetireResponse Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (Packet.Result != PacketQuestRetireResponse::Success)
	{
		FString ErrorMsg = "Error...";
		switch (Packet.Result)
		{
			case PacketQuestRetireResponse::MainQuest:

				ErrorMsg = "This is Main Quest...";
				break;
		}

		USimpleDialog::Show(this, ErrorMsg, 100);
		return true;
	}

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	pInst->RetireQuest(Packet.QuestId);

	USimpleDialog::Show(this, "Quest Retire.", 100);

	return true;
}
