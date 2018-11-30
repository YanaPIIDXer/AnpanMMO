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

	// �J�n���̏���.
	virtual void NativeConstruct() override;

protected:

	// ���������ꂽ
	UFUNCTION(BlueprintNativeEvent, Category = "Party")
	void OnInit();
	void OnInit_Implementation() {}

	// ���U���N�G�X�g�𑗐M.
	UFUNCTION(BlueprintCallable, Category = "Party")
	void SendDissolutionRequest();

	// ���E���N�G�X�g�𑗐M.
	UFUNCTION(BlueprintCallable, Category = "Party")
	void SendExitRequest();


	// ���[�_�[���H
	UPROPERTY(BlueprintReadOnly, Category = "Party")
	bool bIsLeader;

private:

	// �A�Z�b�g�p�X
	static const TCHAR *AssetPath;
	
};
