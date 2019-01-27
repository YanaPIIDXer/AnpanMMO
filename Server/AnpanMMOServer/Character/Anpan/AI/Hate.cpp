/**
 * @file Hate.cpp
 * @brief ヘイト管理クラス
 * @author YanaP
 */
#include "stdafx.h"
#include "Hate.h"
#include "Character/CharacterBase.h"

const int Hate::VolatileHateDecayTime = 3000;

// コンストラクタ
Hate::Hate()
{
}

// 毎フレームの処理.
void Hate::Poll(u32 DeltaTime)
{
	std::vector<HateUnit>::iterator It = HateList.begin();
	bool bNeedSort = false;
	while (It != HateList.end())
	{
		if (It->VolatileHate > 0)
		{
			It->VolatileHateDecayTimer -= DeltaTime;
			if (It->VolatileHateDecayTimer <= 0)
			{
				It->VolatileHate -= 10;
				if (It->VolatileHate < 0)
				{
					It->VolatileHate = 0;
				}
				It->VolatileHateDecayTimer += VolatileHateDecayTime;
				bNeedSort = true;
			}
		}

		if (It->pCharacter.expired() || It->pCharacter.lock()->IsDead() || It->GetTotal() <= 0)
		{
			It = HateList.erase(It);
			bNeedSort = true;
		}
		else
		{
			++It;
		}
	}

	if (bNeedSort)
	{
		Sort();
	}
}

// 増加.
void Hate::Add(CharacterPtr pCharacter, int VolatileHate, int AccumulateHate)
{
	if (pCharacter.expired()) { return; }

	for (u32 i = 0; i < HateList.size(); i++)
	{
		if (HateList[i].pCharacter.lock().get() == pCharacter.lock().get())
		{
			HateList[i].VolatileHate += VolatileHate;
			HateList[i].AccumulateHate += AccumulateHate;
			Sort();
			return;
		}
	}

	HateUnit Unit;
	Unit.pCharacter = pCharacter;
	Unit.VolatileHate = VolatileHate;
	Unit.AccumulateHate = AccumulateHate;
	Unit.VolatileHateDecayTimer = VolatileHateDecayTime;
	HateList.push_back(Unit);
	Sort();
}

// 一番上にいるキャラを取得.
CharacterPtr Hate::GetTop() const
{
	if (HateList.empty()) { return weak_ptr<CharacterBase>(); }
	return HateList[0].pCharacter;
}


// ソート
void Hate::Sort()
{
	std::sort(HateList.begin(), HateList.end(), std::greater<HateUnit>());
}



// ====== ソート用オペレータオーバーロード =====
bool operator <(const HateUnit &Left, const HateUnit &Right)
{
	return (Left.GetTotal() < Right.GetTotal());
}

bool operator >(const HateUnit &Left, const HateUnit &Right)
{
	return (Left.GetTotal() > Right.GetTotal());
}
