// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BuffIcon.generated.h"

// バフタイプ
UENUM(BlueprintType)
enum class EBuffType : uint8
{
	// 無効.
	Invalid,

	// スピードアップ
	SpeedUp,

	// 自動回復.
	AutoHeal,

	// 毒.
	Poision,

	// 麻痺.
	Paralysis,
};

/**
 * バフアイコン
 */
UCLASS()
class ANPANMMO_API UBuffIcon : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// コンストラクタ
	UBuffIcon(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UBuffIcon() {}

	// セットアップ
	UFUNCTION(BlueprintCallable, Category = "BuffIcon")
	void Setup(EBuffType InType, float Time);

	// 毎フレームの処理.
	virtual void NativeTick(const FGeometry &InGeometry, float InDeltaTime) override;

	// タイプを取得.
	UFUNCTION(BlueprintPure, Category = "BuffIcon")
	EBuffType GetType() const { return Type; }

	// バフか？
	UFUNCTION(BlueprintPure, Category = "BuffIcon")
	bool IsBuff() const;

protected:

	// セットアップ時のイベント
	UFUNCTION(BlueprintNativeEvent, Category = "BuffIcon")
	void OnSetup();
	void OnSetup_Implementation() {}

	// 残り時間のパーセンテージを取得.
	UFUNCTION(BlueprintPure, Category = "BuffIcon")
	float GetLastTimePercentage() const { return (LastTime / BuffTime); }

private:

	// タイプ
	EBuffType Type;

	// バフ継続時間.
	float BuffTime;
	
	// 残り時間.
	float LastTime;

};
