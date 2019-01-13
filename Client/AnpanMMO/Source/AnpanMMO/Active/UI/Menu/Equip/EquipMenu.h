// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "EquipMenu.generated.h"

// �����f�[�^
USTRUCT(BlueprintType, Category = "Equip")
struct FEquipData
{
	GENERATED_USTRUCT_BODY()

public:

	// �����h�c
	uint32 EquipId;

	// �L�����H
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


	// �R���X�g���N�^
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
 * �������j���[
 */
UCLASS()
class ANPANMMO_API UEquipMenu : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	UEquipMenu(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UEquipMenu() {}

protected:

	// ������.
	UFUNCTION(BlueprintCallable, Category = "Equip")
	void Init();

	// �������C�x���g
	UFUNCTION(BlueprintNativeEvent, Category = "Equip")
	void InitEvent(const TArray<FEquipData> &Datas);
	void InitEvent_Implementation(const TArray<FEquipData> &Datas) {}

	// ��b�ő�g�o�擾.
	UFUNCTION(BlueprintPure, Category = "Parameter")
	int32 GetBaseMaxHp() const { return BaseMaxHp; }

	// ��bSTR�擾.
	UFUNCTION(BlueprintPure, Category = "Parameter")
	int32 GetBaseStr() const { return BaseStr; }

	// ��bDEF�擾.
	UFUNCTION(BlueprintPure, Category = "Parameter")
	int32 GetBaseDef() const { return BaseDef; }

	// ��bINT�擾.
	UFUNCTION(BlueprintPure, Category = "Parameter")
	int32 GetBaseInt() const { return BaseInt; }

	// ��bMND�擾.
	UFUNCTION(BlueprintPure, Category = "Parameter")
	int32 GetBaseMnd() const { return BaseMnd; }

	// ��bVIT�擾.
	UFUNCTION(BlueprintPure, Category = "Parameter")
	int32 GetBaseVit() const { return BaseVit; }

	// �E�葕���f�[�^���擾.
	UFUNCTION(BlueprintPure, Category = "Equip")
	const FEquipData &GetRightEquipData() const { return RightEquipData; }

	// ���葕���f�[�^���擾.
	UFUNCTION(BlueprintPure, Category = "Equip")
	const FEquipData &GetLeftEquipData() const { return LeftEquipData; }
	
private:

	// ��b�ő�g�o
	int32 BaseMaxHp;

	// ��bSTR
	int32 BaseStr;

	// ��bDEF
	int32 BaseDef;

	// ��bINT
	int32 BaseInt;

	// ��bMND
	int32 BaseMnd;

	// ��bVIT
	int32 BaseVit;

	// �E�葕���f�[�^
	FEquipData RightEquipData;

	// ���葕���f�[�^
	FEquipData LeftEquipData;
	

	// �����f�[�^�𐶐�.
	FEquipData CreateEquipData(uint32 EquipId);

};
