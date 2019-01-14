// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "NoticeMenuWidget.generated.h"

// �ʒm�^�C�v
// ��NoticeData�̒�`�ƍ��킹�鎖�B
UENUM(BlueprintType)
enum class ENoticeType : uint8
{
	// �_�~�[�̒�`.
	None,

	// �p�[�e�B���U.
	PartyInvite,
};

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
	void Action();

	// �ʒm�^�C�v���擾.
	UFUNCTION(BlueprintPure, Category = "Notice")
	virtual ENoticeType GetNoticeType() const { return ENoticeType::None; }

	// �L�����N�^�����擾.
	UFUNCTION(BlueprintPure, Category = "Notice")
	const FString &GetCharacterName() const { return CharacterName; }

protected:

	// �ʒm�ɑ΂���s��.
	virtual void OnAction() {}


	// �J�X�^�}�h�c
	uint32 CustomerId;

	// �ʒmUUID
	uint32 NoticeUuid;

	// �L�����N�^��.
	FString CharacterName;

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
	static UPartyInviteNotice *Create(UObject *pOuter, uint32 NoticeUuid, uint32 CustomerId, const FString &CharacterName);

	// �R���X�g���N�^
	UPartyInviteNotice(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UPartyInviteNotice() {}

	// �ʒm�^�C�v���擾.
	virtual ENoticeType GetNoticeType() const override { return ENoticeType::PartyInvite; }

	// ���U���󂯂邩�ǂ�����ݒ�.
	void SetAccept(bool bInAccept) { bAccept = bInAccept; }

protected:

	// �ʒm�ɑ΂���s��.
	virtual void OnAction() override;

private:

	// ���U���󂯂邩�H
	bool bAccept;

};

class UNoticeMenuWidget;

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

	// �e��ݒ�.
	UFUNCTION(BlueprintCallable, Category = "Notice")
	void SetParent(UNoticeMenuWidget *pInParent) { pParent = pInParent; }

protected:

	// �ʒm�ɑ΂���s��.
	UFUNCTION(BlueprintCallable, Category = "Notice")
	void Action();


	// �ʒm.
	UPROPERTY(BlueprintReadOnly, Category = "Notice")
	UNoticeBase *pNotice;

private:

	// �e.
	UPROPERTY()
	UNoticeMenuWidget *pParent;

};

/**
 * �p�[�e�B���U�ʒm�A�C�e��
 * �����U���󂯂邩�ǂ�����ݒ肷��K�v�����邽��C++�Œ�`�B
 */
UCLASS()
class ANPANMMO_API UPartyInviteNoticeItem : public UNoticeMenuItem
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	UPartyInviteNoticeItem(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UPartyInviteNoticeItem() {}

protected:

	// ���U���󂯂邩�ǂ�����ݒ�.
	UFUNCTION(BlueprintCallable, Category = "PartyInvite")
	void SetAccept(bool bAccept);

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

	// ���������ꂽ�B
	UFUNCTION(BlueprintNativeEvent, Category = "Menu")
	void OnInit();
	void OnInit_Implementation() {}


	// �ʒm���X�g
	UPROPERTY(BlueprintReadOnly, Category = "Notice")
	TArray<UNoticeBase *> NoticeList;

private:

	// �A�Z�b�g�p�X
	static const TCHAR *AssetPath;
	
};
