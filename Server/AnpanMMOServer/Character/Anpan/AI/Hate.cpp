#include "stdafx.h"
#include "Hate.h"
#include "Character/CharacterBase.h"

// �R���X�g���N�^
Hate::Hate()
{
}

// ���t���[���̏���.
void Hate::Poll()
{
	std::vector<HateUnit>::iterator It = HateList.begin();
	bool bNeedSort = false;
	while (It != HateList.end())
	{
		if (It->pCharacter.expired() || It->pCharacter.lock()->IsDead())
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

// ����.
void Hate::Add(weak_ptr<CharacterBase> pCharacter, int Value)
{
	for (unsigned int i = 0; i < HateList.size(); i++)
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

// ��ԏ�ɂ���L�������擾.
weak_ptr<CharacterBase> Hate::GetTop() const
{
	if (HateList.empty()) { return weak_ptr<CharacterBase>(); }
	return HateList[0].pCharacter;
}


// �\�[�g
void Hate::Sort()
{
	std::sort(HateList.begin(), HateList.end(), std::greater<HateUnit>());
}



// ====== �\�[�g�p�I�y���[�^�I�[�o�[���[�h =====
bool operator <(const HateUnit &Left, const HateUnit &Right)
{
	return (Left.HateValue < Right.HateValue);
}

bool operator >(const HateUnit &Left, const HateUnit &Right)
{
	return (Left.HateValue > Right.HateValue);
}
