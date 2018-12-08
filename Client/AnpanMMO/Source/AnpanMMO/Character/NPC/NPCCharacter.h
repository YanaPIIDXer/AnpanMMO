// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "NPCCharacter.generated.h"

struct NPCItem;

/**
 * NPCキャラクタ
 */
UCLASS()
class ANPANMMO_API ANPCCharacter : public ACharacterBase
{

	GENERATED_BODY()

public:

	// Spawn
	static ANPCCharacter *Spawn(UWorld *pWorld, const NPCItem *pItem);

	// コンストラクタ
	ANPCCharacter(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~ANPCCharacter() {}

	// ID取得.
	uint32 GetId() const { return Id; }

	// キャラクタタイプを取得.
	virtual ECharacterType GetCharacterType() const override { return ECharacterType::NPC; }

	// 高さの半分を取得.
	float GetHalfHeight() const override { return HalfHeight; }

private:
	
	// ID
	uint32 Id;

	// 半分の高さ
	float HalfHeight;


	// メッシュのセットアップ
	void SetupMesh(USkeletalMesh *pMesh);

};
