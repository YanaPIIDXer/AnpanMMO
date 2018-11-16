// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "WarpPointManager.h"
#include "WarpPoint.h"
#include "Master/MasterData.h"

// コンストラクタ
WarpPointManager::WarpPointManager()
{
}

// Spawn
void WarpPointManager::Spawn(uint32 AreaId)
{
	auto WarpPointList = MasterData::GetInstance().GetWarpPointMaster().GetAll();
	for (auto Point : WarpPointList)
	{
		if (Point.AreaId != AreaId) { continue; }
		auto *pWarpPoint = AWarpPoint::Spawn(pWorld.Get(), Point.X, Point.Y, Point.WarpDataId);
		WarpPoints.Add(pWarpPoint);
	}
}

// リセット
void WarpPointManager::Reset()
{
	for (WarpPointPtr pWarpPoint : WarpPoints)
	{
		pWarpPoint->Destroy();
	}
	WarpPoints.Empty();
}
