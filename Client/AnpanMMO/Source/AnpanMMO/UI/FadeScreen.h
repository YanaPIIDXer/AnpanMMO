// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FadeScreen.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFadeFinished);

// フェードモード
UENUM(Blueprintable, Category = "Fade")
enum class EFadeMode : uint8
{
	// なし
	None UMETA(Hidden),

	// フェードイン
	FadeIn,

	// フェードアウト
	FadeOut,
};

/**
 * 画面のフェード
 */
UCLASS()
class ANPANMMO_API UFadeScreen : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// コンストラクタ
	UFadeScreen(const FObjectInitializer &ObjectInitializer);
	
	// デストラクタ
	virtual ~UFadeScreen() {}

	// 毎フレームの処理.
	virtual void NativeTick(const FGeometry &Geometry, float DeltaTime) override;

	// フェード開始.
	UFUNCTION(BlueprintCallable, Category = "Fade")
	void Start(EFadeMode Mode);


	// フェード完了delegate
	UPROPERTY(BlueprintAssignable, Category = "Fade")
	FOnFadeFinished OnFadeFinished;

protected:

	// アルファ値.
	UPROPERTY(BlueprintReadOnly, Category = "Fade")
	float AlphaValue;

private:

	// １秒間のアルファ値変動量.
	static const float AlphaSpeedBySec;

	// フェードモード
	EFadeMode FadeMode;
	
};
