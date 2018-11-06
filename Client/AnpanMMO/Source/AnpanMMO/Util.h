// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/**
 * ユーティリティクラス
 */
class ANPANMMO_API Util
{

public:

	// Blueprintをロード
	template<class T>
	static T *LoadBlueprint(UObject *pOuter, const TCHAR *Path)
	{
		FString LoadPath = Path;
		LoadPath += "_C";
		UBlueprintGeneratedClass *pClass = LoadObject<UBlueprintGeneratedClass>(pOuter, *LoadPath, *LoadPath);
		check(pClass != nullptr);

		T *pObject = NewObject<T>(pOuter, pClass);
		check(pObject != nullptr);

		return pObject;
	}

	// BlueprintのActorをSpawn
	template<class T>
	static T *SpawnFromBlueprint(UWorld *pWorld, const TCHAR *Path, const FVector &Position, const FRotator &Rotation)
	{
		FString LoadPath = Path;
		LoadPath += "_C";
		UBlueprintGeneratedClass *pClass = LoadObject<UBlueprintGeneratedClass>(pWorld, *LoadPath, *LoadPath);
		check(pClass != nullptr);

		FActorSpawnParameters Param;
		Param.bNoFail = true;
		Param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		T *pActor = pWorld->SpawnActor<T>(pClass, Position, Rotation, Param);
		check(pActor != nullptr);

		return pActor;
	}

};
