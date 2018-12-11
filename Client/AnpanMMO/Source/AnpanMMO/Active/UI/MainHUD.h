// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainHUD.generated.h"

class AGameCharacter;
class NoticeData;

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

	// �񕜂����B
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "MainHUD")
	void OnHeal(int32 Value);
	void OnHeal_Implementation(int32 Value) {}

	// �^�[�Q�b�g���ύX���ꂽ�B
	UFUNCTION(BlueprintNativeEvent, Category = "Target")
	void OnTargetChanged(ACharacterBase *pCharacter);
	void OnTargetChanged_Implementation(ACharacterBase *pCharacter) {}

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

	// �X�L�����X�g����M�����B
	UFUNCTION(BlueprintNativeEvent, Category = "Skill")
	void OnRecvSkillList(int32 NormalAttack, int32 Skill1, int32 Skill2, int32 Skill3, int32 Skill4);
	void OnRecvSkillList_Implementation(int32 NormalAttack, int32 Skill1, int32 Skill2, int32 Skill3, int32 Skill4) {}

	// �ʒm����M�����B
	void OnRecvNotice(int32 Uuid, const NoticeData &Data);

	// ���O�A�E�g
	UFUNCTION(BlueprintNativeEvent, Category = "Menu")
	void OnLogOut();
	void OnLogOut_Implementation() {}

protected:

	// �U���{�^���������ꂽ�B
	UFUNCTION(BlueprintCallable, Category = "Attack")
	void OnPressedAttackButton();

	// ���x�����[�h�J�n.
	UFUNCTION(BlueprintCallable, Category = "MapChange")
	void StartLevelLoad();

	// �Q�[�����j���[��\��.
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void ShowGameMenu();

	// ���ǒʒm�����邩�H
	UFUNCTION(BlueprintPure, Category = "Notice")
	bool HasNotReadNotice() const { return (NotReadNoticeCount > 0); }

	// �ʒm���j���[��\��.
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void ShowNoticeMenu();

	// ���ǒʒm�̐�.
	UPROPERTY(BlueprintReadOnly, Category = "Notice")
	int32 NotReadNoticeCount;

private:
	
	// Blueprint�̃A�Z�b�g�p�X
	static const TCHAR *AssetPath;

	// �L�����N�^
	TWeakObjectPtr<AGameCharacter> pCharacter;

};
