// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "EquipMenu.generated.h"

/**
 * �������j���[
 */
UCLASS()
class ANPANMMO_API UEquipMenu : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	UEquipMenu(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UEquipMenu() {}

protected:

};
