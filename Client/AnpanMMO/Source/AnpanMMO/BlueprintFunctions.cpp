// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "BlueprintFunctions.h"
#include "UI/SimpleDialog.h"
#include "Particles/Emitter.h"

// 単純なダイアログを表示.
USimpleDialog *UBlueprintFunctions::ShowSimpleDialog(UObject *pOuter, const FString &DisplayText)
{
	USimpleDialog *pDialog = USimpleDialog::Show(pOuter, DisplayText);
	return pDialog;
}

// エフェクト生成.
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
