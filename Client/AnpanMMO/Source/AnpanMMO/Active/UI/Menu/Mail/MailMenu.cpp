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
void UMailMenu::OnRecvPacket(uint8 ID)
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
		FMailData Data;
		
		Data.Id = Mail.Id;
		Data.Subject = UTF8_TO_TCHAR(Mail.Subject.c_str());
		Data.Body = UTF8_TO_TCHAR(Mail.Body.c_str());
		switch (Mail.Flag)
		{
			case MailData::NotRead:

				Data.Flag = EMailFlag::NotRead;
				break;

			case MailData::Read:

				Data.Flag = EMailFlag::Read;
				break;

			case MailData::RecvAttachment:

				Data.Flag = EMailFlag::RecvAttachment;
				break;
		}

		List.Add(Data);
	}

	OnInit(List);
}
