#include "stdafx.h"
#include "Random.h"

Random Random::Instance;

// コンストラクタ
Random::Random()
	: Gen(SeedGen)
{
}

// 範囲を指定して取得（int）
template<>
int Random::Range(int Min, int Max)
{
	boost::random::uniform_int_distribution<> Dist(Min, Max);
	return Dist(Instance.Gen);
}

// 範囲を指定して取得（float）
template<>
float Random::Range(float Min, float Max)
{
	boost::random::uniform_real_distribution<float> Dist(Min, Max);
	return Dist(Instance.Gen);
}
