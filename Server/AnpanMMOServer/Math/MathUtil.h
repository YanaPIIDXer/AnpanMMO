#ifndef __MATHUTIL_H__
#define __MATHUTIL_H__

#include <math.h>
#include "Vector2D.h"

// 演算関係.
class MathUtil
{

public:

	// パイ
	static const float PI;


	// 補間.
	template<class T>
	static T Lerp(T Start, T End, float Rate);

	// DegreeをRadianに変換.
	static float DegToRad(float Deg)
	{
		return (Deg * PI / 180.0f);
	}

	// RadianをDegreeに変換.
	static float RadToDeg(float Rad)
	{
		return (Rad * 180.0f / PI);
	}

	// ベクトルを回転.
	static Vector2D RotateVector(const Vector2D &Vec, float Deg)
	{
		Vector2D Result;
		float Rad = DegToRad(Deg);
		Result.X = ((Vec.X * cos(Rad)) - (Vec.Y * sin(Rad)));
		Result.Y = ((Vec.X * sin(Rad)) + (Vec.Y * cos(Rad)));
		return Result;
	}

};

#endif		// #ifndef __MATHUTIL_H__
