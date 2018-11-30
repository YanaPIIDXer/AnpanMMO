// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PartyInfoMenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "Active/ActiveGameMode.h"
#include "Util.h"
#include "Packet/PacketPartyDissolutionRequest.h"
#include "Packet/PacketPartyExitRequest.h"

const TCHAR *UPartyInfoMenuWidget::AssetPath = TEXT("/Game/Blueprints/UI/Active/Menu/Party/PartyInfoMenu.PartyInfoMenu");

// 生成.
UPartyInfoMenuWidget *UPartyInfoMenuWidget::Create(UObject *pOuter)
{
	UPartyInfoMenuWidget *pWidget = Util::LoadBlueprint<UPartyInfoMenuWidget>(pOuter, AssetPath);
	check(pWidget != nullptr);

	return pWidget;
}

// コンストラクタ
UPartyInfoMenuWidget::UPartyInfoMenuWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// 開始時の処理.
void UPartyInfoMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Init();
}


// 初期化.
void UPartyInfoMenuWidget::Init()
{
	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);

	bIsLeader = pGameMode->GetPartyInfo().IsLeader();

	TArray<PartyMemberData> List = pGameMode->GetPartyInfo().GetMemberList();
	for (int32 i = 0; i < List.Num(); i++)
	{
		const auto &Data = List[i];
		FPartyMemberData Member;
		Member.Uuid = Data.Uuid;
		Member.Name = UTF8_TO_TCHAR(Data.CharacterName.c_str());
		Member.bIsLeader = (i == 0);

		MemberList.Add(Member);
	}

	OnInit();
}


// 解散リクエストを送信.
void UPartyInfoMenuWidget::SendDissolutionRequest()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketPartyDissolutionRequest Packet;
	pInst->SendPacket(&Packet);
}

// 離脱リクエストを送信.
void UPartyInfoMenuWidget::SendExitRequest()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketPartyExitRequest Packet;
	pInst->SendPacket(&Packet);
}
