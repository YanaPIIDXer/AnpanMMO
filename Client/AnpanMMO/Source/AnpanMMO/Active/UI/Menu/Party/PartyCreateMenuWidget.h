// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "PartyCreateMenuWidget.generated.h"

/**
 * �p�[�e�B�쐬���j���[
 */
UCLASS()
class ANPANMMO_API UPartyCreateMenuWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// ����.
	static UPartyCreateMenuWidget *Create(UObject *pOuter);

	// �R���X�g���N�^
	UPartyCreateMenuWidget(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UPartyCreateMenuWidget() {}

protected:

	// �p�[�e�B�쐬���N�G�X�g���M.
	UFUNCTION(BlueprintCallable, Category = "Party")
	void SendPartyCreateRequest();
	
private:

	// �A�Z�b�g�p�X
	static const TCHAR *AssetPath;

};
