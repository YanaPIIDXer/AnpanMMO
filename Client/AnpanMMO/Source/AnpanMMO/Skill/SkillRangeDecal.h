// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Character/CharacterBase.h"
#include "SkillRangeDecal.generated.h"

class UDecalComponent;
class UMaterialInstanceDynamic;

/**
 * スキルの範囲表示デカール
 */
UCLASS()
class ANPANMMO_API ASkillRangeDecal : public AActor
{

	GENERATED_BODY()
	
public:	
	
	// Spawn
	static ASkillRangeDecal *Spawn(UWorld *pWorld, const FVector &CharacterPos, const FRotator &CharacterRot, ECharacterType CharacterType, uint32 SkillId);

	// コンストラクタ
	ASkillRangeDecal(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~ASkillRangeDecal() {}

	// 毎フレームの処理.
	virtual void Tick(float DeltaTime) override;

private:

	// 円形マテリアルパス
	static const TCHAR *CircleMaterialPath;

	// 矩形マテリアルパス
	static const TCHAR *BoxMaterialPath;

	// 色パラメータ名.
	static const FName ColorParamName;

	// αパラメータ名.
	static const FName AlphaParamName;

	// 攻撃スキルの色.
	static const FLinearColor AttackColor;

	// 回復スキルの色.
	static const FLinearColor HealColor;

	// 敵の攻撃スキルの色.
	static const FLinearColor EnemyAttackColor;

	// 敵の回復スキルの色.
	static const FLinearColor EnemyHealColor;

	// スケーリングにかかる時間.
	static const float ScaleAnimationTime;

	// DecalComponent
	UPROPERTY()
	UDecalComponent *pDecalComponent;

	// マテリアル
	UPROPERTY()
	UMaterialInstanceDynamic *pMaterial;

	// 色.
	FLinearColor Color;

	// 現在の幅.
	float CurrentWidth;

	// 現在の高さ.
	float CurrentHeight;

	// デカールの幅
	float DecalWidth;

	// デカールの高さ
	float DecalHeight;

	// 経過時間.
	float ElapsedTime;

	// α値.
	float Alpha;


	// セットアップ
	void Setup(ECharacterType CharacterType, uint32 SkillId);

};
