#include "stdafx.h"
#include "Anpan.h"

// �R���X�g���N�^
Anpan::Anpan(const Vector2D &InPosition, int Hp, int Atk, int Def)
	: AI(this)
{
	SetPosition(InPosition);
	SetParameter(Hp, Hp, Atk, Def);
}

// ���t���[���̏���.
void Anpan::Poll(int DeltaTime)
{
	AI.Poll(DeltaTime);
}
