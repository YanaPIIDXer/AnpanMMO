// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "MailMenu.generated.h"

// ���[���t���O
UENUM(BlueprintType)
enum class EMailFlag : uint8
{
	// ����.
	NotRead,

	// ����.
	Read,

	// �Y�t����M�ς�
	RecvAttachment,
};

// ���[���Y�t���̎��.
UENUM(BlueprintType)
enum class EMailAttachmentType : uint8
{
	// ����
	None,

	// �A�C�e��
	Item,

	// �S�[���h
	Gold,
};

class MailData;

// ���[���f�[�^
USTRUCT(BlueprintType)
struct FMailData
{

	GENERATED_USTRUCT_BODY()

public:

	// ID
	uint32 Id;

	// ����.
	UPROPERTY(BlueprintReadOnly)
	FString Subject;

	// �{��.
	UPROPERTY(BlueprintReadOnly)
	FString Body;

	// �t���O
	UPROPERTY(BlueprintReadOnly)
	EMailFlag Flag;

	// �Y�t���^�C�v
	UPROPERTY(BlueprintReadOnly)
	EMailAttachmentType AttachmentType;

	// �Y�t���A�C�e����.
	UPROPERTY(BlueprintReadOnly)
	FString AttachmentItemName;

	// �Y�t����.
	UPROPERTY(BlueprintReadOnly)
	int32 AttachmentCount;


	// �R���X�g���N�^
	FMailData() {}
	FMailData(const MailData &Source);

};

/**
 * ���[�����j���[
 */
UCLASS()
class ANPANMMO_API UMailMenu : public ULayeredMenuWidgetBase
{
	GENERATED_BODY()
		
public:

	// �R���X�g���N�^
	UMailMenu(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UMailMenu() {}

	// ���[�����X�g�v��.
	UFUNCTION(BlueprintCallable, Category = "Mail")
	void SendMailListRequest();

	// �p�P�b�g����M�����B
	virtual void OnRecvPacket(uint8 ID, MemoryStreamInterface *pStream) override;

protected:

	// �qWidget����߂��Ă������̏���.
	virtual void OnBackFromChild_Implementation() override;

	// �������C�x���g
	UFUNCTION(BlueprintNativeEvent, Category = "Mail")
	void OnInit(const TArray<FMailData> &MailList);
	void OnInit_Implementation(const TArray<FMailData> &MailList) {}

private:

	// ������.
	void Init();

};
