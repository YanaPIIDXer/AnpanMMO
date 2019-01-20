// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Buff/BuffIcon.h"
#include "MainHUD.generated.h"

class AGameCharacter;
class NoticeData;
class QuestData;

// クエストタイプ
UENUM(BlueprintType)
enum class EQuestType : uint8
{
	// 何もない
	None,

	// NPCに話しかける
	TalkNPC,

	// アンパンをブッ殺す
	KillAnpan,

	// アイテム収集.
	CollectItem,
};

/**
 * メインHUD
 */
UCLASS()
class ANPANMMO_API UMainHUD : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// 表示.
	static UMainHUD *Show(UObject *pOuter);

	// コンストラクタ
	UMainHUD(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UMainHUD() {}

	// 開始時の処理.
	virtual void NativeConstruct() override;

	// 初期化.
	UFUNCTION(BlueprintNativeEvent, Category = "MainHUD")
	void OnHUDInitialize();
	void OnHUDInitialize_Implementation() {}

	// ダメージを受けた。
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "MainHUD")
	void OnDamaged(int32 Value);
	void OnDamaged_Implementation(int32 Value) {}

	// 回復した。
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "MainHUD")
	void OnHeal(int32 Value);
	void OnHeal_Implementation(int32 Value) {}

	// ターゲットが変更された。
	UFUNCTION(BlueprintNativeEvent, Category = "Target")
	void OnTargetChanged(ACharacterBase *pCharacter);
	void OnTargetChanged_Implementation(ACharacterBase *pCharacter) {}

	// リスポンした。
	UFUNCTION(BlueprintNativeEvent, Category = "Respawn")
	void OnRespawn();
	void OnRespawn_Implementation() {}

	// レベルアップした。
	UFUNCTION(BlueprintNativeEvent, Category = "LevelUp")
	void OnLevelUp();
	void OnLevelUp_Implementation() {}

	// マップチェンジ開始.
	UFUNCTION(BlueprintNativeEvent, Category = "MapChange")
	void OnStartMapChange();
	void OnStartMapChange_Implementation() {}

	// マップ移動が完了した。
	UFUNCTION(BlueprintNativeEvent, Category = "MapChange")
	void OnRecvMapChangeFinished();
	void OnRecvMapChangeFinished_Implementation() {}

	// チャットを受信した。
	UFUNCTION(BlueprintNativeEvent, Category = "Chat")
	void OnRecvChat(const FString &Name, const FString &Message, bool bIsSelf);
	void OnRecvChat_Implementation(const FString &Name, const FString &Message, bool bIsSelf) {}

	// システムメッセージを表示.
	UFUNCTION(BlueprintNativeEvent, Category = "Chat")
	void ShowSystemMessage(const FString &Message);
	void ShowSystemMessage_Implementation(const FString &Message) {}

	// スキルリストを受信した。
	UFUNCTION(BlueprintNativeEvent, Category = "Skill")
	void OnRecvSkillList(int32 NormalAttack, int32 Skill1, int32 Skill2, int32 Skill3, int32 Skill4);
	void OnRecvSkillList_Implementation(int32 NormalAttack, int32 Skill1, int32 Skill2, int32 Skill3, int32 Skill4) {}

	// リキャスト開始.
	UFUNCTION(BlueprintNativeEvent, Category = "Skill")
	void OnStartRecast(int32 SkillId);
	void OnStartRecast_Implementation(int32 SkillId) {}

	// リキャストが完了した。
	UFUNCTION(BlueprintNativeEvent, Category = "Skill")
	void OnRecvSkillRecastFinished(int32 SkillId);
	void OnRecvSkillRecastFinished_Implementation(int32 SkillId) {}

	// アイテムショートカット更新.
	void UpdateItemShortcut();

	// 通知を受信した。
	void OnRecvNotice(int32 Uuid, const NoticeData &Data);

	// ログアウト
	UFUNCTION(BlueprintNativeEvent, Category = "Menu")
	void OnLogOut();
	void OnLogOut_Implementation() {}

	// バフ追加。
	void AddBuff(uint32 BuffId);

	// バフ消去.
	void RemoveBuff(uint8 Type);

protected:

	// レベルロード開始.
	UFUNCTION(BlueprintCallable, Category = "MapChange")
	void StartLevelLoad();

	// ゲームメニューを表示.
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void ShowGameMenu();

	// 未読通知があるか？
	UFUNCTION(BlueprintPure, Category = "Notice")
	bool HasNotReadNotice() const { return (NotReadNoticeCount > 0); }

	// 通知メニューを表示.
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void ShowNoticeMenu();

	// 未読通知の数.
	UPROPERTY(BlueprintReadOnly, Category = "Notice")
	int32 NotReadNoticeCount;

	// アイテムショートカット更新.
	UFUNCTION(BlueprintNativeEvent, Category = "ItemShortcut")
	void OnUpdateItemShortcut(const TArray<int32> &ItemShortcut);
	void OnUpdateItemShortcut_Implementation(const TArray<int32> &ItemShortcut) {}

	// アクティブクエストが更新された。
	UFUNCTION(BlueprintNativeEvent, Category = "Quest")
	void OnActiveQuestUpdatedEvent(EQuestType Type, int32 TargetId, int32 CurrentCount, int32 MaxCount);
	void OnActiveQuestUpdatedEvent_Implementation(EQuestType Type, int32 TargetId, int32 CurrentCount, int32 MaxCount) {}

	// アクティブクエストの情報を表示.
	UFUNCTION(BlueprintCallable, Category = "Quest")
	void ShowActiveQuestData();

	// バフ追加。
	UFUNCTION(BlueprintNativeEvent, Category = "Buff")
	void OnAddBuff(EBuffType Type, float Time);
	void OnAddBuff_Implementation(EBuffType Type, float Time) {}
	
	// バフ消去.
	UFUNCTION(BlueprintNativeEvent, Category = "Buff")
	void OnRemoveBuff(EBuffType Type);
	void OnRemoveBuff_Implementation(EBuffType Type) {}

private:
	
	// Blueprintのアセットパス
	static const TCHAR *AssetPath;

	// キャラクタ
	TWeakObjectPtr<AGameCharacter> pCharacter;


	// アクティブクエストが更新された。
	void OnActiveQuestUpdated(const QuestData *pQuestData);

	// バフタイプをenumに変換。
	static EBuffType BuffTypeToEnum(uint8 Type);

};
