// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "Buffer.h"

// コンストラクタ
Buffer::Buffer()
{
}

// データを追加.
void Buffer::Push(uint8 *pData, int32 Size)
{
	for (int i = 0; i < Size; i++)
	{
		Data.Add(pData[i]);
	}
}

// データを取り出す
void Buffer::Pop(int32 Size)
{
	int32 DataSize = FMath::Max(Size, Data.Num());
	Data.RemoveAt(0, DataSize);
}

// 先頭を取得.
const uint8 *Buffer::GetTop() const
{
	if (Data.Num() == 0) { return nullptr; }

	return &Data[0];
}
