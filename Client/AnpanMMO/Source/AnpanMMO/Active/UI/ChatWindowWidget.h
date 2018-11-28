// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ChatWindowWidget.generated.h"

// �`���b�g�̎��.
UENUM(BlueprintType, Category = "Chat")
enum class EChatType : uint8
{
	Say,
	Showt,
};

/**
 * �`���b�g�E�B���h�E
 */
UCLASS()
class ANPANMMO_API UChatWindowWidget : public UUserWidget
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	UChatWindowWidget(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UChatWindowWidget() {}

protected:
	
	// �`���b�g���M.
	UFUNCTION(BlueprintCallable, Category = "Chat")
	void SendChat(EChatType Type, const FString &Message);

};
