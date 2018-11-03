// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "TitleGameMode.h"
#include "Title/UI/TitleScreenWidget.h"
#include "MMOGameInstance.h"
#include "UI/SimpleDialog.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketLogInResult.h"
#include "Packet/PacketCharacterStatus.h"

// �R���X�g���N�^
ATitleGameMode::ATitleGameMode(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// �J�n���̏���.
void ATitleGameMode::BeginPlay()
{
	Super::BeginPlay();

	auto *pWidget = UTitleScreenWidget::Show(this);
	pWidget->OnConnect.BindUObject(this, &ATitleGameMode::OnConnectResult);
	
	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	pInst->OnRecvPacketDelegate.BindUObject(this, &ATitleGameMode::OnRecvPacket);
}


// �ڑ��R�[���o�b�N
void ATitleGameMode::OnConnectResult(bool bConnected)
{
	if (!bConnected)
	{
		// �����̂����{�ꂪ�������\������Ȃ��E�E�E
		//USimpleDialog::Show(this, "�ڑ��Ɏ��s���܂����B");
		USimpleDialog::Show(this, "Connection Failed...");
	}
}

// �p�P�b�g����M�����B
void ATitleGameMode::OnRecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{
	switch (ID)
	{
		case PacketID::LogInResult:

			OnRecvLogInResult(pStream);
			break;

		case PacketID::CharacterStatus:

		{
			// @TODO:�Q�[����GameMode�Ɉړ�����B
			PacketCharacterStatus Packet;
			Packet.Serialize(pStream);
			UE_LOG(LogTemp, Log, TEXT("HP:%d MaxHP:%d Atk:%d Def:%d Exp:%d"), Packet.Hp, Packet.MaxHp, Packet.Atk, Packet.Def, Packet.Exp);
			break;
		}

	}
}

// ���O�C�����ʂ���M�����B
void ATitleGameMode::OnRecvLogInResult(MemoryStreamInterface *pStream)
{
	PacketLogInResult Packet;
	Packet.Serialize(pStream);

	OnLogInResult(Packet.Result == PacketLogInResult::Success);
}
