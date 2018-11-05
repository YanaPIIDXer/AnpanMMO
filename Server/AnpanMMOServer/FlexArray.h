#ifndef __FLEXARRAY_H__
#define __FLEXARRAY_H__

#include "MemoryStream/MemoryStreamInterface.h"

template<typename T>
class FlexArray
{

public:

	// �R���X�g���N�^
	FlexArray(int DefaultCapacity = 20)
		: CurrentSize(0)
		, CurrentCapacity(DefaultCapacity)
	{
		pArray = new T[DefaultCapacity];
	}

	// �f�X�g���N�^
	~FlexArray()
	{
		delete[] pArray;
	}

	// �ǉ�.
	void PushBack(T NewItem)
	{
		if (CurrentSize + 1 > CurrentCapacity)
		{
			Reallocate(CurrentCapacity * 2);
		}

		pArray[CurrentSize] = NewItem;
		CurrentSize++;
	}

	// ���A���P�[�g
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

	// ���݂̗v�f�����擾.
	int GetCurrentSize() const { return CurrentSize; }

	// �w�肵���v�f������.
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

	// �I�y���[�^�I�[�o�[���[�h
	T operator [](int Index) const
	{
		return pArray[Index];
	}

	class Iterator
	{
	public:

		// �R���X�g���N�^
		Iterator(int InIndex)
			: Index(InIndex) {}

		// �I�y���[�^�I�[�o�[���[�h
		Iterator &operator ++()
		{
			Index++;
			return *this;
		}

		bool operator !=(const Iterator &Arg) const
		{
			return (Index != Arg.Index);
		}

		T *operator ->() const
		{
			return &pArray[Index];
		}

	private:

		// �C���f�b�N�X
		int Index;
	};

	Iterator begin()
	{
		return Iterator(0);
	}

	Iterator end()
	{
		return Iterator(CurrentSize);
	}
	
	// �V���A���C�YB
	void Serialize(MemoryStreamInterface *pStream);

private:

	// �z��̈�.
	T *pArray;

	// ���݂̗v�f��.
	int CurrentSize;

	// �z��̃L���p�V�e�B
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
