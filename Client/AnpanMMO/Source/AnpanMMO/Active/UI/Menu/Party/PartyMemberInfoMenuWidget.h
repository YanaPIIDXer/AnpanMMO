// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "PartyInfoMenuWidget.h"
#include "PartyMemberInfoMenuWidget.generated.h"

/**
 * �p�[�e�B�����o��񃁃j���[�N���X
 */
UCLASS()
class ANPANMMO_API UPartyMemberInfoMenuWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	UPartyMemberInfoMenuWidget(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UPartyMemberInfoMenuWidget() {}

	// ������.
	UFUNCTION(BlueprintCallable, Category = "Party")
	void Init(bool bInIsLeader, const FPartyMemberData &InData);

protected:

	// ���[�_�[���H
	UPROPERTY(BlueprintReadOnly, Category = "Party")
	bool bIsLeader;

	// �f�[�^
	UPROPERTY(BlueprintReadOnly)
	FPartyMemberData Data;


	// �L�b�N����
	UFUNCTION(BlueprintCallable, Category = "Party")
	void Kick();

};
