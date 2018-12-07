// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "NPCDataAsset.h"

// コンストラクタ
UNPCDataAsset::UNPCDataAsset(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// 取得.
USkeletalMesh *UNPCDataAsset::Get(int32 Index)
{
	if (Index < 0 || Index >= Assets.Num()) { return nullptr; }
	USkeletalMesh *pMesh = Assets[Index].Get();
	return pMesh;
}
