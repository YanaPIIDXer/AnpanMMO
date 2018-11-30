// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "InstanceAreaTicketMenuWidget.generated.h"

/**
 * �C���X�^���X�}�b�v�`�P�b�g���j���[
 */
UCLASS()
class ANPANMMO_API UInstanceAreaTicketMenuWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// �\��.
	static void ShowWidget(UObject *pOuter, uint32 TicketId);

	// �R���X�g���N�^
	UInstanceAreaTicketMenuWidget(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UInstanceAreaTicketMenuWidget() {}

protected:

	// �Q���𑗐M�B
	UFUNCTION(BlueprintCallable, Category = "InstanceAreaTicket")
	void SendEnter();

	// �j���𑗐M.
	UFUNCTION(BlueprintCallable, Category = "InstanceAreaTicket")
	void SendDiscard();

private:

	// �A�Z�b�g�p�X
	static const TCHAR *AssetPath;

	// �`�P�b�g�h�c
	uint32 TicketId;
	
};
