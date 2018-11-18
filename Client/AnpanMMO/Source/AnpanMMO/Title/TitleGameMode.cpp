// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "TitleGameMode.h"
#include "Title/UI/TitleScreenWidget.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "UI/SimpleDialog.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketLogInResult.h"
#include "Packet/PacketCharacterStatus.h"
#include "Master/MasterData.h"

// �R���X�g���N�^
ATitleGameMode::ATitleGameMode(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pScreenWidget(nullptr)
{
	AddPacketFunction(PacketID::LogInResult, std::bind(&ATitleGameMode::OnRecvLogInResult, this, _1));
	AddPacketFunction(PacketID::CharacterStatus, std::bind(&ATitleGameMode::OnRecvCharacterStatus, this, _1));
}

// �J�n���̏���.
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

// ���O�C�����ʂ���M�����B
void ATitleGameMode::OnRecvLogInResult(MemoryStreamInterface *pStream)
{
	PacketLogInResult Packet;
	Packet.Serialize(pStream);

	bool bResult = (Packet.Result == PacketLogInResult::Success);
	OnLogInResult(bResult);

	if (bResult)
	{
		MasterData::GetInstance().Load();
		pScreenWidget->StartFade();
	}

	// @TODO:�b�菈��.
	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	pInst->SetAreaIdCache(Packet.LastAreaId);
}

// �L�����N�^�X�e�[�^�X����M�����B
void ATitleGameMode::OnRecvCharacterStatus(MemoryStreamInterface *pStream)
{
	PacketCharacterStatus Packet;
	Packet.Serialize(pStream);

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	pInst->OnRecvStatus(Packet.Uuid, Packet.MaxHp, Packet.Atk, Packet.Def, Packet.Exp);
}

// �Q�[����ʂɐi�ޏ������o�����B
void ATitleGameMode::OnReadyToGame()
{
	UGameplayStatics::OpenLevel(this, "Active");
}
