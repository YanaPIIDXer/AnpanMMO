#ifndef __MATHUTIL_H__
#define __MATHUTIL_H__

#define _USE_MATH_DEFINES
#include <math.h>
#include "Vector2D.h"

// ‰‰ŽZŠÖŒW.
class MathUtil
{

public:

	// •âŠÔ.
	template<class T>
	static T Lerp(T Start, T End, float Rate);

	// Degree‚ðRadian‚É•ÏŠ·.
	static float DegToRad(float Deg)
	{
		if (fabsf(Deg) < FLT_EPSILON) { return 0.0f; }
		return (float)(Deg * M_PI / 180.0f);
	}

	// Radian‚ðDegree‚É•ÏŠ·.
	static float RadToDeg(float Rad)
	{
		if (fabsf(Rad) < FLT_EPSILON) { return 0.0f; }
		return (float)(Rad * 180.0f / M_PI);
	}

	// ƒxƒNƒgƒ‹‚ð‰ñ“].
	static Vector2D RotateVector(const Vector2D &Vec, float Deg)
	{
		Vector2D Result;
		float Rad = DegToRad(Deg);
		Result.X = ((Vec.X * cosf(Rad)) - (Vec.Y * sinf(Rad)));
		Result.Y = ((Vec.X * sinf(Rad)) + (Vec.Y * cosf(Rad)));
		return Result;
	}

	// “àÏ.
	static float Dot(const Vector2D &A, const Vector2D &B)
	{
		return ((A.X * B.X) + (A.Y * B.Y));
	}

	static void DependTest()
	{
	}

};

#endif		// #ifndef __MATHUTIL_H__
