/**
 * @file BuffManager.cpp
 * @brief �o�t�Ǘ��N���X
 * @author YanaP
 */
#include "stdafx.h"
#include "BuffManager.h"
#include "BuffBase.h"
#include "Character/CharacterBase.h"
#include "Master/MasterData.h"
#include "BuffSpeedUp.h"

// �R���X�g���N�^
BuffManager::BuffManager(CharacterBase *pInOwner)
	: pOwner(pInOwner)
{
}

// �f�X�g���N�^
BuffManager::~BuffManager()
{
	for (BuffMap::iterator It = Buffs.begin(); It != Buffs.end(); ++It)
	{
		delete It->second;
	}
}

// ���t���[���̏���
void BuffManager::Poll(u32 DeltaTime)
{
	for (BuffMap::iterator It = Buffs.begin(); It != Buffs.end();)
	{
		It->second->Poll(DeltaTime);
		if (It->second->IsFinished())
		{
			u8 BuffType = It->second->GetType();
			delete It->second;
			It = Buffs.erase(It);
			pOwner->OnBuffRemoved(BuffType);
		}
		else
		{
			++It;
		}
	}
}

// �o�t�ǉ��B
void BuffManager::AddBuff(u32 BuffId)
{
	const BuffItem *pItem = MasterData::GetInstance().GetBuffMaster().GetItem(BuffId);
	if (pItem == NULL)
	{
		std::cout << "Warning! Invalid BuffID:" << BuffId << std::endl;
		return;
	}

	// @TODO:�e��o�t��ǉ����鏈���B
	BuffBase *pBuff = NULL;
	switch (pItem->Type)
	{
		case BuffItem::SPEEDUP:

			// �X�s�[�h�A�b�v
			pBuff = new BuffSpeedUp(pItem->TimeMilliSec, pOwner, pItem->Value);
			break;

		case BuffItem::AUTO_HEAL:

			// ������.
			break;

		case BuffItem::POISON:

			// ��.
			break;

		case BuffItem::PARALYSIS:

			// ���.
			break;
	}

	if (pBuff == NULL)
	{
		std::cout << "Warning! Buff object is NULL! BuffID:" << BuffId << std::endl;
		return;
	}

	if (Buffs.find(pItem->Type) != Buffs.end())
	{
		delete Buffs[pItem->Type];
	}

	Buffs[pItem->Type] = pBuff;
	pOwner->OnBuffAdded(BuffId);
}
