// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.


#include "MailDetail.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Packet/PacketMailRead.h"

// コンストラクタ
UMailDetail::UMailDetail(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// メールを開く
void UMailDetail::Open(const FMailData &InData)
{
	Data = InData;

	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	pInst->ChangeMailFlag(Data.Id, MailData::Read);
	
	PacketMailRead Packet(Data.Id);
	pInst->SendPacket(&Packet);

	OnOpen();
}
