// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LayeredMenuWidgetBase.generated.h"

DECLARE_DELEGATE(FOnMenuClosed);

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

	// ����
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void Close();

	// �q�����B
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void CloseChild();

	// �p�P�b�g����M�����B
	virtual void OnRecvPacket(PacketID ID) {}


	// ���j���[������ꂽ�B
	FOnMenuClosed OnMenuClosed;

protected:

	// �߂�
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void Back();

	// �߂��Ă������̃C�x���g
	UFUNCTION(BlueprintNativeEvent, Category = "Menu")
	void OnBackFromChild();
	void OnBackFromChild_Implementation() {}

	// �q��\��.
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void ShowChild(ULayeredMenuWidgetBase *pInChildMenu, bool bHideSelf = true);

private:

	// �e���j���[
	UPROPERTY()
	ULayeredMenuWidgetBase *pParentMenu;

	// �q���j���[
	UPROPERTY()
	ULayeredMenuWidgetBase *pChildMenu;

	// ZOrder
	int32 ZOrder;

};
