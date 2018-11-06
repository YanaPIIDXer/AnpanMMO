// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Anpan.generated.h"

class AnpanData;

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

	// UUID取得.
	uint32 GetUuid() const { return Uuid; }

private:

	// メッシュのパス
	static const TCHAR *MeshPath;

	// Blueprintのパス
	static const TCHAR *BlueprintPath;

	// メッシュComponent
	UPROPERTY()
	UStaticMeshComponent *pMeshComponent;

	// UUID
	uint32 Uuid;
	
};
