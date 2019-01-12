// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

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

	// �g�p�\���H
	UPROPERTY(BlueprintReadOnly)
	bool bIsUsable;

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

	// �p�P�b�g����M�����B
	virtual void OnRecvPacket(uint8 ID) override;

protected:

	// �������C�x���g
	UFUNCTION(BlueprintNativeEvent, Category = "ItemMenu")
	void InitEvent(const TArray<FItemData> &Items, const FItemData &ItemShortcut1, const FItemData &ItemShortcut2);
	void InitEvent_Implementation(const TArray<FItemData> &Items, const FItemData &ItemShortcut1, const FItemData &ItemShortcut2) {}

	// �g�p.
	UFUNCTION(BlueprintCallable, Category = "ItemMenu")
	void Use(const FItemData &Data);

	// �j��.
	UFUNCTION(BlueprintCallable, Category = "ItemMenu")
	void Subtract(const FItemData &Data, int32 Count);

	// �V���[�g�J�b�g�ۑ�.
	UFUNCTION(BlueprintCallable, Category = "ItemMenu")
	void SaveShortcut(const FItemData &Data1, const FItemData &Data2);

};
