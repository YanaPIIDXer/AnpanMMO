#include "stdafx.h"
#include "AnpanPopArea.h"
#include "Character/Anpan/Anpan.h"
#include "Master/AnpanPopAreaMaster.h"
#include "Math/Random.h"

// �R���X�g���N�^
AnpanPopArea::AnpanPopArea(const AnpanPopAreaItem *pMasterItem)
	: Range(pMasterItem->Range)
	, Position(pMasterItem->X, pMasterItem->Y)
	, MinHp(pMasterItem->MinHp)
	, MaxHp(pMasterItem->MaxHp)
	, MinAtk(pMasterItem->MinAtk)
	, MaxAtk(pMasterItem->MaxAtk)
	, MinDef(pMasterItem->MinDef)
	, MaxDef(pMasterItem->MaxDef)
	, MinExp(pMasterItem->MinDef)
	, MaxExp(pMasterItem->MaxDef)
	, PopInterval(pMasterItem->PopInterval)
	, CurrentInterval(pMasterItem->PopInterval)
{
}

// ���t���[���̏���.
void AnpanPopArea::Poll(int DeltaTime)
{
	CurrentInterval -= DeltaTime;
	if (CurrentInterval <= 0)
	{
		SpawnAnpan();
		CurrentInterval += PopInterval;
	}
}


// �A���p���𐶐�.
void AnpanPopArea::SpawnAnpan()
{
	float X = Random::Range<float>(-Range, Range);
	float Y = Random::Range<float>(-Range, Range);
	int Hp = Random::Range<int>(MinHp, MaxHp);
	int Atk = Random::Range<int>(MinAtk, MaxAtk);
	int Def = Random::Range<int>(MinDef, MaxDef);
	int Exp = Random::Range<int>(MinExp, MaxExp);

	Anpan *pNewAnpan = new Anpan(Vector2D(X, Y), Hp, Atk, Def, Exp);
	shared_ptr<Anpan> pAnpan = shared_ptr<Anpan>(pNewAnpan);
	if (SpawnFunction)
	{
		SpawnFunction(pAnpan);
	}
}
