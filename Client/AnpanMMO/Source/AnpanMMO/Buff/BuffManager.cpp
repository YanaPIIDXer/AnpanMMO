// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.


#include "BuffManager.h"
#include "BuffNop.h"
#include "Master/MasterData.h"

// �R���X�g���N�^
BuffManager::BuffManager()
	: pOwner(nullptr)
{
}

// �f�X�g���N�^
BuffManager::~BuffManager()
{
	for (auto KeyValue : Buffs)
	{
		delete KeyValue.Value;
	}
}

// �o�t�ǉ�.
void BuffManager::Add(uint32 BuffId)
{
	const BuffItem *pItem = MasterData::GetInstance().GetBuffMaster().Get(BuffId);
	check(pItem != nullptr);

	if (Buffs.Contains(pItem->Type))
	{
		delete Buffs[pItem->Type];
		Buffs.Remove(pItem->Type);
	}

	BuffBase *pBuff = nullptr;
	switch (pItem->Type)
	{
		case BuffItem::SPEEDUP:

			// @TODO:�X�s�[�h�A�b�v�o�t�N���X���쐬���A�������ɍ����ւ���B
			//		 ���G���[����̂��߂̑[�u�B
			pBuff = new BuffNop(pOwner.Get(), pItem->Type);
			break;

		default:

			// �N���C�A���g���͓��ɂ�鎖�����B
			pBuff = new BuffNop(pOwner.Get(), pItem->Type);
			break;
	}

	Buffs.Add(pBuff->GetType(), pBuff);
	pBuff->Begin();
}

// �o�t����.
void BuffManager::Remove(uint8 Type)
{
	if (!Buffs.Contains(Type)) { return; }

	Buffs[Type]->Finish();
	delete Buffs[Type];
	Buffs.Remove(Type);
}
