// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/DirectionalLight.h"
#include "Classes/Curves/CurveLinearColor.h"
#include "SkyControl.generated.h"

/**
 * 天球の状態コントロールActor
 */
UCLASS()
class ANPANMMO_API ASkyControl : public AActor
{

	GENERATED_BODY()
	
public:	
	
	// コンストラクタ
	ASkyControl(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~ASkyControl() {}

	// 毎フレームの処理.
	virtual void Tick(float DeltaTime) override;

	// マテリアルの更新.
	void RefleshMaterial();

	// 太陽の方向を更新.
	void UpdateSunDirection();

	// ゲーム外（Editor）でもTickさせるか？
	virtual bool ShouldTickIfViewportsOnly() const override { return true; }

private:

	// スカイスフィアのメッシュ
	UPROPERTY()
	UStaticMeshComponent *pSkySphereMesh;

	// ソースマテリアル
	UPROPERTY()
	UMaterial *pSourceMaterial;

	// 空のマテリアル
	UPROPERTY()
	UMaterialInstanceDynamic *pSkyMaterial;

	// マテリアルを更新するか？
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	bool bRefleshMaterial;

	// ディレクショナルライト
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	ADirectionalLight *pDirectionalLight;

	// 太陽の色の影響を受けるか（？）
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	bool bColorsDeterminedBySun;

	// 太陽光の強さ
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	float SunBrightness;

	// 雲の速度.
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	float CloudSpeed;

	// 雲の透明度.
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	float CloudOpacity;

	// 星の光の強さ
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	float StarsBrightness;

	// 地平線のカラーカーブ
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	UCurveLinearColor *pHorizonColorCurve;
	
	// 天頂のカラーカーブ
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	UCurveLinearColor *pZenithColorCurve;

	// 雲のカラーカーブ
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	UCurveLinearColor *pCloudColorCurve;

	// 太陽の高さ
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	float SunHeight;

	// 地平線の減衰.
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	float HorizonFallOff;

	// 天頂の色.
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	FLinearColor ZenithColor;

	// 地平線の色.
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	FLinearColor HorizonColor;

	// 雲の色.
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	FLinearColor CloudColor;

	// 全部の色.
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	FLinearColor OverallColor;

};
