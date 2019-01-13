// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "EquipMenu.generated.h"

// 装備データ
USTRUCT(BlueprintType, Category = "Equip")
struct FEquipData
{
	GENERATED_USTRUCT_BODY()

public:

	// 装備ＩＤ
	uint32 EquipId;

	// 有効か？
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


	// コンストラクタ
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
 * 装備メニュー
 */
UCLASS()
class ANPANMMO_API UEquipMenu : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// コンストラクタ
	UEquipMenu(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UEquipMenu() {}

protected:

	// 初期化.
	UFUNCTION(BlueprintCallable, Category = "Equip")
	void Init();

	// 初期化イベント
	UFUNCTION(BlueprintNativeEvent, Category = "Equip")
	void InitEvent(const TArray<FEquipData> &Datas);
	void InitEvent_Implementation(const TArray<FEquipData> &Datas) {}

	// 基礎最大ＨＰ取得.
	UFUNCTION(BlueprintPure, Category = "Parameter")
	int32 GetBaseMaxHp() const { return BaseMaxHp; }

	// 基礎STR取得.
	UFUNCTION(BlueprintPure, Category = "Parameter")
	int32 GetBaseStr() const { return BaseStr; }

	// 基礎DEF取得.
	UFUNCTION(BlueprintPure, Category = "Parameter")
	int32 GetBaseDef() const { return BaseDef; }

	// 基礎INT取得.
	UFUNCTION(BlueprintPure, Category = "Parameter")
	int32 GetBaseInt() const { return BaseInt; }

	// 基礎MND取得.
	UFUNCTION(BlueprintPure, Category = "Parameter")
	int32 GetBaseMnd() const { return BaseMnd; }

	// 基礎VIT取得.
	UFUNCTION(BlueprintPure, Category = "Parameter")
	int32 GetBaseVit() const { return BaseVit; }

	// 右手装備データを取得.
	UFUNCTION(BlueprintPure, Category = "Equip")
	const FEquipData &GetRightEquipData() const { return RightEquipData; }

	// 左手装備データを取得.
	UFUNCTION(BlueprintPure, Category = "Equip")
	const FEquipData &GetLeftEquipData() const { return LeftEquipData; }
	
private:

	// 基礎最大ＨＰ
	int32 BaseMaxHp;

	// 基礎STR
	int32 BaseStr;

	// 基礎DEF
	int32 BaseDef;

	// 基礎INT
	int32 BaseInt;

	// 基礎MND
	int32 BaseMnd;

	// 基礎VIT
	int32 BaseVit;

	// 右手装備データ
	FEquipData RightEquipData;

	// 左手装備データ
	FEquipData LeftEquipData;
	

	// 装備データを生成.
	FEquipData CreateEquipData(uint32 EquipId);

};
