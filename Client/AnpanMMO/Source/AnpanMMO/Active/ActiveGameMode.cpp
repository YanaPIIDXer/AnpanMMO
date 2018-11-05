// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "ActiveGameMode.h"
#include "MMOGameInstance.h"
#include "Packet/PacketGameReady.h"
#include "Packet/PacketDamage.h"

// �R���X�g���N�^
AActiveGameMode::AActiveGameMode(const FObjectInitializer &ObjectInitializer) 
	: Super(ObjectInitializer)
{
	AddPacketFunction(PacketID::AnpanList, std::bind(&AnpanManager::OnRecvList, &AnpanMgr, std::placeholders::_1));
	AddPacketFunction(PacketID::SpawnAnpan, std::bind(&AnpanManager::OnRecvSpawn, &AnpanMgr, std::placeholders::_1));
	AddPacketFunction(PacketID::Damage, std::bind(&AActiveGameMode::OnRecvDamage, this, std::placeholders::_1));
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


// �_���[�W����M�����B
void AActiveGameMode::OnRecvDamage(MemoryStreamInterface *pStream)
{
	PacketDamage Packet;
	Packet.Serialize(pStream);

}
