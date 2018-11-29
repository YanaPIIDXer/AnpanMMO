// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "NoticeMenuWidget.generated.h"

/**
 * �ʒm���N���X
 */
UCLASS(Abstract, BlueprintType)
class UNoticeBase : public UObject
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	UNoticeBase(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UNoticeBase() {}

	// �ʒm�ɑ΂���s��.
	UFUNCTION(BlueprintCallable, Category = "Notice")
	virtual void Action() {}

protected:

	// �J�X�^�}�h�c
	uint32 CustomerId;

};

/**
 * �p�[�e�B���U�ʒm.
 */
UCLASS(BlueprintType)
class UPartyInviteNotice : public UNoticeBase
{

	GENERATED_BODY()

public:

	// ����.
	static UPartyInviteNotice *Create(uint32 CustomerId);

	// �R���X�g���N�^
	UPartyInviteNotice(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UPartyInviteNotice() {}

	// �ʒm�ɑ΂���s��.
	virtual void Action() override;

};

/**
 * �ʒm���j���[�̃A�C�e��
 */
UCLASS()
class ANPANMMO_API UNoticeMenuItem : public UUserWidget
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	UNoticeMenuItem(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UNoticeMenuItem() {}

	// �ʒm���Z�b�g�B
	UFUNCTION(BlueprintCallable, Category = "Notice")
	void SetNotice(UNoticeBase *pInNotice) { pNotice = pInNotice; }

protected:

	// �ʒm�ɑ΂���s��.
	UFUNCTION(BlueprintCallable, Category = "Notice")
	void Action();

private:

	// �ʒm.
	UPROPERTY()
	UNoticeBase *pNotice;

};

/**
 * �ʒm���j���[
 */
UCLASS()
class ANPANMMO_API UNoticeMenuWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// �\��.
	static void ShowWidget(UObject *pOuter);

	// �R���X�g���N�^
	UNoticeMenuWidget(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UNoticeMenuWidget() {}

	// �J�n���̏���.
	virtual void NativeConstruct() override;

protected:

	// �ʒm���X�g
	UPROPERTY(BlueprintReadOnly, Category = "Notice")
	TArray<UNoticeBase *> NoticeList;

private:

	// �A�Z�b�g�p�X
	static const TCHAR *AssetPath;
	
};
