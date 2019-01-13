// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "EquipMenu.generated.h"

// υf[^
USTRUCT(BlueprintType, Category = "Equip")
struct FEquipData
{
	GENERATED_USTRUCT_BODY()

public:

	// υhc
	uint32 EquipId;

	// Lψ©H
	UPROPERTY(BlueprintReadOnly)
	bool bIsValid;

	// STR
	UPROPERTY(BlueprintReadOnly)
	int32 Str;

	// DEF
	UPROPERTY(BlueprintReadOnly)
	int32 Def;

	// Int
	UPROPERTY(BlueprintReadOnly)
	int32 Int;

	// MND
	UPROPERTY(BlueprintReadOnly)
	int32 Mnd;

	// VIT
	UPROPERTY(BlueprintReadOnly)
	int32 Vit;


	// RXgN^
	FEquipData()
		: EquipId(0)
		, bIsValid(false)
		, Str(0)
		, Def(0)
		, Int(0)
		, Mnd(0)
		, Vit(0) {}

};

/**
 * υj[
 */
UCLASS()
class ANPANMMO_API UEquipMenu : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// RXgN^
	UEquipMenu(const FObjectInitializer &ObjectInitializer);

	// fXgN^
	virtual ~UEquipMenu() {}

protected:

	// ϊ».
	UFUNCTION(BlueprintCallable, Category = "Equip")
	void Init();

	// ϊ»Cxg
	UFUNCTION(BlueprintNativeEvent, Category = "Equip")
	void InitEvent(const TArray<FEquipData> &Datas);
	void InitEvent_Implementation(const TArray<FEquipData> &Datas) {}

	// ξbΕεgoζΎ.
	UFUNCTION(BlueprintPure, Category = "Parameter")
	int32 GetBaseMaxHp() const { return BaseMaxHp; }

	// ξbSTRζΎ.
	UFUNCTION(BlueprintPure, Category = "Parameter")
	int32 GetBaseStr() const { return BaseStr; }

	// ξbDEFζΎ.
	UFUNCTION(BlueprintPure, Category = "Parameter")
	int32 GetBaseDef() const { return BaseDef; }

	// ξbINTζΎ.
	UFUNCTION(BlueprintPure, Category = "Parameter")
	int32 GetBaseInt() const { return BaseInt; }

	// ξbMNDζΎ.
	UFUNCTION(BlueprintPure, Category = "Parameter")
	int32 GetBaseMnd() const { return BaseMnd; }

	// ξbVITζΎ.
	UFUNCTION(BlueprintPure, Category = "Parameter")
	int32 GetBaseVit() const { return BaseVit; }

	// Eθυf[^πζΎ.
	UFUNCTION(BlueprintPure, Category = "Equip")
	const FEquipData &GetRightEquipData() const { return RightEquipData; }

	// Άθυf[^πζΎ.
	UFUNCTION(BlueprintPure, Category = "Equip")
	const FEquipData &GetLeftEquipData() const { return LeftEquipData; }

	// υΟXpPbgπM.
	UFUNCTION(BlueprintCallable, Category = "Equip")
	void SendChangeEquip(const FEquipData &RightEquip, const FEquipData &LeftEquip);
	
private:

	// ξbΕεgo
	int32 BaseMaxHp;

	// ξbSTR
	int32 BaseStr;

	// ξbDEF
	int32 BaseDef;

	// ξbINT
	int32 BaseInt;

	// ξbMND
	int32 BaseMnd;

	// ξbVIT
	int32 BaseVit;

	// Eθυf[^
	FEquipData RightEquipData;

	// Άθυf[^
	FEquipData LeftEquipData;
	

	// υf[^πΆ¬.
	FEquipData CreateEquipData(uint32 EquipId);

};
