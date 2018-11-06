// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AttachableWidget.generated.h"

/**
 * Actorに追従するWidget
 */
UCLASS()
class ANPANMMO_API UAttachableWidget : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// コンストラクタ
	UAttachableWidget(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UAttachableWidget() {}

	// 開始時の処理.
	virtual void NativeConstruct() override;

	// 毎フレームの処理.
	virtual void NativeTick(const FGeometry &InGeometry, float InDeltaTime) override;

	// ターゲットを設定.
	UFUNCTION(BlueprintCallable, Category = "Attachable")
	void SetTarget(AActor *pInTargetActor) { pTargetActor = pInTargetActor; }

	// オフセットを設定.
	UFUNCTION(BlueprintCallable, Category = "Attachable")
	void SetOffset(const FVector &InOffset) { Offset = InOffset; }

protected:

	// 表示状態.
	UPROPERTY(BlueprintReadOnly, Category = "Attachable")
	ESlateVisibility Visible;

	// 表示座標.
	UPROPERTY(BlueprintReadOnly, Category = "Attachable")
	FVector2D DisplayPosition;

private:

	// 対象Actor
	TWeakObjectPtr<AActor> pTargetActor;

	// コントローラ
	TWeakObjectPtr<APlayerController> pController;
	
	// オフセット.
	FVector Offset;

};
