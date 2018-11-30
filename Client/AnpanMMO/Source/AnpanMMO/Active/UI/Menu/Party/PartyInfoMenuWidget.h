// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "PartyInfoMenuWidget.generated.h"

// �p�[�e�B�f�[�^
USTRUCT(BlueprintType, Category = "Party")
struct FPartyMemberData
{

	GENERATED_USTRUCT_BODY()

public:

	// UUID
	uint32 Uuid;

	// ���O.
	UPROPERTY(BlueprintReadOnly)
	FString Name;

	// ���[�_�[���H
	UPROPERTY(BlueprintReadOnly)
	bool bIsLeader;
};

/**
 * �p�[�e�B��񃁃j���[Widget
 */
UCLASS()
class ANPANMMO_API UPartyInfoMenuWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// ����.
	static UPartyInfoMenuWidget *Create(UObject *pOuter);

	// �R���X�g���N�^
	UPartyInfoMenuWidget(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UPartyInfoMenuWidget() {}

	// �J�n���̏���.
	virtual void NativeConstruct() override;

protected:

	// ������.
	UFUNCTION(BlueprintCallable, Category = "PartyMenu")
	void Init();

	// ���������ꂽ
	UFUNCTION(BlueprintNativeEvent, Category = "Party")
	void OnInit();
	void OnInit_Implementation() {}

	// ���U���N�G�X�g�𑗐M.
	UFUNCTION(BlueprintCallable, Category = "Party")
	void SendDissolutionRequest();

	// ���E���N�G�X�g�𑗐M.
	UFUNCTION(BlueprintCallable, Category = "Party")
	void SendExitRequest();


	// �����o���X�g
	UPROPERTY(BlueprintReadOnly, Category = "Party")
	TArray<FPartyMemberData> MemberList;

	// ���[�_�[���H
	UPROPERTY(BlueprintReadOnly, Category = "Party")
	bool bIsLeader;

private:

	// �A�Z�b�g�p�X
	static const TCHAR *AssetPath;
	
};
