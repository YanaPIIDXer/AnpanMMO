// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintFunctions.generated.h"

class USimpleDialog;

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
	
};
