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
	virtual void OnRecvPacket(uint8 ID) override;

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
