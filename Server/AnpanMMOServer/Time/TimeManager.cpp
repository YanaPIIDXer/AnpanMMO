#include "stdafx.h"
#include "TimeManager.h"
#include "Master/MasterData.h"
#include "Math/Random.h"
#include "ClientManager.h"
#include "Packet/PacketTimeChange.h"

TimeManager TimeManager::Instance;
const int TimeManager::TimeZoneChangeInterval = 60000;

// コンストラクタ
TimeManager::TimeManager()
	: CurrentTimeZone(TimeInfoItem::MORNING)
	, TimeZoneChangeTimer(TimeZoneChangeInterval)
	, MasterId(0)
{
}

// 初期化.
void TimeManager::Initialize()
{
	SetTimeZone(TimeInfoItem::MORNING);
}

// 毎フレームの処理.
void TimeManager::Poll(int DeltaTime)
{
	TimeZoneChangeTimer -= DeltaTime;
	if (TimeZoneChangeTimer <= 0)
	{
		switch (CurrentTimeZone)
		{
			case TimeInfoItem::MORNING:
			
				SetTimeZone(TimeInfoItem::AFTERNOON);
				break;

			case TimeInfoItem::AFTERNOON:

				SetTimeZone(TimeInfoItem::EVENING);
				break;

			case TimeInfoItem::EVENING:

				SetTimeZone(TimeInfoItem::NIGHT);
				break;

			case TimeInfoItem::NIGHT:

				SetTimeZone(TimeInfoItem::MORNING);
				break;

		}

		TimeZoneChangeTimer += TimeZoneChangeInterval;
	}
}


// 時間帯を設定.
void TimeManager::SetTimeZone(u8 NewTimeZone)
{
	CurrentTimeZone = NewTimeZone;

	std::vector<TimeInfoItem> Items = MasterData::GetInstance().GetTimeInfoMaster().GetAll();
	std::vector<u32> Ids;
	for (u32 i = 0; i < Items.size(); i++)
	{
		if (Items[i].TimeType == CurrentTimeZone)
		{
			Ids.push_back(Items[i].Id);
		}
	}

	s32 Index = Random::Range<s32>(0, Ids.size() - 1);
	MasterId = Ids[Index];

	PacketTimeChange Packet(MasterId);
	ClientManager::GetInstance().BroadcastPacket(&Packet);
}
