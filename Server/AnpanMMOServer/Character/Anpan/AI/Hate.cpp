#include "stdafx.h"
#include "Hate.h"

// コンストラクタ
Hate::Hate()
{
}

// 毎フレームの処理.
void Hate::Poll()
{
	std::vector<HateUnit>::iterator It = HateList.begin();
	bool bNeedSort = false;
	while (It != HateList.end())
	{
		if (It->pCharacter.expired())
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
void Hate::Add(weak_ptr<CharacterBase> pCharacter, int Value)
{
	for (int i = 0; i < HateList.size(); i++)
	{
		if (HateList[i].pCharacter.lock().get() == pCharacter.lock().get())
		{
			HateList[i].HateValue += Value;
			Sort();
			return;
		}
	}

	HateUnit Unit;
	Unit.pCharacter = pCharacter;
	Unit.HateValue = Value;
	HateList.push_back(Unit);
	Sort();
}


// ソート
void Hate::Sort()
{
	std::sort(HateList.begin(), HateList.end(), std::greater<HateUnit>());
}



// ====== ソート用オペレータオーバーロード =====
bool operator <(const HateUnit &Left, const HateUnit &Right)
{
	return (Left.HateValue < Right.HateValue);
}

bool operator >(const HateUnit &Left, const HateUnit &Right)
{
	return (Left.HateValue > Right.HateValue);
}
