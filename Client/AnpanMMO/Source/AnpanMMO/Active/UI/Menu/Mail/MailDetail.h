// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "MailMenu.h"
#include "MailDetail.generated.h"

/**
 * ���[���ڍ�.
 */
UCLASS()
class ANPANMMO_API UMailDetail : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()
		
public:

	// �R���X�g���N�^
	UMailDetail(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UMailDetail() {}

	// ���[�����J��
	UFUNCTION(BlueprintCallable, Category = "Mail")
	void Open(const FMailData &InData);

protected:

	// ���[�����J����
	UFUNCTION(BlueprintNativeEvent, Category = "Mail")
	void OnOpen();
	void OnOpen_Implementation() {}

	// �f�[�^���擾.
	UFUNCTION(BlueprintPure, Category = "Mail")
	const FMailData &GetData() const { return Data; }

private:
	
	// �f�[�^
	FMailData Data;

};
