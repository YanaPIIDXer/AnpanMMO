// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "Buffer.h"

// コンストラクタ
Buffer::Buffer()
{
}

// データを追加.
void Buffer::Push(const uint8 *pData, int32 Size)
{
	for (int i = 0; i < Size; i++)
	{
		Data.Add(pData[i]);
	}
}

// データを取り出す
void Buffer::Pop(int32 Size)
{
	int32 DataSize = FMath::Min(Size, Data.Num());
	Data.RemoveAt(0, DataSize);
}

// 先頭を取得.
uint8 *Buffer::GetTop()
{
	if (Data.Num() == 0) { return nullptr; }

	return &Data[0];
}
