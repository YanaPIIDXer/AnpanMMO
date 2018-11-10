#include "stdafx.h"
#include "Rotation.h"

// �R���X�g���N�^
Rotation::Rotation()
	: Value(0.0f)
{
}

// �R���X�g���N�^
Rotation::Rotation(float InValue)
{
	Set(InValue);
}

// �Z�b�g.
void Rotation::Set(float InValue)
{
	Value = InValue;
	Value = Coax(Value);
}

// �I�y���[�^�I�[�o�[���[�h
float Rotation::operator+(float InValue) const
{
	return Coax(Value + InValue);
}

float Rotation::operator-(float InValue) const
{
	return Coax(Value - InValue);
}

void Rotation::operator+=(float InValue)
{
	Value += InValue;
	Value = Coax(Value);
}

void Rotation::operator-=(float InValue)
{
	Value -= InValue;
	Value = Coax(Value);
}


// �ۂߍ��ݏ���.
float Rotation::Coax(float InValue)
{
	if (InValue >= 180.0f)
	{
		InValue -= 360.0f;
	}
	else if (InValue <= -180.0f)
	{
		InValue += 360.0f;
	}

	return InValue;
}
