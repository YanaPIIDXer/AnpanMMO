// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.


#include "MailMenu.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Packet/PacketMailListRequest.h"

// �R���X�g���N�^
UMailMenu::UMailMenu(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// ���[�����X�g�v�����M.
void UMailMenu::SendMailListRequest()
{
	PacketMailListRequest Packet;
	
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	pInst->SendPacket(&Packet);
}

// �p�P�b�g����M�����B
void UMailMenu::OnRecvPacket(uint8 ID, MemoryStreamInterface *pStream)
{
	switch (ID)
	{
		case PacketID::MailList:

			Init();
			break;
	}
}


// �qWidget����߂��Ă������̏���.
void UMailMenu::OnBackFromChild_Implementation()
{
	Init();
}


// ������.
void UMailMenu::Init()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	const auto &AllMail = pInst->GetMailManager().GetAllMail();
	TArray<FMailData> List;
	for (const auto &Mail : AllMail)
	{
		FMailData Data(Mail);
		List.Add(Data);
	}

	OnInit(List);
}


// ================ FMailData ===================

// �R���X�g���N�^
FMailData::FMailData(const MailData &Source)
{
	Id = Source.Id;
	Subject = UTF8_TO_TCHAR(Source.Subject.c_str());
	Body = UTF8_TO_TCHAR(Source.Body.c_str());
	switch (Source.Flag)
	{
		case MailData::NotRead:

			Flag = EMailFlag::NotRead;
			break;

		case MailData::Read:

			Flag = EMailFlag::Read;
			break;

		case MailData::RecvAttachment:

			Flag = EMailFlag::RecvAttachment;
			break;
	}
}
