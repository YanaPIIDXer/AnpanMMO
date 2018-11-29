#ifndef __FLEXARRAY_H__
#define __FLEXARRAY_H__

#include "MemoryStream/MemoryStreamInterface.h"

template<typename T>
class FlexArray
{

public:

	// コンストラクタ
	FlexArray(int DefaultCapacity = 20)
		: CurrentSize(0)
		, CurrentCapacity(DefaultCapacity)
	{
		pArray = new T[DefaultCapacity];
	}

	// デストラクタ
	~FlexArray()
	{
		delete[] pArray;
	}

	// 追加.
	void PushBack(T NewItem)
	{
		if (CurrentSize + 1 > CurrentCapacity)
		{
			Reallocate(CurrentCapacity * 2);
		}

		pArray[CurrentSize] = NewItem;
		CurrentSize++;
	}

	// 挿入.
	void Insert(T NewItem, int Index)
	{
		if (CurrentSize + 1 > CurrentCapacity)
		{
			Reallocate(CurrentCapacity * 2);
		}

		for (int i = CurrentSize; i > Index; i--)
		{
			pArray[i] = pArray[i - 1];
		}
		pArray[Index] = NewItem;
		CurrentSize++;
	}

	// リアロケート
	void Reallocate(int Capacity)
	{
		CurrentCapacity = Capacity;
		T *pTmp = new T[Capacity];
		if (CurrentSize > Capacity)
		{
			CurrentSize = Capacity;
		}
		for (int i = 0; i < CurrentSize; i++)
		{
			pTmp[i] = pArray[i];
		}
		delete[] pArray;
		pArray = pTmp;
	}

	// 現在の要素数を取得.
	int GetCurrentSize() const { return CurrentSize; }

	// 指定した要素を消去.
	void Remove(T Item)
	{
		for (int i = 0; i < CurrentSize; i++)
		{
			if (Item == pArray[i])
			{
				for (int j = i; j < CurrentSize - 1; j++)
				{
					pArray[j] = pArray[j + 1];
				}
				CurrentSize--;
				return;
			}
		}
	}

	// オペレータオーバーロード
	T operator [](int Index) const
	{
		return pArray[Index];
	}

	// シリアライズB
	void Serialize(MemoryStreamInterface *pStream);

private:

	// 配列領域.
	T *pArray;

	// 現在の要素数.
	int CurrentSize;

	// 配列のキャパシティ
	int CurrentCapacity;

};

template<typename T>
void FlexArray<T>::Serialize(MemoryStreamInterface *pStream)
{
	pStream->Serialize(&CurrentSize);
	if (CurrentSize > CurrentCapacity)
	{
		Reallocate(CurrentSize);
	}

	for (int i = 0; i < CurrentSize; i++)
	{
		pArray[i].Serialize(pStream);
	}
}


#endif		// #ifndef __FLEXARRAY_H__
