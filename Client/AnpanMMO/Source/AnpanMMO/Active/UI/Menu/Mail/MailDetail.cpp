// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.


#include "MailDetail.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Packet/PacketMailRead.h"

// コンストラクタ
UMailDetail::UMailDetail(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, Subject("")
	, Body("")
{
}

// メールを開く
void UMailDetail::Open(const FMailData &Data)
{
	Subject = Data.Subject;
	Body = Data.Body;

	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	pInst->ChangeMailFlag(Data.Id, MailData::Read);
	
	PacketMailRead Packet(Data.Id);
	pInst->SendPacket(&Packet);

	OnOpen();
}
