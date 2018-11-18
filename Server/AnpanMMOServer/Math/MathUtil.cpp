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
	return (int)((1.0f - Rate) * Start + Rate * End);
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
	return (1.0f - Rate) * Start + Rate * End;
}

// Vector3D‚Ì•âŠÔ.
template<>
Vector3D MathUtil::Lerp(Vector3D Start, Vector3D End, float Rate)
{
	Vector3D Result = Start;
	Result.X += (End.X - Start.X) * Rate;
	Result.Y += (End.Y - Start.Y) * Rate;
	Result.Z += (End.Z - Start.Z) * Rate;
	return Result;
}

// ‰ñ“]‚Ì•âŠÔ.
template<>
Rotation MathUtil::Lerp(Rotation Start, Rotation End, float Rate)
{
	float Value = Lerp<float>(Start.Get(), End.Get(), Rate);
	return Rotation(Value);
}
