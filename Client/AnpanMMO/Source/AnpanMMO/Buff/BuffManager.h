// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class BuffBase;
class ACharacterBase;

/**
 * �o�t�Ǘ�.
 */
class ANPANMMO_API BuffManager
{

public:

	// �R���X�g���N�^
	BuffManager();

	// �f�X�g���N�^
	~BuffManager();

	// ���L�҂�ݒ�.
	void SetOwner(ACharacterBase *pInOwner) { pOwner = pInOwner; }

	// �o�t�ǉ�.
	void Add(uint32 BuffId);

	// �o�t����.
	void Remove(uint8 Type);

	// �w�肵���o�t���������Ă��邩�H
	bool IsActive(uint8 Type) const { return Buffs.Contains(Type); }

private:

	// �o�t�}�b�v
	TMap<uint8, BuffBase *> Buffs;

	// ���L��.
	TWeakObjectPtr<ACharacterBase> pOwner;

};
