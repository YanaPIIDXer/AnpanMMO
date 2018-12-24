// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacterBase.h"
#include "PlayerStatus.h"
#include "PlayerMove.h"
#include "Skill/SkillControl.h"
#include "GameCharacter.generated.h"

class UFloatingPawnMovement;
class USkeletalMeshComponent;

/**
 * �v���C���[�L�����N�^�N���X
 */
UCLASS()
class ANPANMMO_API AGameCharacter : public APlayerCharacterBase
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	AGameCharacter(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~AGameCharacter() {}

	// �J�n���̏���.
	virtual void BeginPlay() override;

	// ���t���[���̏���.
	virtual void Tick(float DeltaTime) override;

	// �X�e�[�^�X�擾.
	const PlayerStatus &GetStatus() const { return Status; }

	// �o���l����M�����B
	void OnRecvExp(int32 Exp);

	// ���x���A�b�v����M�����B
	void OnRecvLevelUp(uint32 Level, int32 MaxHp, int32 Atk, int32 Def);

	// �ړ��x�N�g���̎擾.
	virtual FVector GetMoveVector() const override;

	// UUID���擾.
	virtual uint32 GetUuid() const override { return Status.GetUuid(); }

	// �L�����N�^�����擾.
	virtual FString GetCharacterName() const override { return Status.GetName(); }
	
	// �L�����N�^�^�C�v���擾.
	virtual ECharacterType GetCharacterType() const override { return ECharacterType::Player; }

	// �X�L�����g�p�\���H
	UFUNCTION(BlueprintPure, Category = "Skill")
	bool IsSkillUsable(int32 SkillId) const;

	// �A�C�e�����g�p�\���H
	UFUNCTION(BlueprintPure, Category = "ItemShortcut")
	bool IsItemUsable(int32 ItemId) const;

	// �X�L���g�p.
	UFUNCTION(BlueprintCallable, Category = "Skill")
	void UseSkill(int32 SkillId);

	// �A�C�e���g�p.
	UFUNCTION(BlueprintCallable, Category = "ItemShortcut")
	void UseItem(int32 ItemId);
	
	// �ʏ�U���X�L�����g�p.
	void UseNormalAttackSkill();

	// �X�L������I�u�W�F�N�g���擾.
	const SkillControl &GetSkillControl() const { return Skill; }

	// �X�L���L���X�g�����������B
	virtual void OnSkillCastFinished() override;

	// �X�L����������M�����B
	virtual void OnSkillActivate() override;

	// �X�L���L�����Z��
	void OnSkillCancel();

	// �S�[���h���擾.
	UFUNCTION(BlueprintPure, Category = "Gold")
	int32 GetGold() const { return Status.GetGold(); }

	// �S�[���h���Z�b�g
	void SetGold(uint32 Gold) { Status.SetGold(Gold); }

	// �X�L���c���[�m�[�h���J��.
	void OpenSkillTreeNode(uint32 NodeId);

	// �X�L�����X�g����M�����B
	void OnRecvSkillList(uint32 SkillId1, uint32 SkillId2, uint32 SkillId3, uint32 SkillId4);

	// ���x�����擾.
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetLevel() const { return Status.GetLevel(); }

	// �A�C�e���ǉ�.
	void AddItem(uint32 ItemId, uint32 Count) { Status.AddItem(ItemId, Count); }

	// �A�C�e���폜.
	void SubtractItem(uint32 ItemId, uint32 Count) { Status.SubtractItem(ItemId, Count); }

	// �A�C�e���V���[�g�J�b�g���X�V.
	void UpdateItemShortcut(uint32 ItemId1, uint32 ItemId2);

	// BP�����ɃA�C�e���V���[�g�J�b�g���擾.
	UFUNCTION(BlueprintCallable, Category = "ItemShortcut")
	TArray<int32> GetItemShortcutForBlurprint();

	// �A�C�e�������擾.
	UFUNCTION(BlueprintPure, Category = "Item")
	int32 GetItemCount(int32 ItemId) const { return Status.GetItemList().GetCount(ItemId); }

protected:

	// ���x���A�b�v����
	UFUNCTION(BlueprintNativeEvent, Category = "Character")
	void OnLevelUp();
	void OnLevelUp_Implementation() {}

	// ���X�|�������B
	virtual void OnRespawn() override;

private:

	// �X�e�[�^�X
	PlayerStatus Status;

	// �ړ��p�P�b�g����.
	PlayerMove Move;

	// �X�L������.
	SkillControl Skill;

	// MainHUD���������������H
	bool bInitializedMainHUD;


	// �X�L���^�[�Q�b�g�擾.
	ACharacterBase *GetSkillTarget(uint32 SkillId);

	// MainHUD�̏�����.
	void InitializeMainHUD();

};
