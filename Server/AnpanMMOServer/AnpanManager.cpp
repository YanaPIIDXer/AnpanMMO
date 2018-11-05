#include "stdafx.h"
#include "AnpanManager.h"
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>
#include "Packet/PacketAnpanList.h"

// コンストラクタ
AnpanManager::AnpanManager()
	: NextUuid(1)
{
}

// 毎フレームの処理.
void AnpanManager::Poll()
{
	AnpanMap::iterator It = AnpanList.begin();
	while (It != AnpanList.end())
	{
		if (It->second->IsDead())
		{
			AnpanList.erase(It);
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

// アンパン生成.
void AnpanManager::SpawnAnpan()
{
	if (AnpanList.size() >= 100) { return; }

	boost::random::random_device SeedGen;
	boost::random::mt19937 Gen(SeedGen);
	boost::random::uniform_real_distribution<float> PositionDist(-500.0f, 500.0f);

	float X = PositionDist(Gen);
	float Y = PositionDist(Gen);
	
	boost::random::uniform_int_distribution<> HpDist(100, 500);
	int Hp = HpDist(Gen);

	boost::random::uniform_int_distribution<> ParamDist(10, 100);
	int Atk = ParamDist(Gen);
	int Def = ParamDist(Gen);

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
