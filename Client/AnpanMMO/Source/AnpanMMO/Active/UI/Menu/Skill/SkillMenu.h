// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "SkillMenu.generated.h"

/**
 * �X�L���c���[�m�[�h
 */
USTRUCT(BlueprintType)
struct FSkillTreeNode
{

	GENERATED_USTRUCT_BODY()

public:

	// �m�[�h�h�c
	uint32 NodeId;

	// �X�L���h�c
	UPROPERTY(BlueprintReadOnly)
	int32 SkillId;

	// �K�v�ȃ��x��
	UPROPERTY(BlueprintReadOnly)
	int32 NeedLevel;

	// �R�X�g
	UPROPERTY(BlueprintReadOnly)
	int32 Cost;

	// �J���Ă��邩�H
	UPROPERTY(BlueprintReadOnly)
	bool bIsOpened;

	// �e�m�[�h���J���Ă��邩�H
	UPROPERTY(BlueprintReadOnly)
	bool bIsParentOpened;

	// ���W.
	UPROPERTY(BlueprintReadOnly)
	FVector2D Position;

};

/**
 * �X�L�����j���[
 */
UCLASS()
class ANPANMMO_API USkillMenu : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	USkillMenu(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~USkillMenu() {}

	// �p�P�b�g����M�����B
	virtual void OnRecvPacket(uint8 ID) override;

protected:

	// ���j���[�̍ď�����.
	UFUNCTION(BlueprintNativeEvent, Category = "SkillMenu")
	void RefleshMenu();
	void RefleshMenu_Implementation() {}

};
