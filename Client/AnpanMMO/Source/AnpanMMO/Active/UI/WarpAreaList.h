// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WarpAreaList.generated.h"

/**
 * ���[�v�G���A���X�g
 */
UCLASS()
class ANPANMMO_API UWarpAreaList : public UUserWidget
{

	GENERATED_BODY()

public:

	// ����.
	static void Create(UObject *pOuter, uint32 Id);

	// �R���X�g���N�^
	UWarpAreaList(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UWarpAreaList() {}

	// �������̏���.
	virtual void NativeConstruct() override;

	// �j�����̏���.
	virtual void NativeDestruct() override;

protected:

	// �A�C�e���ǉ��B
	UFUNCTION(BlueprintNativeEvent, Category = "WarpAreaList")
	void AddItem(int32 Id, const FString &Name);
	void AddItem_Implementation(int32 Id, const FString &Name) {}

private:

	// �A�Z�b�g�̃p�X
	static const TCHAR *AssetPath;

	// ID
	uint32 Id;
	
};
