#include "stdafx.h"
#include "Anpan.h"

// �R���X�g���N�^
Anpan::Anpan(const Vector2D &InPosition, int Hp, int Atk, int Def)
{
	SetPosition(InPosition);
	SetParameter(Hp, Hp, Atk, Def);
}
