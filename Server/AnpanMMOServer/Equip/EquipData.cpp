/**
 * @file EquipData.cpp
 * @brief 装備データ
 * @author YanaP
 */
#include "stdafx.h"
#include "EquipData.h"
#include "Master/MasterData.h"

// コンストラクタ
EquipData::EquipData()
{
	Reset();
}

// セット
void EquipData::Set(u32 InEquipId)
{
	// 一旦リセット
	Reset();
	
	const EquipItem *pItem = MasterData::GetInstance().GetEquipMaster().GetItem(InEquipId);
	if (pItem == NULL) { return; }
	
	EquipId = pItem->ID;
	Str = pItem->Str;
	Def = pItem->Def;
	Int = pItem->Int;
	Mnd = pItem->Mnd;
	Vit = pItem->Vit;
}

// リセット
void EquipData::Reset()
{
	EquipId = 0;
	Str = 0;
	Def = 0;
	Int = 0;
	Mnd = 0;
	Vit = 0;
}
