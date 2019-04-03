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
	void Open(const FMailData &Data);

protected:

	// ���[�����J����
	UFUNCTION(BlueprintNativeEvent, Category = "Mail")
	void OnOpen();
	void OnOpen_Implementation() {}

	// �������擾.
	UFUNCTION(BlueprintPure, Category = "Mail")
	const FString &GetSubject() const { return Subject; }

	// �{�����擾.
	UFUNCTION(BlueprintPure, Category = "Mail")
	const FString &GetBody() const { return Body; }

private:
	
	// ����.
	FString Subject;

	// �{��.
	FString Body;

};
