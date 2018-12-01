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
void TimeManager::OnRecvTime(MemoryStreamInterface *pStream)
{
	PacketTime Packet;
	Packet.Serialize(pStream);

	CurrentMasterId = Packet.MasterId;
	if (pSky != nullptr)
	{
		pSky->SetTime(Packet.MasterId);
	}
}

// 時間変動を受け取った。
void TimeManager::OnRecvTimeChange(MemoryStreamInterface *pStream)
{
	PacketTimeChange Packet;
	Packet.Serialize(pStream);

	CurrentMasterId = Packet.MasterId;
	if (pSky != nullptr)
	{
		pSky->TimeChange(Packet.MasterId);
	}
}
