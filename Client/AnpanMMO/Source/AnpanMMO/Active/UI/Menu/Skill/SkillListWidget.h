// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SkillMenu.h"
#include "Blueprint/UserWidget.h"
#include "SkillListWidget.generated.h"

/**
 * �X�L�����X�g���.
 */
UCLASS()
class ANPANMMO_API USkillListWidget : public UUserWidget
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	USkillListWidget(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~USkillListWidget() {}

	// ������.
	UFUNCTION(BlueprintCallable, Category = "SkillList")
	void Init();

protected:

	// �������C�x���g
	UFUNCTION(BlueprintNativeEvent, Category = "SkillList")
	void InitEvent();
	void InitEvent_Implementation() {}
	
};
