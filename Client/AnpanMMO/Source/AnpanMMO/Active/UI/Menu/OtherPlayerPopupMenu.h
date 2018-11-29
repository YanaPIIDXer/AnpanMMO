// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OtherPlayerPopupMenu.generated.h"

class AOtherPlayerCharacter;

/**
 * ���l�Ɋւ���|�b�v�A�b�v���j���[
 */
UCLASS()
class ANPANMMO_API UOtherPlayerPopupMenu : public UUserWidget
{

	GENERATED_BODY()

public:

	// �\��.
	static UOtherPlayerPopupMenu *Show(UObject *pOuter, AOtherPlayerCharacter *pCharacter);

	// �R���X�g���N�^
	UOtherPlayerPopupMenu(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UOtherPlayerPopupMenu() {}

protected:

	// �p�[�e�B�Ɋ��U�ł��邩�H
	UFUNCTION(BlueprintPure, Category = "Party")
	bool IsAblePartyInvite() const;

	// �p�[�e�B���U�𑗐M.
	UFUNCTION(BlueprintCallable, Category = "Party")
	void SendPartyInvite();

	// ���j���[������.
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void EraseMenu();


	// �L�����N�^��.
	UPROPERTY(BlueprintReadOnly, Category = "Character")
	FString CharacterName;

private:

	// �A�Z�b�g�p�X
	static const TCHAR *AssetPath;

	// �L������UUID
	uint32 CharacterUuid;
	
};
