// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "TitleScreenWidget.h"
#include "MMOGameInstance.h"
#include "Config.h"
#include "Packet/PacketLogInRequest.h"
#include "IdManager.h"

const TCHAR *UTitleScreenWidget::WidgetPath = TEXT("/Game/Blueprints/UI/Title/TitleScreen.TitleScreen_C");

// ����.
UTitleScreenWidget *UTitleScreenWidget::Create(UObject *pOuter)
{
	UBlueprintGeneratedClass *pClass = LoadObject<UBlueprintGeneratedClass>(pOuter, WidgetPath, WidgetPath);
	check(pClass != nullptr);

	UTitleScreenWidget *pWidget = NewObject<UTitleScreenWidget>(pOuter, pClass);
	check(pWidget != nullptr);

	return pWidget;
}

// �R���X�g���N�^
UTitleScreenWidget::UTitleScreenWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// �Q�[���T�[�o�ւ̐ڑ�.
void UTitleScreenWidget::ConnectToGameServer()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	if (!pInst->Connect(Config::ServerHost, Config::ServerPort))
	{
		UE_LOG(LogTemp, Log, TEXT("GameServer Connection Failed..."));
		return;
	}

	// ���O�C���p�P�b�g���M.
	std::string FilePath = TCHAR_TO_UTF8(*Config::IdFilePath);
	IdManager IdMgr(FilePath);
	std::string Id = IdMgr.GetId();
	PacketLogInRequest Packet(Id);
	pInst->SendPacket(&Packet);
}
