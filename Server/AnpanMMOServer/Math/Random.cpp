#include "stdafx.h"
#include "Random.h"

Random Random::Instance;

// �R���X�g���N�^
Random::Random()
	: Gen(SeedGen)
{
}

// �͈͂��w�肵�Ď擾�iint�j
template<>
int Random::Range(int Min, int Max)
{
	boost::random::uniform_int_distribution<> Dist(Min, Max);
	return Dist(Instance.Gen);
}

// �͈͂��w�肵�Ď擾�ifloat�j
template<>
float Random::Range(float Min, float Max)
{
	boost::random::uniform_real_distribution<float> Dist(Min, Max);
	return Dist(Instance.Gen);
}
