// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SkillTreeWidget.generated.h"

/**
 * �X�L���c���[���.
 */
UCLASS()
class ANPANMMO_API USkillTreeWidget : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// �R���X�g���N�^
	USkillTreeWidget(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~USkillTreeWidget() {}

	// ������.
	UFUNCTION(BlueprintCallable, Category = "SkillTree")
	void Init();

protected:

	// �������C�x���g
	UFUNCTION(BlueprintNativeEvent, Category = "SkillTree")
	void InitEvent();
	void InitEvent_Implementation() {}

};
