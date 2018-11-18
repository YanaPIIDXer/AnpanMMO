#ifndef __MATHUTIL_H__
#define __MATHUTIL_H__

#define _USE_MATH_DEFINES
#include <math.h>
#include "Vector3D.h"

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
	static Vector3D RotateVector(const Vector3D &Vec, float Deg)
	{
		Vector3D Result;
		float Rad = DegToRad(Deg);
		Result.X = ((Vec.X * cosf(Rad)) - (Vec.Y * sinf(Rad)));
		Result.Y = ((Vec.X * sinf(Rad)) + (Vec.Y * cosf(Rad)));
		Result.Z = Vec.Z;
		return Result;
	}

	// “àÏ.
	static float Dot(const Vector3D &A, const Vector3D &B)
	{
		return ((A.X * B.X) + (A.Y * B.Y) + (A.Z * B.Z));
	}

	// ŠOÏ.
	static Vector3D Cross(const Vector3D &A, const Vector3D &B)
	{
		Vector3D Vec;
		Vec.X = (A.Y * B.Z) - (A.Z * B.Y);
		Vec.Y = (A.Z * B.X) - (A.X * B.Z);
		Vec.Z = (A.X * B.Y) - (A.Y * B.X);
		return Vec;
	}

};

#endif		// #ifndef __MATHUTIL_H__
