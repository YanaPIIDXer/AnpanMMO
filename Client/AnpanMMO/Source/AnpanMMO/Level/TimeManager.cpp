// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "TimeManager.h"
#include "SkyControl.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketTime.h"
#include "Packet/PacketTimeChange.h"

// コンストラクタ
TimeManager::TimeManager()
	: pSky(nullptr)
	, CurrentMasterId(1)
{
}

// 天球をセット。
void TimeManager::SetSkyControl(ASkyControl *pInSky)
{
	pSky = pInSky;
	pSky->SetTime(CurrentMasterId);
}

// 開始時の時間を受け取った。
bool TimeManager::OnRecvTime(MemoryStreamInterface *pStream)
{
	PacketTime Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	CurrentMasterId = Packet.MasterId;
	if (pSky != nullptr)
	{
		pSky->SetTime(Packet.MasterId);
	}

	return true;
}

// 時間変動を受け取った。
bool TimeManager::OnRecvTimeChange(MemoryStreamInterface *pStream)
{
	PacketTimeChange Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	CurrentMasterId = Packet.MasterId;
	if (pSky != nullptr)
	{
		pSky->TimeChange(Packet.MasterId);
	}

	return true;
}
