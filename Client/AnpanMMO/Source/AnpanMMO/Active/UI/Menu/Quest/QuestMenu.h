// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "QuestMenu.generated.h"

// �N�G�X�g�f�[�^
USTRUCT(BlueprintType)
struct FQuestData
{

	GENERATED_USTRUCT_BODY()

public:

	// �N�G�X�g�h�c
	uint32 QuestId;

	// �N�G�X�g��.
	UPROPERTY(BlueprintReadOnly)
	FString Name;

	// ������.
	UPROPERTY(BlueprintReadOnly)
	FString Explain;

	// ���C���N�G�X�g���H
	UPROPERTY(BlueprintReadOnly)
	bool bIsMainQuest;

	// �A�N�e�B�u�N�G�X�g���H
	UPROPERTY(BlueprintReadWrite)
	bool bIsActive;

};

/**
 * �N�G�X�g���j���[
 */
UCLASS()
class ANPANMMO_API UQuestMenu : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()
	
public:

	// �R���X�g���N�^
	UQuestMenu(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UQuestMenu() {}

	// �p�P�b�g����M�����B
	virtual void OnRecvPacket(uint8 ID, MemoryStreamInterface *pStream) override;

protected:

	// ������.
	UFUNCTION(BlueprintCallable, Category = "QuestMenu")
	void Init();

	// �������C�x���g
	UFUNCTION(BlueprintNativeEvent, Category = "QuestMenu")
	void InitEvent(const TArray<FQuestData> &List);
	void InitEvent_Implementation(const TArray<FQuestData> &List) {}
	
	// �N�G�X�g�j��.
	UFUNCTION(BlueprintCallable, Category = "QuestMenu")
	void RetireQuest(const FQuestData &Data);

	// �A�N�e�B�u�N�G�X�g��ύX.
	UFUNCTION(BlueprintCallable, Category = "QuestMenu")
	void ChangeActiveQuest(const FQuestData &Data);

};
