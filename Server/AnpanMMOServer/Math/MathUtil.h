#ifndef __MATHUTIL_H__
#define __MATHUTIL_H__

#define _USE_MATH_DEFINES
#include <math.h>
#include "Vector2D.h"

// ‰‰ZŠÖŒW.
class MathUtil
{

public:

	// •âŠÔ.
	template<class T>
	static T Lerp(T Start, T End, float Rate);

	// Degree‚ğRadian‚É•ÏŠ·.
	static float DegToRad(float Deg)
	{
		return (float)(Deg * M_PI / 180.0f);
	}

	// Radian‚ğDegree‚É•ÏŠ·.
	static float RadToDeg(float Rad)
	{
		return (float)(Rad * 180.0f / M_PI);
	}

	// ƒxƒNƒgƒ‹‚ğ‰ñ“].
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

};

#endif		// #ifndef __MATHUTIL_H__
