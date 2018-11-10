// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintFunctions.generated.h"

class USimpleDialog;

// �L�����N�^�^�C�v
UENUM(BlueprintType, Category = "Character")
enum class ECharacterType : uint8
{
	// ����
	Player,

	// ���l.
	Other,

	// �G.
	Enemy,
};

/**
 * Blueprint�p�֐��Q.
 */
UCLASS()
class ANPANMMO_API UBlueprintFunctions : public UBlueprintFunctionLibrary
{

	GENERATED_BODY()
	
public:
	
	// �P���ȃ_�C�A���O��\��.
	UFUNCTION(BlueprintCallable, Category = "Dialog", meta = (WorldContext = pOuter))
	static USimpleDialog *ShowSimpleDialog(UObject *pOuter, const FString &DisplayText);

	// �G�t�F�N�g����.
	UFUNCTION(BlueprintCallable, Category = "Effect", meta = (WorldContext = pWorldContext))
	static AEmitter *SpawnEffect(UObject *pWorldContext, UParticleSystem *pParticle, const FVector &Position, const FRotator &Rotation);
	
	// �����_���ȃx�N�g�����擾.
	UFUNCTION(BlueprintPure, Category = "Math")
	static FVector GetRandomVector(float Min, float Max);
	
	// ���X�|�����N�G�X�g���M.
	UFUNCTION(BlueprintCallable, Category = "Respawn", meta = (WorldContext = pWorldContext))
	static void SendRespawnRequest(UObject *pWorldContext);

};
