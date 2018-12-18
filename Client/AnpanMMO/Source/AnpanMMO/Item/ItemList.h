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

private:

	// �A�C�e���}�b�v
	ItemMap Items;

};
