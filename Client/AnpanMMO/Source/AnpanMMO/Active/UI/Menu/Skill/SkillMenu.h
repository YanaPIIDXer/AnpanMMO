// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "SkillMenu.generated.h"

/**
 * �X�L�����j���[
 */
UCLASS()
class ANPANMMO_API USkillMenu : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	USkillMenu(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~USkillMenu() {}

	// �p�P�b�g����M�����B
	virtual void OnRecvPacket(uint8 ID) override;

protected:

	// ���j���[�̍ď�����.
	UFUNCTION(BlueprintNativeEvent, Category = "SkillMenu")
	void RefleshMenu();
	void RefleshMenu_Implementation() {}

};
