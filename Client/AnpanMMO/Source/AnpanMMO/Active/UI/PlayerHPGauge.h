// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHPGauge.generated.h"

/**
 * プレイヤーＨＰゲージ
 */
UCLASS()
class ANPANMMO_API UPlayerHPGauge : public UUserWidget
{

	GENERATED_BODY()

public:

	// コンストラクタ
	UPlayerHPGauge(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UPlayerHPGauge() {}

	// 毎フレームの処理.
	virtual void NativeTick(const FGeometry &InGeometry, float InDeltaTime) override;

	// 初期化.
	UFUNCTION(BlueprintCallable, Category = "HPGauge")
	void Init(int32 InCurrentHp, int32 InMaxHp);

	// リスポンした。
	UFUNCTION(BlueprintCallable, Category = "HPGauge")
	void Respawn();
	
	// ダメージを受けた。
	UFUNCTION(BlueprintCallable, Category = "HPGauge")
	void Damaged(int32 Value);

	// 回復した。
	UFUNCTION(BlueprintCallable, Category = "HpGauge")
	void Healed(int32 Value);

	// レベルアップ
	UFUNCTION(BlueprintCallable, Category = "HPGauge")
	void LevelUp(int32 InMaxHp);

protected:

	// プログレスバーにブチ込むレート
	UPROPERTY(BlueprintReadOnly, Category = "HPGauge")
	float ProgressRate;

private:

	// 変化時間.
	static const float MutateTime;

	// 現在のＨＰ
	int32 CurrentHp;

	// 以前のＨＰ
	int32 PrevHp;

	// 最大ＨＰ
	int32 MaxHp;

	// 現在の時間.
	float CurrentTime;
	
};
