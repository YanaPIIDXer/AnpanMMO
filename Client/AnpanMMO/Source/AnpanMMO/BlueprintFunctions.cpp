// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "BlueprintFunctions.h"
#include "UI/SimpleDialog.h"
#include "Particles/Emitter.h"

// �P���ȃ_�C�A���O��\��.
USimpleDialog *UBlueprintFunctions::ShowSimpleDialog(UObject *pOuter, const FString &DisplayText)
{
	USimpleDialog *pDialog = USimpleDialog::Show(pOuter, DisplayText);
	return pDialog;
}

// �G�t�F�N�g����.
AEmitter *UBlueprintFunctions::SpawnEffect(UObject *pWorldContext, UParticleSystem *pParticle, const FVector &Position, const FRotator &Rotation)
{
	FActorSpawnParameters Param;
	Param.bNoFail = true;
	Param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	UWorld *pWorld = pWorldContext->GetWorld();
	AEmitter *pEmitter = pWorld->SpawnActor<AEmitter>(AEmitter::StaticClass(), Position, Rotation, Param);
	check(pEmitter != nullptr);
	
	pEmitter->SetTemplate(pParticle);
	pEmitter->Activate();

	return pEmitter;
}

// �����_���ȃx�N�g�����擾.
FVector UBlueprintFunctions::GetRandomVector(float Min, float Max)
{
	FVector Vec;
	Vec.X = FMath::RandRange(Min, Max);
	Vec.Y = FMath::RandRange(Min, Max);
	Vec.Z = FMath::RandRange(Min, Max);
	return Vec;
}
