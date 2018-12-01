// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "Packet/PacketID.h"
#include "InstanceAreaWaitingWidget.generated.h"

/**
 * インスタンスエリア移動待機Widegt
 */
UCLASS()
class ANPANMMO_API UInstanceAreaWaitingWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// コンストラクタ
	UInstanceAreaWaitingWidget(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UInstanceAreaWaitingWidget() {}
	
	// パケットを受信した。
	virtual void OnRecvPacket(PacketID ID) override;

};
