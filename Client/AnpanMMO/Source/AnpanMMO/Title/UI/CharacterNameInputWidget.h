// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterNameInputWidget.generated.h"

/**
 * �L�����N�^������Widget
 */
UCLASS()
class ANPANMMO_API UCharacterNameInputWidget : public UUserWidget
{

	GENERATED_BODY()

public:

	// �\��.
	static UCharacterNameInputWidget *Show(UObject *pOuter, int32 ZOrder);

	// �R���X�g���N�^
	UCharacterNameInputWidget(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UCharacterNameInputWidget() {}

protected:

	// ���N�G�X�g�p�P�b�g���M.
	UFUNCTION(BlueprintCallable, Category = "Request")
	void SendRequestPacket(const FString &Name);

private:

	// �A�Z�b�g�p�X
	static const TCHAR *AssetPath;

};
