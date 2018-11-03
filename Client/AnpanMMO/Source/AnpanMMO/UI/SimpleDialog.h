// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SimpleDialog.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDialogOK);

/**
 * �P���ȃ_�C�A���O
 */
UCLASS()
class ANPANMMO_API USimpleDialog : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// �\��.
	static USimpleDialog *Show(UObject *pOuter, const FString &InDisplayText);

	// �R���X�g���N�^
	USimpleDialog(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~USimpleDialog() {}

	// OK�{�^���������ꂽ�B
	UPROPERTY(BlueprintAssignable, Category = "Dialog")
	FOnDialogOK OnDialogOK;

protected:

	// OK�{�^���������ꂽ�B
	UFUNCTION(BlueprintCallable, Category = "Dialog")
	void OnOK();

	// �\��������.
	UPROPERTY(BlueprintReadOnly, Category = "Dialog")
	FString DisplayText;
	
private:

	// Blueprint�̃p�X.
	static const TCHAR *BlueprintPath;

};
