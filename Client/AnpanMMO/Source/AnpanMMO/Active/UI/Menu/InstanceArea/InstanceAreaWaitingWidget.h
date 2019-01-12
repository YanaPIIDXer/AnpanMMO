// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "Packet/PacketID.h"
#include "InstanceAreaWaitingWidget.generated.h"

/**
 * �C���X�^���X�G���A�ړ��ҋ@Widegt
 */
UCLASS()
class ANPANMMO_API UInstanceAreaWaitingWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	UInstanceAreaWaitingWidget(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UInstanceAreaWaitingWidget() {}
	
	// �p�P�b�g����M�����B
	virtual void OnRecvPacket(uint8 ID) override;

};
