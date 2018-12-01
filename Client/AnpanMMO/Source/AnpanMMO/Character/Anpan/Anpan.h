// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Anpan.generated.h"

class AnpanData;
class AAnpanController;

/**
 * アンパンクラス
 */
UCLASS()
class ANPANMMO_API AAnpan : public ACharacterBase
{

	GENERATED_BODY()
	
public:	

	// 生成.
	static AAnpan *Spawn(UWorld *pWorld, const AnpanData &Data);

	// コンストラクタ
	AAnpan(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~AAnpan() {}

	// 開始時の処理.
	virtual void BeginPlay() override;

	// コントローラと紐付けられた。
	virtual void PossessedBy(AController *NewController) override;

	// UUID取得.
	uint32 GetUuid() const { return Uuid; }

	// 移動.
	void Move(float X, float Y, float Z, int32 Time);

	// 回転.
	void Rotate(float Rotation, int32 Time);

	// 停止.
	void Stop(float X, float Y, float Z, float Rotation);

protected:

	// 足元の座標を取得.
	UFUNCTION(BlueprintPure, Category = "Anpan")
	FVector GetFootPosition() const;


	// 拡縮倍率.
	UPROPERTY(BlueprintReadOnly, Category = "Anpan")
	float ScaleRate;

private:

	// 半径基準値.
	static const float BaseRadius;

	// メッシュのパス
	static const TCHAR *MeshPath;

	// Blueprintのパス
	static const TCHAR *BlueprintPath;

	// メッシュComponent
	UPROPERTY()
	UStaticMeshComponent *pMeshComponent;

	// コントローラ
	TWeakObjectPtr<AAnpanController> pController;

	// UUID
	uint32 Uuid;
	
};
