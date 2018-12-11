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
	static USimpleDialog *ShowSimpleDialog(UObject *pOuter, const FString &DisplayText, int32 ZOrder = 0);

	// はい・いいえのダイアログを表示.
	UFUNCTION(BlueprintCallable, Category = "Dialog", meta = (WorldContext = pOuter))
	static UYesNoDialog *ShowYesNoDialog(UObject *pOuter, const FString &DisplayText, int32 ZOrder = 0);

	// エフェクト生成.
	UFUNCTION(BlueprintCallable, Category = "Effect", meta = (WorldContext = pWorldContext))
	static AEmitter *SpawnEffect(UObject *pWorldContext, UParticleSystem *pParticle, const FVector &Position, const FRotator &Rotation);
	
	// ランダムなベクトルを取得.
	UFUNCTION(BlueprintPure, Category = "Math")
	static FVector GetRandomVector(float Min, float Max);
	
	// リスポンリクエスト送信.
	UFUNCTION(BlueprintCallable, Category = "Respawn", meta = (WorldContext = pWorldContext))
	static void SendRespawnRequest(UObject *pWorldContext);

	// スキル名を取得.
	UFUNCTION(BlueprintPure, Category = "Skill")
	static FString GetSkillName(int32 SkillId);

	// リキャストタイムを取得.
	UFUNCTION(BlueprintPure, Category = "Skill")
	static int32 GetRecastTime(int32 SkillId);

};
