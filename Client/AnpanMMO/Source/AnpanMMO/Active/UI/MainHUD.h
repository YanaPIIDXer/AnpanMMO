// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainHUD.generated.h"

/**
 * ���C��HUD
 */
UCLASS()
class ANPANMMO_API UMainHUD : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// �\��.
	static UMainHUD *Show(UObject *pOuter);

	// �R���X�g���N�^
	UMainHUD(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UMainHUD() {}

protected:


private:
	
	// Blueprint�̃A�Z�b�g�p�X
	static const TCHAR *AssetPath;
	
};
