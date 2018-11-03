// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleScreenWidget.generated.h"

/**
 * �^�C�g�����Widget
 */
UCLASS()
class ANPANMMO_API UTitleScreenWidget : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// ����.
	static UTitleScreenWidget *Show(UObject *pOuter);

	// �R���X�g���N�^
	UTitleScreenWidget(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UTitleScreenWidget() {}

protected:

	// �Q�[���T�[�o�ւ̐ڑ�.
	UFUNCTION(BlueprintCallable, Category = "Connection")
	void ConnectToGameServer();

private:

	// Widget�̃p�X
	static const TCHAR *WidgetPath;
	
};
