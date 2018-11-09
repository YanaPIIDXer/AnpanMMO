#include "stdafx.h"
#include "MathUtil.h"
#include "Rotation.h"

// int‚Ì•âŠÔ.
template<>
int MathUtil::Lerp(int Start, int End, float Rate)
{
	if (Rate <= 0.0f)
	{
		Rate = 0.0f;
	}
	if (Rate >= 1.0f)
	{
		Rate = 1.0f;
	}
	return (int)(Start + Rate * (End - Start));
}

// float‚Ì•âŠÔ.
template<>
float MathUtil::Lerp(float Start, float End, float Rate)
{
	if (Rate <= 0.0f)
	{
		Rate = 0.0f;
	}
	if (Rate >= 1.0f)
	{
		Rate = 1.0f;
	}
	return Start + Rate * (End - Start);
}

// Vector2D‚Ì•âŠÔ.
template<>
Vector2D MathUtil::Lerp(Vector2D Start, Vector2D End, float Rate)
{
	Vector2D Result;
	Result.X = Lerp<float>(Start.X, End.X, Rate);
	Result.Y = Lerp<float>(Start.X, End.Y, Rate);
	return Result;
}

// ‰ñ“]‚Ì•âŠÔ.
template<>
Rotation MathUtil::Lerp(Rotation Start, Rotation End, float Rate)
{
	float Value = Lerp<float>(Start.Get(), End.Get(), Rate);
	return Rotation(Value);
}
