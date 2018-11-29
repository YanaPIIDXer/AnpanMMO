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
	void OnHUDInitialize();
	void OnHUDInitialize_Implementation() {}

	// �_���[�W���󂯂��B
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "MainHUD")
	void OnDamaged(int32 Value);
	void OnDamaged_Implementation(int32 Value) {}

	// ���X�|�������B
	UFUNCTION(BlueprintNativeEvent, Category = "Respawn")
	void OnRespawn();
	void OnRespawn_Implementation() {}

	// ���x���A�b�v�����B
	UFUNCTION(BlueprintNativeEvent, Category = "LevelUp")
	void OnLevelUp();
	void OnLevelUp_Implementation() {}

	// �}�b�v�`�F���W�J�n.
	UFUNCTION(BlueprintNativeEvent, Category = "MapChange")
	void OnStartMapChange();
	void OnStartMapChange_Implementation() {}

	// �}�b�v�ړ������������B
	UFUNCTION(BlueprintNativeEvent, Category = "MapChange")
	void OnRecvMapChangeFinished();
	void OnRecvMapChangeFinished_Implementation() {}

	// �`���b�g����M�����B
	UFUNCTION(BlueprintNativeEvent, Category = "Chat")
	void OnRecvChat(const FString &Name, const FString &Message, bool bIsSelf);
	void OnRecvChat_Implementation(const FString &Name, const FString &Message, bool bIsSelf) {}

protected:

	// �U���{�^���������ꂽ�B
	UFUNCTION(BlueprintCallable, Category = "Attack")
	void OnPressedAttackButton();

	// ���x�����[�h�J�n.
	UFUNCTION(BlueprintCallable, Category = "MapChange")
	void StartLevelLoad();

	// �Q�[�����j���[�\��.
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void ShowGameMenu();

private:
	
	// Blueprint�̃A�Z�b�g�p�X
	static const TCHAR *AssetPath;

	// �L�����N�^
	TWeakObjectPtr<AGameCharacter> pCharacter;
	
};
