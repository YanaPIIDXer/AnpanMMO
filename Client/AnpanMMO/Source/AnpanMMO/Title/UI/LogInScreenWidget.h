// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LogInScreenWidget.generated.h"

/**
 * ���O�C�����Widget
 */
UCLASS()
class ANPANMMO_API ULogInScreenWidget : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// �R���X�g���N�^
	ULogInScreenWidget(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~ULogInScreenWidget() {}

protected:
	
	
};
