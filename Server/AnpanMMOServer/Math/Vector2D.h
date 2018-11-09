#ifndef __VECTOR2D_H__
#define __VECTOR2D_H__

#include <math.h>
#include <float.h>

// �x�N�g���N���X
class Vector2D
{

public:

	// �R���X�g���N�^
	Vector2D()
		: X(0.0f)
		, Y(0.0f) {}

	Vector2D(float InX, float InY)
		: X(InX)
		, Y(InY) {}

	Vector2D(const Vector2D &Arg)
		: X(Arg.X)
		, Y(Arg.Y) {}

	// ���W.
	float X;
	float Y;

	// �T�C�Y���擾.
	float GetSize() const
	{
		return sqrt(GetSizeSq());
	}

	// �T�C�Y�̓����擾.
	float GetSizeSq() const
	{
		return ((X * X) + (Y * Y));
	}

	// ���K���������̂��擾.
	Vector2D GetNormalized() const
	{
		float Size = GetSize();
		Vector2D Vec;
		Vec.X = X / Size;
		Vec.Y = Y / Size;
		return Vec;
	}

	// ���K��.
	void Normalize()
	{
		Vector2D Vec = GetNormalized();
		*this = Vec;
	}

	// �I�y���[�^�I�[�o�[���[�h
	Vector2D operator +(const Vector2D &Arg) const
	{
		Vector2D Vec;
		Vec.X = X + Arg.X;
		Vec.Y = Y + Arg.Y;
		return Vec;
	}

	Vector2D operator -(const Vector2D &Arg) const
	{
		Vector2D Vec;
		Vec.X = X - Arg.X;
		Vec.Y = Y - Arg.Y;
		return Vec;
	}

	void operator +=(const Vector2D &Arg)
	{
		X += Arg.X;
		Y += Arg.Y;
	}

	void operator -=(const Vector2D &Arg)
	{
		X -= Arg.X;
		Y -= Arg.Y;
	}

	Vector2D operator *(float Arg) const
	{
		Vector2D Vec;
		Vec.X = X * Arg;
		Vec.Y = Y * Arg;
		if (Vec.X == -0.0f)
		{
			Vec.X = 0.0f;
		}
		if (Vec.Y == -0.0f)
		{
			Vec.Y = 0.0f;
		}
		return Vec;
	}

	Vector2D operator /(float Arg) const
	{
		Vector2D Vec;
		Vec.X = X / Arg;
		Vec.Y = Y / Arg;
		if (Vec.X == -0.0f)
		{
			Vec.X = 0.0f;
		}
		if (Vec.Y == -0.0f)
		{
			Vec.Y = 0.0f;
		}
		return Vec;
	}

	void operator *=(float Arg)
	{
		X *= Arg;
		Y *= Arg;
		if (X == -0.0f)
		{
			X = 0.0f;
		}
		if (Y == -0.0f)
		{
			Y = 0.0f;
		}
	}

	void operator /=(float Arg)
	{
		X /= Arg;
		Y /= Arg;
		if (X == -0.0f)
		{
			X = 0.0f;
		}
		if (Y == -0.0f)
		{
			Y = 0.0f;
		}
	}

	bool operator ==(const Vector2D &Arg) const
	{
		return (fabsf(X - Arg.X) < FLT_EPSILON && fabsf(Y - Arg.Y) < FLT_EPSILON);
	}

	bool operator !=(const Vector2D &Arg) const
	{
		return (fabsf(X - Arg.X) >= FLT_EPSILON || fabsf(Y - Arg.Y) >= FLT_EPSILON);
	}

};

#endif		// #ifndef __VECTOR2D_H__
