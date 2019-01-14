// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "TitleGameMode.h"
#include "Config.h"
#include "Packet/PacketLogInRequest.h"
#include "IdManager.h"
#include "Title/UI/TitleScreenWidget.h"
#include "Title/UI/CharacterNameInputWidget.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "UI/SimpleDialog.h"
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

// �R���X�g���N�^
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

// �J�n���̏���.
void ATitleGameMode::BeginPlay()
{
	Super::BeginPlay();

	auto *pController = UGameplayStatics::GetPlayerController(this, 0);
	pController->ConsoleCommand("r.SetRes 1280x720w");
	pController->SetVirtualJoystickVisibility(false);

	pScreenWidget = UTitleScreenWidget::Show(this);
	pScreenWidget->OnConnect.BindUObject(this, &ATitleGameMode::OnConnectResult);
	pScreenWidget->OnReadyToGame.BindUObject(this, &ATitleGameMode::OnReadyToGame);
}

// ���O�C�����N�G�X�g�𑗐M.
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
bool ATitleGameMode::OnRecvLogInResult(MemoryStreamInterface *pStream)
{
	PacketLogInResult Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (Packet.Result == PacketLogInResult::NoCharacter)
	{
		pNameInputWidget = UCharacterNameInputWidget::Show(this, 1);
		return true;
	}

	bool bResult = (Packet.Result == PacketLogInResult::Success);
	OnLogInResult(bResult);

	if (bResult)
	{
		pScreenWidget->StartFade();
	}
	else
	{
		pScreenWidget->OnFailedLogIn();
	}

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);
	pInst->SetAreaIdCache(Packet.LastAreaId);

	return true;
}

// �L�����N�^�쐬���ʂ���M�����B
bool ATitleGameMode::OnRecvCreateCharacterResult(MemoryStreamInterface *pStream)
{
	PacketCreateCharacterResult Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	switch (Packet.Result)
	{
		case PacketCreateCharacterResult::Success:

			// ���O����Widget�������B
			pNameInputWidget->RemoveFromParent();
			pNameInputWidget = nullptr;

			// ���߂ă��O�C���v��.
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

	return true;
}

// �L�����N�^�X�e�[�^�X����M�����B
bool ATitleGameMode::OnRecvCharacterStatus(MemoryStreamInterface *pStream)
{
	PacketCharacterStatus Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	FString NameStr = UTF8_TO_TCHAR(Packet.Name.c_str());
	pInst->OnRecvStatus(Packet.Uuid, NameStr, Packet.Job, Packet.Level, Packet.MaxHp, Packet.BaseMaxHp, Packet.Str, Packet.Def, Packet.Int, Packet.Mnd, Packet.Vit, Packet.Exp, Packet.Gold, Packet.RightEquip, Packet.LeftEquip);

	return true;
}

// �X�L�����X�g����M�����B
bool ATitleGameMode::OnRecvSkillList(MemoryStreamInterface *pStream)
{
	PacketSkillList Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	pInst->OnRecvSkillList(Packet.Skill1, Packet.Skill2, Packet.Skill3, Packet.Skill4);

	return true;
}

// �X�L���c���[�f�[�^����M�����B
bool ATitleGameMode::OnRecvSkillTreeData(MemoryStreamInterface *pStream)
{
	PacketSkillTreeData Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	pInst->OnRecvSkillTreeData(Packet.Nodes);

	return true;
}

// �A�C�e�����X�g����M�����B
bool ATitleGameMode::OnRecvItemList(MemoryStreamInterface *pStream)
{
	PacketItemList Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	pInst->OnRecvItemList(Packet.Items);

	return true;
}

// �A�C�e���V���[�g�J�b�g����M�����B
bool ATitleGameMode::OnRecvItemShortcut(MemoryStreamInterface *pStream)
{
	PacketItemShortcut Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	pInst->OnRecvItemShortcht(Packet.ItemId1, Packet.ItemId2);

	return true;
}

// �X�N���v�g�t���O����M�����B
bool ATitleGameMode::OnRecvScriptFlag(MemoryStreamInterface *pStream)
{
	PacketScriptFlag Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	pInst->GetScript()->ConvertFlagFromBitFields(Packet.BitField1, Packet.BitField2, Packet.BitField3);

	return true;
}

// �N�G�X�g�f�[�^����M�����B
bool ATitleGameMode::OnRecvQuestData(MemoryStreamInterface *pStream)
{
	PacketQuestData Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	auto *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	pInst->InitializeQuestManager();

	for (int32 i = 0; i < Packet.Quests.GetCurrentSize(); i++)
	{
		pInst->AddQuestData(Packet.Quests[i]);
	}

	pInst->SetActiveQuest(Packet.ActiveQuestId, false);

	return true;
}

// �Q�[����ʂɐi�ޏ������o�����B
void ATitleGameMode::OnReadyToGame()
{
	UGameplayStatics::OpenLevel(this, "Active");
}
