// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Buff/BuffIcon.h"
#include "MainHUD.generated.h"

class AGameCharacter;
class NoticeData;
class QuestData;

// �N�G�X�g�^�C�v
UENUM(BlueprintType)
enum class EQuestType : uint8
{
	// �����Ȃ�
	None,

	// NPC�ɘb��������
	TalkNPC,

	// �A���p�����u�b�E��
	KillAnpan,

	// �A�C�e�����W.
	CollectItem,
};

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

	// �V�X�e�����b�Z�[�W��\��.
	UFUNCTION(BlueprintNativeEvent, Category = "Chat")
	void ShowSystemMessage(const FString &Message);
	void ShowSystemMessage_Implementation(const FString &Message) {}

	// �X�L�����X�g����M�����B
	UFUNCTION(BlueprintNativeEvent, Category = "Skill")
	void OnRecvSkillList(int32 NormalAttack, int32 Skill1, int32 Skill2, int32 Skill3, int32 Skill4);
	void OnRecvSkillList_Implementation(int32 NormalAttack, int32 Skill1, int32 Skill2, int32 Skill3, int32 Skill4) {}

	// ���L���X�g�J�n.
	UFUNCTION(BlueprintNativeEvent, Category = "Skill")
	void OnStartRecast(int32 SkillId);
	void OnStartRecast_Implementation(int32 SkillId) {}

	// ���L���X�g�����������B
	UFUNCTION(BlueprintNativeEvent, Category = "Skill")
	void OnRecvSkillRecastFinished(int32 SkillId);
	void OnRecvSkillRecastFinished_Implementation(int32 SkillId) {}

	// �A�C�e���V���[�g�J�b�g�X�V.
	void UpdateItemShortcut();

	// �ʒm����M�����B
	void OnRecvNotice(int32 Uuid, const NoticeData &Data);

	// ���O�A�E�g
	UFUNCTION(BlueprintNativeEvent, Category = "Menu")
	void OnLogOut();
	void OnLogOut_Implementation() {}

	// �o�t�ǉ��B
	void AddBuff(uint32 BuffId);

	// �o�t����.
	void RemoveBuff(uint8 Type);

protected:

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

	// �A�C�e���V���[�g�J�b�g�X�V.
	UFUNCTION(BlueprintNativeEvent, Category = "ItemShortcut")
	void OnUpdateItemShortcut(const TArray<int32> &ItemShortcut);
	void OnUpdateItemShortcut_Implementation(const TArray<int32> &ItemShortcut) {}

	// �A�N�e�B�u�N�G�X�g���X�V���ꂽ�B
	UFUNCTION(BlueprintNativeEvent, Category = "Quest")
	void OnActiveQuestUpdatedEvent(EQuestType Type, int32 TargetId, int32 CurrentCount, int32 MaxCount);
	void OnActiveQuestUpdatedEvent_Implementation(EQuestType Type, int32 TargetId, int32 CurrentCount, int32 MaxCount) {}

	// �A�N�e�B�u�N�G�X�g�̏���\��.
	UFUNCTION(BlueprintCallable, Category = "Quest")
	void ShowActiveQuestData();

	// �o�t�ǉ��B
	UFUNCTION(BlueprintNativeEvent, Category = "Buff")
	void OnAddBuff(EBuffType Type, float Time);
	void OnAddBuff_Implementation(EBuffType Type, float Time) {}
	
	// �o�t����.
	UFUNCTION(BlueprintNativeEvent, Category = "Buff")
	void OnRemoveBuff(EBuffType Type);
	void OnRemoveBuff_Implementation(EBuffType Type) {}

private:
	
	// Blueprint�̃A�Z�b�g�p�X
	static const TCHAR *AssetPath;

	// �L�����N�^
	TWeakObjectPtr<AGameCharacter> pCharacter;


	// �A�N�e�B�u�N�G�X�g���X�V���ꂽ�B
	void OnActiveQuestUpdated(const QuestData *pQuestData);

	// �o�t�^�C�v��enum�ɕϊ��B
	static EBuffType BuffTypeToEnum(uint8 Type);

};
