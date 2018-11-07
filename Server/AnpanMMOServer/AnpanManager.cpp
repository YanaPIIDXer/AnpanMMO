#include "stdafx.h"
#include "AnpanManager.h"
#include "Math/Random.h"
#include "Packet/PacketAnpanList.h"

const int AnpanManager::SpawnInterval = 5000;

// コンストラクタ
AnpanManager::AnpanManager()
	: NextUuid(1)
	, SpawnTime(SpawnInterval)
{
}

// 毎フレームの処理.
void AnpanManager::Poll(int DeltaTime)
{
	SpawnTime -= DeltaTime;
	if (SpawnTime <= 0)
	{
		SpawnAnpan();
		SpawnTime += SpawnInterval;
	}

	AnpanMap::iterator It = AnpanList.begin();
	while (It != AnpanList.end())
	{
		if (It->second->IsDead())
		{
			It = AnpanList.erase(It);
		}
		else
		{
			++It;
		}
	}
}

// 取得.
AnpanPtr AnpanManager::Get(u32 Uuid) const
{
	AnpanMap::const_iterator It = AnpanList.find(Uuid);
	if (It == AnpanList.end()) { return AnpanPtr(); }

	return It->second;
}
// アンパンリストパケットを生成.
void AnpanManager::MakeListPacket(PacketAnpanList &Packet)
{
	for (AnpanMap::iterator It = AnpanList.begin(); It != AnpanList.end(); ++It)
	{
		AnpanSharedPtr pAnpan = It->second;
		const CharacterParameter &Param = pAnpan->GetParameter();
		const Vector2D Position = pAnpan->GetPosition();
		AnpanData Data(It->first, Position.X, Position.Y, Param.Hp, Param.MaxHp);
		Packet.List.PushBack(Data);
	}
}


// アンパン生成.
void AnpanManager::SpawnAnpan()
{
	if (AnpanList.size() >= 100) { return; }

	float X = Random::Range<float>(-2500.0f, 2500.0f);
	float Y = Random::Range<float>(-2500.0f, 2500.0f);

	int Hp = Random::Range<int>(100, 500);

	int Atk = Random::Range<int>(10, 100);
	int Def = Random::Range<int>(10, 100);

	Anpan *pNewAnpan = new Anpan(Vector2D(X, Y), Hp, Atk, Def);
	AnpanSharedPtr pAnpan = AnpanSharedPtr(pNewAnpan);

	unsigned int Uuid = NextUuid;
	AnpanList[Uuid] = pAnpan;

	NextUuid++;

	if (OnSpawn)
	{
		OnSpawn(Uuid, pAnpan);
	}
}
