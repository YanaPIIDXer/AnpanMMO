// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "ScriptMessageWidget.generated.h"

/**
 * �X�N���v�g�F���b�Z�[�W�E�B���h�E
 */
UCLASS()
class ANPANMMO_API UScriptMessageWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// ����.
	static UScriptMessageWidget *Create(UObject *pOuter);

	// �R���X�g���N�^
	UScriptMessageWidget(const FObjectInitializer &ObjectInitializer);
	
	// �f�X�g���N�^
	virtual ~UScriptMessageWidget() {}

	// ���b�Z�[�W���Z�b�g�B
	void SetMessage(const FString &InMessage) { Message = InMessage; }

protected:

	// ���b�Z�[�W
	UPROPERTY(BlueprintReadonly, Category = "Script")
	FString Message;

private:

	// �A�Z�b�g�p�X
	static const TCHAR *AssetPath;


	// ���֐i�ށB
	UFUNCTION(BlueprintCallable, Category = "Script")
	void ToNext();
	
};
