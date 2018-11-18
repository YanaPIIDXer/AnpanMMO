#include "stdafx.h"
#include "AnpanPopArea.h"
#include "Character/Anpan/Anpan.h"
#include "Master/AnpanPopAreaMaster.h"
#include "Math/Random.h"

// コンストラクタ
AnpanPopArea::AnpanPopArea(const AnpanPopAreaItem *pMasterItem)
	: Range(pMasterItem->Range)
	, Position(pMasterItem->X, pMasterItem->Y, 0.0f)
	, MaxCount(pMasterItem->MaxCount)
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

// 毎フレームの処理.
void AnpanPopArea::Poll(int DeltaTime)
{
	CurrentInterval -= DeltaTime;
	if (CurrentInterval <= 0)
	{
		SpawnAnpan();
		CurrentInterval += PopInterval;
	}
	UpdateList();
}


// アンパンを生成.
void AnpanPopArea::SpawnAnpan()
{
	if (AnpanList.size() >= MaxCount) { return; }

	float X = Position.X + Random::Range<float>(-Range, Range);
	float Y = Position.Y + Random::Range<float>(-Range, Range);
	float Z = Position.Z;
	int Hp = Random::Range<int>(MinHp, MaxHp);
	int Atk = Random::Range<int>(MinAtk, MaxAtk);
	int Def = Random::Range<int>(MinDef, MaxDef);
	int Exp = Random::Range<int>(MinExp, MaxExp);

	Anpan *pNewAnpan = new Anpan(Vector3D(X, Y, Z), Hp, Atk, Def, Exp);
	shared_ptr<Anpan> pAnpan = shared_ptr<Anpan>(pNewAnpan);
	AnpanList.push_back(pAnpan);
	if (SpawnFunction)
	{
		SpawnFunction(pAnpan);
	}
}

// リスト更新.
void AnpanPopArea::UpdateList()
{
	std::vector<AnpanPtr>::iterator It = AnpanList.begin();
	while (It != AnpanList.end())
	{
		if (It->expired())
		{
			It = AnpanList.erase(It);
		}
		else
		{
			++It;
		}
	}
}
