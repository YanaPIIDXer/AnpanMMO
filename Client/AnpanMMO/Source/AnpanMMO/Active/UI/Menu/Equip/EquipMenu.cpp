// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "EquipMenu.h"
#include "Kismet/GameplayStatics.h"
#include "Character/Player/GameCharacter.h"
#include "Master/MasterData.h"

// コンストラクタ
UEquipMenu::UEquipMenu(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, BaseMaxHp(0)
	, BaseStr(0)
	, BaseDef(0)
	, BaseInt(0)
	, BaseMnd(0)
	, BaseVit(0)
{
}


// 初期化.
void UEquipMenu::Init()
{
	AGameCharacter *pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	check(pCharacter != nullptr);

	// 基礎パラメータの設定。
	const PlayerStatus &Status = pCharacter->GetStatus();
	BaseMaxHp = Status.GetBaseMaxHp();
	BaseStr = Status.GetStr();
	BaseDef = Status.GetDef();
	BaseInt = Status.GetInt();
	BaseMnd = Status.GetMnd();
	BaseVit = Status.GetVit();

	// 現在の装備データ
	RightEquipData = CreateEquipData(Status.GetRightEquipId());
	LeftEquipData = CreateEquipData(Status.GetLeftEquipId());

	// 装備リスト
	TArray<FEquipData> Datas;
	TArray<uint32> Items = Status.GetItemList().CollectItemList();
	for (uint32 ItemId : Items)
	{
		if (ItemId < 10000) { continue; }
		for (uint32 i = 0; i < Status.GetItemList().GetCount(ItemId); i++)
		{
			FEquipData Data = CreateEquipData(ItemId);
			Datas.Add(Data);
		}
	}

	InitEvent(Datas);
}


// 装備データを生成.
FEquipData UEquipMenu::CreateEquipData(uint32 EquipId) const
{
	FEquipData Data;
	Data.EquipId = EquipId;
	const EquipItem *pItem = MasterData::GetInstance().GetEquipMaster().Get(EquipId);
	if (pItem != nullptr)
	{
		Data.Str = pItem->Str;
		Data.Def = pItem->Def;
		Data.Int = pItem->Int;
		Data.Mnd = pItem->Mnd;
		Data.Vit = pItem->Vit;
	}
	else
	{
		Data.Str = 0;
		Data.Def = 0;
		Data.Int = 0;
		Data.Mnd = 0;
		Data.Vit = 0;
	}

	return Data;
}
