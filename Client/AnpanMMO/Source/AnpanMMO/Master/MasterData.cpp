// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "MasterData.h"

MasterData MasterData::Instance;

// �R���X�g���N�^
MasterData::MasterData()
{
}

// ���[�h
void MasterData::Load()
{
	Area.Load();
	WarpPoint.Load();
	WarpData.Load();
}
