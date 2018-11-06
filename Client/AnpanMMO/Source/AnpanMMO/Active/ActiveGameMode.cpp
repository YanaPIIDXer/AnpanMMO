// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "ActiveGameMode.h"
#include "MMOGameInstance.h"
#include "Character/CharacterBase.h"
#include "Character/Anpan/Anpan.h"
#include "Active/UI/MainHUD.h"
#include "Packet/PacketGameReady.h"
#include "Packet/PacketDamage.h"
#include "Packet/PacketAddExp.h"
#include "Packet/PacketLevelUp.h"

// �R���X�g���N�^
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
}

// �J�n���̏���.
void AActiveGameMode::BeginPlay()
{
	Super::BeginPlay();

	pMainHUD = UMainHUD::Show(this);

	AnpanMgr.SetWorld(GetWorld());

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	PacketGameReady Packet;
	pInst->SendPacket(&Packet);
}

// ���t���[���̏���.
void AActiveGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AnpanMgr.Poll();
}


// �_���[�W����M�����B
void AActiveGameMode::OnRecvDamage(MemoryStreamInterface *pStream)
{
	PacketDamage Packet;
	Packet.Serialize(pStream);

	ACharacterBase *pDamageCharacter = nullptr;
	switch (Packet.TargetType)
	{
		case PacketDamage::TargetType::Player:

			// @TODO:���v���C���[���肪�o����������B
			break;

		case PacketDamage::TargetType::Enemy:
	
			pDamageCharacter = AnpanMgr.Get(Packet.TargetUuid);
			break;

	}
	check(pDamageCharacter != nullptr);
	pDamageCharacter->ApplyDamage(Packet.DamageValue);
}

// �o���l����M�����B
void AActiveGameMode::OnRecvAddExp(MemoryStreamInterface *pStream)
{
	PacketAddExp Packet;
	Packet.Serialize(pStream);

	UE_LOG(LogTemp, Log, TEXT("AddExp Exp:%d"), Packet.Exp);
}

// ���x���A�b�v����M�����B
void AActiveGameMode::OnRecvLevelUp(MemoryStreamInterface *pStream)
{
	PacketLevelUp Packet;
	Packet.Serialize(pStream);

	UE_LOG(LogTemp, Log, TEXT("Level Up!!"));
	UE_LOG(LogTemp, Log, TEXT("MaxHp:%d Atc:%d Def;%d"), Packet.MaxHp, Packet.Atk, Packet.Def);
}
