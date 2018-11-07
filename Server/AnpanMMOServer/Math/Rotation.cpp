#include "stdafx.h"
#include "Rotation.h"

// コンストラクタ
Rotation::Rotation()
	: Value(0.0f)
{
}

// コンストラクタ
Rotation::Rotation(float InValue)
{
	Set(InValue);
}

// セット.
void Rotation::Set(float InValue)
{
	Value = InValue;
	Value = Coax(Value);
}

// オペレータオーバーロード
float Rotation::operator+(float InValue)
{
	return Coax(Value + InValue);
}

float Rotation::operator-(float InValue)
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


// 丸め込み処理.
float Rotation::Coax(float InValue)
{
	if (InValue >= 360.0f)
	{
		InValue -= 360.0f;
	}
	else if (InValue <= 0.0f)
	{
		InValue += 360.0f;
	}

	return InValue;
}
