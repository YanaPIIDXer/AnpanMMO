#ifndef __VECTOR2D_H__
#define __VECTOR2D_H__

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

	// ���W.
	float X;
	float Y;

};

#endif		// #ifndef __VECTOR2D_H__
