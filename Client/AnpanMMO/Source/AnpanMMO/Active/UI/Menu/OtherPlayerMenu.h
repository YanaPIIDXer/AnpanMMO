// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OtherPlayerMenu.generated.h"

class AOtherPlayerCharacter;

/**
 * ���l�Ɋւ���|�b�v�A�b�v���j���[
 */
UCLASS()
class ANPANMMO_API UOtherPlayerMenu : public UUserWidget
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	UOtherPlayerMenu(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UOtherPlayerMenu() {}

	// �Z�b�g�A�b�v
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void Setup(AOtherPlayerCharacter *pCharacter);

protected:

	// �p�[�e�B�Ɋ��U�ł��邩�H
	UFUNCTION(BlueprintPure, Category = "Party")
	bool IsAblePartyInvite() const;

	// �p�[�e�B���U�𑗐M.
	UFUNCTION(BlueprintCallable, Category = "Party")
	void SendPartyInvite();


	// �L�����N�^��.
	UPROPERTY(BlueprintReadOnly, Category = "Character")
	FString CharacterName;

private:

	// �L������UUID
	uint32 CharacterUuid;
	
};
