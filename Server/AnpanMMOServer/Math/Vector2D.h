#ifndef __VECTOR2D_H__
#define __VECTOR2D_H__

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

	// 座標.
	float X;
	float Y;

};

#endif		// #ifndef __VECTOR2D_H__
