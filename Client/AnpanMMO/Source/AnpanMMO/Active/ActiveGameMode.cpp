// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "ActiveGameMode.h"
#include "MMOGameInstance.h"
#include "Character/CharacterBase.h"
#include "Character/Anpan/Anpan.h"
#include "Active/UI/MainHUD.h"
#include "Character/Player/GameCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Packet/PacketGameReady.h"
#include "Packet/PacketDamage.h"
#include "Packet/PacketAddExp.h"
#include "Packet/PacketLevelUp.h"

// コンストラクタ
AActiveGameMode::AActiveGameMode(const FObjectInitializer &ObjectInitializer) 
	: Super(ObjectInitializer)
	, pMainHUD(nullptr)
{
	PrimaryActorTick.bCanEverTick = true;

	AddPacketFunction(PacketID::AnpanList, std::bind(&AnpanManager::OnRecvList, &AnpanMgr, _1));
	AddPacketFunction(PacketID::SpawnAnpan, std::bind(&AnpanManager::OnRecvSpawn, &AnpanMgr, _1));
	AddPacketFunction(PacketID::Damage, std::bind(&AActiveGameMode::OnRecvDamage, this, _1));
	AddPacketFunction(PacketID::AddExp, std::bind(&AActiveGameMode::OnRecvAddExp, this, _1));
	AddPacketFunction(PacketID::LevelUp, std::bind(&AActiveGameMode::OnRecvLevelUp, this, _1));
	AddPacketFunction(PacketID::SpawnPlayer, std::bind(&PlayerManager::OnRecvSpawn, &PlayerMgr, _1));
	AddPacketFunction(PacketID::PlayerList, std::bind(&PlayerManager::OnRecvList, &PlayerMgr, _1));
}

// 開始時の処理.
void AActiveGameMode::BeginPlay()
{
	Super::BeginPlay();

	pMainHUD = UMainHUD::Show(this);

	PlayerMgr.SetWorld(GetWorld());
	AnpanMgr.SetWorld(GetWorld());

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	PacketGameReady Packet;
	pInst->SendPacket(&Packet);
}

// 毎フレームの処理.
void AActiveGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AnpanMgr.Poll();
}

// プレイヤーキャラ追加.
void AActiveGameMode::AddPlayerCharacter(uint32 Uuid, APlayerCharacterBase *pPlayer)
{
	PlayerMgr.Add(Uuid, pPlayer);
}


// ダメージを受信した。
void AActiveGameMode::OnRecvDamage(MemoryStreamInterface *pStream)
{
	PacketDamage Packet;
	Packet.Serialize(pStream);

	ACharacterBase *pDamageCharacter = nullptr;
	switch (Packet.TargetType)
	{
		case PacketDamage::TargetType::Player:

			// @TODO:他プレイヤー周りが出来たら実装。
			break;

		case PacketDamage::TargetType::Enemy:
	
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
}
