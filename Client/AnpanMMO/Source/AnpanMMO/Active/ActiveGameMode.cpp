// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "ActiveGameMode.h"
#include "MMOGameInstance.h"
#include "Character/CharacterBase.h"
#include "Character/Anpan/Anpan.h"
#include "Packet/PacketGameReady.h"
#include "Packet/PacketDamage.h"

// �R���X�g���N�^
AActiveGameMode::AActiveGameMode(const FObjectInitializer &ObjectInitializer) 
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	AddPacketFunction(PacketID::AnpanList, std::bind(&AnpanManager::OnRecvList, &AnpanMgr, _1));
	AddPacketFunction(PacketID::SpawnAnpan, std::bind(&AnpanManager::OnRecvSpawn, &AnpanMgr, _1));
	AddPacketFunction(PacketID::Damage, std::bind(&AActiveGameMode::OnRecvDamage, this, _1));
}

// �J�n���̏���.
void AActiveGameMode::BeginPlay()
{
	Super::BeginPlay();

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
	int32 BeforeHp = pDamageCharacter->GetHp();
	pDamageCharacter->ApplyDamage(Packet.DamageValue);
	int32 AfterHp = pDamageCharacter->GetHp();
	UE_LOG(LogTemp, Log, TEXT("Damage Hp:%d -> %d"), BeforeHp, AfterHp);
}
