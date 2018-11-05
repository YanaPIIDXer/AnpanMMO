#include "stdafx.h"
#include "AnpanManager.h"
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>

// コンストラクタ
AnpanManager::AnpanManager()
{
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

	Anpan Pan(Vector2D(X, Y), Hp, Atk, Def);
	AnpanList.push_back(Pan);

	// @TODO:クライアントに通知.
}
