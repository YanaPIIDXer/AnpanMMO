// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "NPCDataAsset.h"

// �R���X�g���N�^
UNPCDataAsset::UNPCDataAsset(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// �擾.
USkeletalMesh *UNPCDataAsset::Get(int32 Index)
{
	check((Index >= 0 && Index < Assets.Num()));
	USkeletalMesh *pMesh = Assets[Index].Get();
	return pMesh;
}
