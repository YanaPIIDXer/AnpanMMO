// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "ScriptSelectionWidget.generated.h"

/**
 * �X�N���v�g�F�I����Widget
 */
UCLASS()
class ANPANMMO_API UScriptSelectionWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// ����.
	static UScriptSelectionWidget *Create(UObject *pOuter);

	// �R���X�g���N�^
	UScriptSelectionWidget(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UScriptSelectionWidget() {}

	// ������.
	void Init();

	// �I������ǉ�.
	void AddSelection(const FString &Item);

protected:

	// �I��.
	UFUNCTION(BlueprintCallable, Category = "Script")
	void Select(int32 Index);

	// �������C�x���g.
	UFUNCTION(BlueprintNativeEvent, Category = "Script")
	void InitEvent(const TArray<FString> &Items);
	void InitEvent_Implementation(const TArray<FString> &Items) {}

private:
	
	// �A�Z�b�g�p�X
	static const TCHAR *AssetPath;

	// �I����.
	TArray<FString> Selections;

};
