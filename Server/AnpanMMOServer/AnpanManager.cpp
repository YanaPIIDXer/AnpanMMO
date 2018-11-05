#include "stdafx.h"
#include "AnpanManager.h"
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>

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

// アンパン生成.
void AnpanManager::SpawnAnpan()
{
	if (AnpanList.size() >= 100) { return; }

	boost::random::random_device SeedGen;
	boost::random::mt19937 Gen(SeedGen);
	boost::random::uniform_real_distribution<float> PositionDist(-100.0f, 100.0f);

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
