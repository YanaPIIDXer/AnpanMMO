#include "stdafx.h"
#include "AnpanManager.h"
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>

// �R���X�g���N�^
AnpanManager::AnpanManager()
{
}

// �A���p������.
void AnpanManager::SpawnAnpan()
{
	boost::random::random_device SeedGen;
	boost::random::mt19937 Gen(SeedGen);
	boost::random::uniform_real_distribution<float> Dist(-100.0f, 100.0f);

	float X = Dist(Gen);
	float Y = Dist(Gen);
	Anpan Pan(Vector2D(X, Y));

	AnpanList.push_back(Pan);

	// @TODO:�N���C�A���g�ɒʒm.
}
