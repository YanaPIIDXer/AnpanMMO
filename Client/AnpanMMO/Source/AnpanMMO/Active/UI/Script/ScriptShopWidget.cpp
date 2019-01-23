// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.


#include "ScriptShopWidget.h"
#include "Util.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "Packet/PacketExitShop.h"

const TCHAR *UScriptShopWidget::AssetPath = TEXT("/Game/Blueprints/UI/Active/Script/ShopWidget.ShopWidget");

// 生成.
UScriptShopWidget *UScriptShopWidget::Create(UObject *pOuter)
{
	auto *pWidget = Util::LoadBlueprint<UScriptShopWidget>(pOuter, AssetPath);
	check(pWidget != nullptr);

	return pWidget;
}

// コンストラクタ
UScriptShopWidget::UScriptShopWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, ShopId(0)
{
}

// 初期化.
void UScriptShopWidget::Init(uint32 InShopId)
{
	ShopId = InShopId;
}


// 次へ進む。
void UScriptShopWidget::ToNext()
{
	// 終了パケット送信。
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketExitShop Packet;
	pInst->SendPacket(&Packet);

	// スクリプトのResume
	pInst->GetScript()->Resume();
}
