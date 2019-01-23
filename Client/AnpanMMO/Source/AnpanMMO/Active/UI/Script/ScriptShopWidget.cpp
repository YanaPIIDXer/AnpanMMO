// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.


#include "ScriptShopWidget.h"
#include "Util.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "Packet/PacketExitShop.h"

const TCHAR *UScriptShopWidget::AssetPath = TEXT("/Game/Blueprints/UI/Active/Script/ShopWidget.ShopWidget");

// ����.
UScriptShopWidget *UScriptShopWidget::Create(UObject *pOuter)
{
	auto *pWidget = Util::LoadBlueprint<UScriptShopWidget>(pOuter, AssetPath);
	check(pWidget != nullptr);

	return pWidget;
}

// �R���X�g���N�^
UScriptShopWidget::UScriptShopWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, ShopId(0)
{
}

// ������.
void UScriptShopWidget::Init(uint32 InShopId)
{
	ShopId = InShopId;
}


// ���֐i�ށB
void UScriptShopWidget::ToNext()
{
	// �I���p�P�b�g���M�B
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketExitShop Packet;
	pInst->SendPacket(&Packet);

	// �X�N���v�g��Resume
	pInst->GetScript()->Resume();
}
