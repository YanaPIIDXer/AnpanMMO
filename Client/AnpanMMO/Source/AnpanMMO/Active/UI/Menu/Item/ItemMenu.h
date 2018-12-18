// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "ItemMenu.generated.h"

// �A�C�e���f�[�^
USTRUCT(BlueprintType)
struct FItemData
{

	GENERATED_USTRUCT_BODY()

public:

	// �A�C�e���h�c
	uint32 ItemId;

	// ���O.
	UPROPERTY(BlueprintReadOnly)
	FString Name;

	// ��.
	UPROPERTY(BlueprintReadOnly)
	int32 Count;

};

/**
 * �A�C�e�����j���[
 */
UCLASS()
class ANPANMMO_API UItemMenu : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()
	
public:

	// �R���X�g���N�^
	UItemMenu(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UItemMenu() {}

	// ������.
	UFUNCTION(BlueprintCallable, Category = "ItemMenu")
	void Init();

protected:

	// �������C�x���g
	UFUNCTION(BlueprintNativeEvent, Category = "ItemMenu")
	void InitEvent(const TArray<FItemData> &Items);
	void InitEvent_Implementation(const TArray<FItemData> &Items) {}

};
