#ifndef __MATHUTIL_H__
#define __MATHUTIL_H__

#include <math.h>
#include "Vector2D.h"

// ���Z�֌W.
class MathUtil
{

public:

	// �p�C
	static const float PI;


	// ���.
	template<class T>
	static T Lerp(T Start, T End, float Rate);

	// Degree��Radian�ɕϊ�.
	static float DegToRad(float Deg)
	{
		return (Deg * PI / 180.0f);
	}

	// Radian��Degree�ɕϊ�.
	static float RadToDeg(float Rad)
	{
		return (Rad * 180.0f / PI);
	}

	// �x�N�g������].
	static Vector2D RotateVector(const Vector2D &Vec, float Deg)
	{
		Vector2D Result;
		float Rad = DegToRad(Deg);
		Result.X = ((Vec.X * cos(Rad)) - (Vec.Y * sin(Rad)));
		Result.Y = ((Vec.X * sin(Rad)) + (Vec.Y * cos(Rad)));
		return Result;
	}

	// ����.
	static float Dot(const Vector2D &A, const Vector2D &B)
	{
		return ((A.X * B.X) + (A.Y * B.Y));
	}

};

#endif		// #ifndef __MATHUTIL_H__
