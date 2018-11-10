#ifndef __MATHUTIL_H__
#define __MATHUTIL_H__

#define _USE_MATH_DEFINES
#include <math.h>
#include "Vector2D.h"

// 演算関係.
class MathUtil
{

public:

	// 補間.
	template<class T>
	static T Lerp(T Start, T End, float Rate);

	// DegreeをRadianに変換.
	static float DegToRad(float Deg)
	{
		if (fabsf(Deg) < FLT_EPSILON) { return 0.0f; }
		return (float)(Deg * M_PI / 180.0f);
	}

	// RadianをDegreeに変換.
	static float RadToDeg(float Rad)
	{
		if (fabsf(Rad) < FLT_EPSILON) { return 0.0f; }
		return (float)(Rad * 180.0f / M_PI);
	}

	// ベクトルを回転.
	static Vector2D RotateVector(const Vector2D &Vec, float Deg)
	{
		Vector2D Result;
		float Rad = DegToRad(Deg);
		Result.X = ((Vec.X * cosf(Rad)) - (Vec.Y * sinf(Rad)));
		Result.Y = ((Vec.X * sinf(Rad)) + (Vec.Y * cosf(Rad)));
		return Result;
	}

	// 内積.
	static float Dot(const Vector2D &A, const Vector2D &B)
	{
		return ((A.X * B.X) + (A.Y * B.Y));
	}

};

#endif		// #ifndef __MATHUTIL_H__
