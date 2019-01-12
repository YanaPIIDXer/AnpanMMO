// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "GameMenuWidget.generated.h"

/**
 * �Q�[�����j���[Widget
 */
UCLASS()
class ANPANMMO_API UGameMenuWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// �\��.
	static UGameMenuWidget *ShowWidget(UObject *pOuter);

	// �R���X�g���N�^
	UGameMenuWidget(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UGameMenuWidget() {}

protected:

	// �p�[�e�B���j���[�\��.
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void ShowPartyMenu();

	// ���O�A�E�g
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void LogOut();

private:

	// �A�Z�b�g�̃p�X
	static const TCHAR *AssetPath;

};
