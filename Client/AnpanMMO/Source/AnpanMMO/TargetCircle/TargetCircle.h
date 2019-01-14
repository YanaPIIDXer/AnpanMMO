// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetCircle.generated.h"

class ACharacterBase;

/**
 * ターゲットサークル
 */
UCLASS()
class ANPANMMO_API ATargetCircle : public AActor
{

	GENERATED_BODY()
	
public:	

	// コンストラクタ
	ATargetCircle(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~ATargetCircle() {}

	// キャラクタをセット。
	void SetCharacter(ACharacterBase *pInCharacter);

	// 毎フレームの処理.
	virtual void Tick(float DeltaTime) override;
	
private:

	// アセットパス
	static const TCHAR *AssetPath;

	// 高さオフセット
	static const float HeightOffset;

	// １秒間の回転量.
	static const float RotateBySec;

	// StaticMeshComponent
	UPROPERTY()
	UStaticMeshComponent *pMeshCmp;

	// キャラクタ
	TWeakObjectPtr<ACharacterBase> pCharacter;

};
