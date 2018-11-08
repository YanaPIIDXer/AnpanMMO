#include "stdafx.h"
#include "Anpan.h"

// コンストラクタ
Anpan::Anpan(const Vector2D &InPosition, int Hp, int Atk, int Def)
	: AI(this)
{
	SetPosition(InPosition);
	SetParameter(Hp, Hp, Atk, Def);
}

// 毎フレームの処理.
void Anpan::Poll(int DeltaTime)
{
	AI.Poll(DeltaTime);
}
