/**
 * @file BuffManager.cpp
 * @brief �o�t�Ǘ��N���X
 * @author YanaP
 */
#include "stdafx.h"
#include "BuffManager.h"
#include "BuffBase.h"

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
			delete It->second;
			It = Buffs.erase(It);
		}
		else
		{
			++It;
		}
	}
}
