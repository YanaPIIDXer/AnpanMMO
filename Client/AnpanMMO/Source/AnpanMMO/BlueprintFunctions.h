// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintFunctions.generated.h"

class USimpleDialog;

// キャラクタタイプ
UENUM(BlueprintType, Category = "Character")
enum class ECharacterType : uint8
{
	// 自分
	Player,

	// 他人.
	Other,

	// 敵.
	Enemy,
};

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
	
	// リスポンリクエスト送信.
	UFUNCTION(BlueprintCallable, Category = "Respawn", meta = (WorldContext = pWorldContext))
	static void SendRespawnRequest(UObject *pWorldContext);

};
