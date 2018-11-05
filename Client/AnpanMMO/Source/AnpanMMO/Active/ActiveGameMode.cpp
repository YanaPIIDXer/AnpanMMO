// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "ActiveGameMode.h"
#include "MMOGameInstance.h"
#include "Character/CharacterBase.h"
#include "Character/Anpan/Anpan.h"
#include "Packet/PacketGameReady.h"
#include "Packet/PacketDamage.h"

// コンストラクタ
AActiveGameMode::AActiveGameMode(const FObjectInitializer &ObjectInitializer) 
	: Super(ObjectInitializer)
{
	AddPacketFunction(PacketID::AnpanList, std::bind(&AnpanManager::OnRecvList, &AnpanMgr, _1));
	AddPacketFunction(PacketID::SpawnAnpan, std::bind(&AnpanManager::OnRecvSpawn, &AnpanMgr, _1));
	AddPacketFunction(PacketID::Damage, std::bind(&AActiveGameMode::OnRecvDamage, this, _1));
}

// 開始時の処理.
void AActiveGameMode::BeginPlay()
{
	Super::BeginPlay();

	AnpanMgr.SetWorld(GetWorld());

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	PacketGameReady Packet;
	pInst->SendPacket(&Packet);
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
