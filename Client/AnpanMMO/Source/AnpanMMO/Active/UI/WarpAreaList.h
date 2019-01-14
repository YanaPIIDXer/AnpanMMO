// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "WarpAreaList.generated.h"

/**
 * ���[�v�G���A���X�g
 */
UCLASS()
class ANPANMMO_API UWarpAreaList : public ULayeredMenuWidgetBase
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

protected:

	// �A�C�e���ǉ��B
	UFUNCTION(BlueprintNativeEvent, Category = "WarpAreaList")
	void AddItem(int32 Id, int32 AreaId, const FString &Name);
	void AddItem_Implementation(int32 Id, int32 AreaId, const FString &Name) {}

	// �G���A�ړ��p�P�b�g���M.
	UFUNCTION(BlueprintCallable, Category = "WarpAreaList")
	void SendAreaMoveRequest(int32 MoveId, int32 AreaId);

private:

	// �A�Z�b�g�̃p�X
	static const TCHAR *AssetPath;

	// ID
	uint32 Id;
	
};
