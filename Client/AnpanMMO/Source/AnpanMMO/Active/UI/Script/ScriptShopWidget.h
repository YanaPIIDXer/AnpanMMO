// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "ScriptShopWidget.generated.h"

/**
 * �X�N���v�g�F�V���b�v���.
 */
UCLASS()
class ANPANMMO_API UScriptShopWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()
	
public:

	// ����.
	static UScriptShopWidget *Create(UObject *pOuter);

	// �R���X�g���N�^
	UScriptShopWidget(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UScriptShopWidget() {}

	// ������.
	void Init(uint32 InShopId);

protected:

	// ���֐i�ށB
	UFUNCTION(BlueprintCallable, Category = "Shop")
	void ToNext();

private:

	// �A�Z�b�g�̃p�X
	static const TCHAR *AssetPath;

	// �V���b�v�h�c
	uint32 ShopId;

};
