// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "ScriptWidgetRoot.generated.h"

/**
 * �X�N���v�gWidget�̐e.
 */
UCLASS()
class ANPANMMO_API UScriptWidgetRoot : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	UScriptWidgetRoot(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UScriptWidgetRoot() {}

private:
	


};
