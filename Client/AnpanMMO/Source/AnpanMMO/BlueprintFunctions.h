// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintFunctions.generated.h"

class USimpleDialog;

/**
 * Blueprint用関数群.
 */
UCLASS()
class ANPANMMO_API UBlueprintFunctions : public UBlueprintFunctionLibrary
{

	GENERATED_BODY()
	
public:
	
	// 単純なダイアログを表示.
	UFUNCTION(BlueprintCallable, Category = "Dialog", meta = (WorldContext = pOuter))
	static USimpleDialog *ShowSimpleDialog(UObject *pOuter, const FString &DisplayText);

	// エフェクト生成.
	UFUNCTION(BlueprintCallable, Category = "Effect", meta = (WorldContext = pWorldContext))
	static AEmitter *SpawnEffect(UObject *pWorldContext, UParticleSystem *pParticle, const FVector &Position, const FRotator &Rotation);
	
	// ランダムなベクトルを取得.
	UFUNCTION(BlueprintPure, Category = "Math")
	static FVector GetRandomVector(float Min, float Max);

};
