// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainHUD.generated.h"

class AGameCharacter;

/**
 * ���C��HUD
 */
UCLASS()
class ANPANMMO_API UMainHUD : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// �\��.
	static UMainHUD *Show(UObject *pOuter);

	// �R���X�g���N�^
	UMainHUD(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UMainHUD() {}

	// �J�n���̏���.
	virtual void NativeConstruct() override;

	// ������.
	UFUNCTION(BlueprintNativeEvent, Category = "MainHUD")
	void OnInitialize();
	void OnInitialize_Implementation() {}

protected:

	// �U���{�^���������ꂽ�B
	UFUNCTION(BlueprintCallable, Category = "Attack")
	void OnPressedAttackButton();

private:
	
	// Blueprint�̃A�Z�b�g�p�X
	static const TCHAR *AssetPath;

	// �L�����N�^
	TWeakObjectPtr<AGameCharacter> pCharacter;
	
};
