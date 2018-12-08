// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "ScriptWidgetRoot.generated.h"

class UScriptMessageWidget;

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

	// Widget�����B
	void CloseWidget();

private:
	
	// ���b�Z�[�WWidget
	UPROPERTY()
	UScriptMessageWidget *pMessageWidget;

	// ���ݕ\������Widget
	UPROPERTY()
	UUserWidget *pCurrentWidget;

};
