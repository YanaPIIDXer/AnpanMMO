// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "YesNoDialog.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDialogResult);

/**
 * �͂��E�������̃_�C�A���O
 */
UCLASS()
class ANPANMMO_API UYesNoDialog : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// �\��.
	static UYesNoDialog *Show(UObject *pOuter, const FString &DisplayText, int32 ZOrder = 0);

	// �R���X�g���N�^
	UYesNoDialog(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UYesNoDialog() {}


	// �͂����I�����ꂽ�B
	UPROPERTY(BlueprintAssignable, Category = "Dialog")
	FOnDialogResult OnYes;

	// ���������I�����ꂽ�B
	UPROPERTY(BlueprintAssignable, Category = "Dialog")
	FOnDialogResult OnNo;

protected:

	// �͂����I�����ꂽ�B
	UFUNCTION(BlueprintCallable, Category = "Dialog")
	void OnSelectedYes();

	// ���������I�����ꂽ�B
	UFUNCTION(BlueprintCallable, Category = "Dialog")
	void OnSelectedNo();


	// �\��������.
	UPROPERTY(BlueprintReadOnly, Category = "Dialog")
	FString DisplayText;

private:

	// �A�Z�b�g�p�X
	static const TCHAR *AssetPath;

};
