/**
 * @file EquipData.cpp
 * @brief �����f�[�^
 * @author YanaP
 */
#include "stdafx.h"
#include "EquipData.h"
#include "Master/MasterData.h"

// �R���X�g���N�^
EquipData::EquipData()
{
	Reset();
}

// �Z�b�g
void EquipData::Set(u32 InEquipId)
{
	// ��U���Z�b�g
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

// ���Z�b�g
void EquipData::Reset()
{
	EquipId = 0;
	Str = 0;
	Def = 0;
	Int = 0;
	Mnd = 0;
	Vit = 0;
}
