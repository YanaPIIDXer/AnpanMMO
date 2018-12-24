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
 * プレイヤーキャラクタクラス
 */
UCLASS()
class ANPANMMO_API AGameCharacter : public APlayerCharacterBase
{

	GENERATED_BODY()

public:

	// コンストラクタ
	AGameCharacter(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~AGameCharacter() {}

	// 開始時の処理.
	virtual void BeginPlay() override;

	// 毎フレームの処理.
	virtual void Tick(float DeltaTime) override;

	// ステータス取得.
	const PlayerStatus &GetStatus() const { return Status; }

	// 経験値を受信した。
	void OnRecvExp(int32 Exp);

	// レベルアップを受信した。
	void OnRecvLevelUp(uint32 Level, int32 MaxHp, int32 Atk, int32 Def);

	// 移動ベクトルの取得.
	virtual FVector GetMoveVector() const override;

	// UUIDを取得.
	virtual uint32 GetUuid() const override { return Status.GetUuid(); }

	// キャラクタ名を取得.
	virtual FString GetCharacterName() const override { return Status.GetName(); }
	
	// キャラクタタイプを取得.
	virtual ECharacterType GetCharacterType() const override { return ECharacterType::Player; }

	// スキルが使用可能か？
	UFUNCTION(BlueprintPure, Category = "Skill")
	bool IsSkillUsable(int32 SkillId) const;

	// アイテムが使用可能か？
	UFUNCTION(BlueprintPure, Category = "ItemShortcut")
	bool IsItemUsable(int32 ItemId) const;

	// スキル使用.
	UFUNCTION(BlueprintCallable, Category = "Skill")
	void UseSkill(int32 SkillId);

	// アイテム使用.
	UFUNCTION(BlueprintCallable, Category = "ItemShortcut")
	void UseItem(int32 ItemId);
	
	// 通常攻撃スキルを使用.
	void UseNormalAttackSkill();

	// スキル制御オブジェクトを取得.
	const SkillControl &GetSkillControl() const { return Skill; }

	// スキルキャストが完了した。
	virtual void OnSkillCastFinished() override;

	// スキル発動を受信した。
	virtual void OnSkillActivate() override;

	// スキルキャンセル
	void OnSkillCancel();

	// ゴールドを取得.
	UFUNCTION(BlueprintPure, Category = "Gold")
	int32 GetGold() const { return Status.GetGold(); }

	// ゴールドをセット
	void SetGold(uint32 Gold) { Status.SetGold(Gold); }

	// スキルツリーノードを開放.
	void OpenSkillTreeNode(uint32 NodeId);

	// スキルリストを受信した。
	void OnRecvSkillList(uint32 SkillId1, uint32 SkillId2, uint32 SkillId3, uint32 SkillId4);

	// レベルを取得.
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetLevel() const { return Status.GetLevel(); }

	// アイテム追加.
	void AddItem(uint32 ItemId, uint32 Count) { Status.AddItem(ItemId, Count); }

	// アイテム削除.
	void SubtractItem(uint32 ItemId, uint32 Count) { Status.SubtractItem(ItemId, Count); }

	// アイテムショートカットを更新.
	void UpdateItemShortcut(uint32 ItemId1, uint32 ItemId2);

	// BP向けにアイテムショートカットを取得.
	UFUNCTION(BlueprintCallable, Category = "ItemShortcut")
	TArray<int32> GetItemShortcutForBlurprint();

	// アイテム数を取得.
	UFUNCTION(BlueprintPure, Category = "Item")
	int32 GetItemCount(int32 ItemId) const { return Status.GetItemList().GetCount(ItemId); }

protected:

	// レベルアップした
	UFUNCTION(BlueprintNativeEvent, Category = "Character")
	void OnLevelUp();
	void OnLevelUp_Implementation() {}

	// リスポンした。
	virtual void OnRespawn() override;

private:

	// ステータス
	PlayerStatus Status;

	// 移動パケット制御.
	PlayerMove Move;

	// スキル制御.
	SkillControl Skill;

	// MainHUDを初期化したか？
	bool bInitializedMainHUD;


	// スキルターゲット取得.
	ACharacterBase *GetSkillTarget(uint32 SkillId);

	// MainHUDの初期化.
	void InitializeMainHUD();

};
