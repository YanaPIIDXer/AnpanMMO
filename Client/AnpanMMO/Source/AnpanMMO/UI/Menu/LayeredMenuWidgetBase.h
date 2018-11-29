// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LayeredMenuWidgetBase.generated.h"

/**
 * ���C���ɕ������ꂽ���j���[Widget���N���X
 */
UCLASS()
class ANPANMMO_API ULayeredMenuWidgetBase : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// �R���X�g���N�^
	ULayeredMenuWidgetBase(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~ULayeredMenuWidgetBase() {}

	// �\��.
	void Show(int32 InZOrder = 0);

protected:

	// �߂�
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void Back();

	// ����
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void Close();

	// �q��\��.
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void ShowChild(ULayeredMenuWidgetBase *pChildMenu, bool bHideSelf = true);

private:

	// �e���j���[
	UPROPERTY()
	ULayeredMenuWidgetBase *pParentMenu;

	// ZOrder
	int32 ZOrder;

};
