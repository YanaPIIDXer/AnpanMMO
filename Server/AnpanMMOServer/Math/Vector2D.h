#ifndef __VECTOR2D_H__
#define __VECTOR2D_H__

#include <math.h>

// ベクトルクラス
class Vector2D
{

public:

	// コンストラクタ
	Vector2D()
		: X(0.0f)
		, Y(0.0f) {}

	Vector2D(float InX, float InY)
		: X(InX)
		, Y(InY) {}

	Vector2D(const Vector2D &Arg)
		: X(Arg.X)
		, Y(Arg.Y) {}

	// 座標.
	float X;
	float Y;

	// サイズを取得.
	float GetSize() const
	{
		return sqrt(GetSizeSq());
	}

	// サイズの二乗を取得.
	float GetSizeSq() const
	{
		return ((X * X) + (Y * Y));
	}

	// 正規化したものを取得.
	Vector2D GetNormalized() const
	{
		float Size = GetSize();
		Vector2D Vec;
		Vec.X = X / Size;
		Vec.Y = Y / Size;
		return Vec;
	}

	// 正規化.
	void Normalize()
	{
		Vector2D Vec = GetNormalized();
		*this = Vec;
	}

	// 内積.
	float Dot(const Vector2D &Arg)
	{
		return ((X * Arg.X) + (Y * Arg.Y)) / (GetSize() * Arg.GetSize());
	}

	// オペレータオーバーロード
	Vector2D operator +(const Vector2D &Arg)
	{
		Vector2D Vec;
		Vec.X = X + Arg.X;
		Vec.Y = Y + Arg.Y;
		return Vec;
	}

	Vector2D operator -(const Vector2D &Arg)
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

	Vector2D operator *(float Arg)
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

	Vector2D operator /(float Arg)
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

};

#endif		// #ifndef __VECTOR2D_H__
