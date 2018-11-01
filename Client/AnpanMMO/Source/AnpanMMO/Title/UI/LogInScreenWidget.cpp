// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "LogInScreenWidget.h"
#include "MMOGameInstance.h"
#include "Packet/PacketLogInRequest.h"

// �R���X�g���N�^
ULogInScreenWidget::ULogInScreenWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}


// ���O�C���p�P�b�g�𑗐M.
void ULogInScreenWidget::SendLogInPacket(const FString &UserName, const FString &Password)
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(GetGameInstance());
	check(pInst != nullptr);

	PacketLogInRequest Packet(TCHAR_TO_UTF8(*UserName));
	pInst->SendPacket(&Packet);
}
