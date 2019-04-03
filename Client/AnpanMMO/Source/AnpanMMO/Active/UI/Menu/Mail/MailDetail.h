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

	// �p�P�b�g����M�����B
	virtual void OnRecvPacket(uint8 ID, MemoryStreamInterface *pStream) override;

protected:

	// ���[�����J����
	UFUNCTION(BlueprintNativeEvent, Category = "Mail")
	void OnOpen();
	void OnOpen_Implementation() {}

	// �f�[�^���擾.
	UFUNCTION(BlueprintPure, Category = "Mail")
	const FMailData &GetData() const { return Data; }

	// �Y�t����M�v���𑗐M.
	UFUNCTION(BlueprintCallable, Category = "Mail")
	void SendRecvAttachmentRequest();

	// �Y�t�������邩�H
	// ���󒍍ς݂̏ꍇ�ł�true��Ԃ��B
	UFUNCTION(BlueprintPure, Category = "Mail")
	bool HasAttachment() const { return (Data.AttachmentType != EMailAttachmentType::None); }

private:
	
	// �f�[�^
	FMailData Data;

};
