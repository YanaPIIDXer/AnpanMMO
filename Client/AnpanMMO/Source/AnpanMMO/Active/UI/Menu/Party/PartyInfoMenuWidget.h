// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "PartyInfoMenuWidget.generated.h"

/**
 * �p�[�e�B��񃁃j���[Widget
 */
UCLASS()
class ANPANMMO_API UPartyInfoMenuWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// ����.
	static UPartyInfoMenuWidget *Create(UObject *pOuter);

	// �R���X�g���N�^
	UPartyInfoMenuWidget(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UPartyInfoMenuWidget() {}

protected:

	// ���U���N�G�X�g�𑗐M.
	UFUNCTION(BlueprintCallable, Category = "Party")
	void SendDissolutionRequest();

private:

	// �A�Z�b�g�p�X
	static const TCHAR *AssetPath;
	
};
