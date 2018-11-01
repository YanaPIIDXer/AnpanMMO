// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "Buffer.h"

// �R���X�g���N�^
Buffer::Buffer()
{
}

// �f�[�^��ǉ�.
void Buffer::Push(const uint8 *pData, int32 Size)
{
	for (int i = 0; i < Size; i++)
	{
		Data.Add(pData[i]);
	}
}

// �f�[�^�����o��
void Buffer::Pop(int32 Size)
{
	int32 DataSize = FMath::Max(Size, Data.Num());
	Data.RemoveAt(0, DataSize);
}

// �擪���擾.
uint8 *Buffer::GetTop()
{
	if (Data.Num() == 0) { return nullptr; }

	return &Data[0];
}
