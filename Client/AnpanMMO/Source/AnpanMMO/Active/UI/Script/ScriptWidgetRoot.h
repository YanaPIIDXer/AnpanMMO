// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "ScriptWidgetRoot.generated.h"

class UScriptMessageWidget;
class UScriptSelectionWidget;

/**
 * �X�N���v�gWidget�̐e.
 */
UCLASS()
class ANPANMMO_API UScriptWidgetRoot : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	UScriptWidgetRoot(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UScriptWidgetRoot() {}

	// ������.
	// ��Initialize�ƌ����֐����ɂ��������������Ɏg���Ă���悤���B
	void Init();

	// ���b�Z�[�W�\��.
	void ShowMessage(const FString &Message);

	// �I������ǉ�.
	void AddSelection(const FString &Item);

	// �I������\��.
	void ShowSelection();

	// Widget�����B
	void CloseWidget();

private:
	
	// ���b�Z�[�WWidget
	UPROPERTY()
	UScriptMessageWidget *pMessageWidget;

	// �I����Widget
	UPROPERTY()
	UScriptSelectionWidget *pSelectionWidget;

	// ���ݕ\������Widget
	UPROPERTY()
	UUserWidget *pCurrentWidget;

};
