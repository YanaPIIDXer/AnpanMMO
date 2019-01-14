// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/**
 * �o�b�t�@�N���X
 */
class ANPANMMO_API Buffer
{

public:

	// �R���X�g���N�^
	Buffer();

	// �f�X�g���N�^
	~Buffer() {}

	// �f�[�^��ǉ�.
	void Push(const uint8 *pData, int32 Size);

	// �f�[�^�����o��
	void Pop(int32 Size);

	// �擪���擾.
	uint8 *GetTop();

	// �T�C�Y���擾.
	int32 GetSize() const { return Data.Num(); }

private:

	// �f�[�^
	TArray<uint8> Data;

};
