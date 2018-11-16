// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "MasterData.h"

MasterData MasterData::Instance;

// コンストラクタ
MasterData::MasterData()
{
}

// ロード
void MasterData::Load()
{
	Area.Load();
	WarpPoint.Load();
	WarpData.Load();
}
