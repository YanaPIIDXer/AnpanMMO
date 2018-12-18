// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/**
 * �A�C�e�����X�g�N���X
 */
class ANPANMMO_API ItemList
{

private:		// �ʖ���`.

	typedef TMap<uint32, uint32> ItemMap;

public:

	// �R���X�g���N�^
	ItemList();

	// �f�X�g���N�^
	~ItemList() {}

	// �ǉ�.
	void Add(uint32 ItemId, uint32 Count);

	// ����.
	void Subtract(uint32 ItemId, uint32 Count);

	// �����擾.
	uint32 GetCount(uint32 ItemId) const;

	// ��������A�C�e�����X�g���.
	// �����͍l���Ȃ��B
	TArray<uint32> CollectItemList() const;

	// �A�C�e���V���[�g�J�b�g���X�V.
	void UpdateItemShortcut(uint32 ItemId1, uint32 ItemId2);

	// �A�C�e���V���[�g�J�b�g���擾.
	const TArray<uint32> &GetItemShortcut() const { return ItemShortcut; }

private:

	// �A�C�e���}�b�v
	ItemMap Items;

	// �A�C�e���V���[�g�J�b�g
	TArray<uint32> ItemShortcut;

};
