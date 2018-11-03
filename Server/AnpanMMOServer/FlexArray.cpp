#include "stdafx.h"
#include "FlexArray.h"
#include "MemoryStream/MemoryStreamInterface.h"

template <>
void FlexArray<s8>::Serialize(MemoryStreamInterface *pStream)
{
	pStream->Serialize(&CurrentSize);
	if (CurrentSize > CurrentCapacity)
	{
		Reallocate(CurrentSize);
	}
	for (int i = 0; i < CurrentSize; i++)
	{
		pStream->Serialize(&pArray[i]);
	}
}

template <>
void FlexArray<u8>::Serialize(MemoryStreamInterface *pStream)
{
	pStream->Serialize(&CurrentSize);
	if (CurrentSize > CurrentCapacity)
	{
		Reallocate(CurrentSize);
	}
	for (int i = 0; i < CurrentSize; i++)
	{
		pStream->Serialize(&pArray[i]);
	}
}

template <>
void FlexArray<s16>::Serialize(MemoryStreamInterface *pStream)
{
	pStream->Serialize(&CurrentSize);
	if (CurrentSize > CurrentCapacity)
	{
		Reallocate(CurrentSize);
	}
	for (int i = 0; i < CurrentSize; i++)
	{
		pStream->Serialize(&pArray[i]);
	}
}

template <>
void FlexArray<u16>::Serialize(MemoryStreamInterface *pStream)
{
	pStream->Serialize(&CurrentSize);
	if (CurrentSize > CurrentCapacity)
	{
		Reallocate(CurrentSize);
	}
	for (int i = 0; i < CurrentSize; i++)
	{
		pStream->Serialize(&pArray[i]);
	}
}

template <>
void FlexArray<s32>::Serialize(MemoryStreamInterface *pStream)
{
	pStream->Serialize(&CurrentSize);
	if (CurrentSize > CurrentCapacity)
	{
		Reallocate(CurrentSize);
	}
	for (int i = 0; i < CurrentSize; i++)
	{
		pStream->Serialize(&pArray[i]);
	}
}

template <>
void FlexArray<u32>::Serialize(MemoryStreamInterface *pStream)
{
	pStream->Serialize(&CurrentSize);
	if (CurrentSize > CurrentCapacity)
	{
		Reallocate(CurrentSize);
	}
	for (int i = 0; i < CurrentSize; i++)
	{
		pStream->Serialize(&pArray[i]);
	}
}

template <>
void FlexArray<std::string>::Serialize(MemoryStreamInterface *pStream)
{
	pStream->Serialize(&CurrentSize);
	if (CurrentSize > CurrentCapacity)
	{
		Reallocate(CurrentSize);
	}
	for (int i = 0; i < CurrentSize; i++)
	{
		pStream->Serialize(&pArray[i]);
	}
}

template <>
void FlexArray<float>::Serialize(MemoryStreamInterface *pStream)
{
	pStream->Serialize(&CurrentSize);
	if (CurrentSize > CurrentCapacity)
	{
		Reallocate(CurrentSize);
	}
	for (int i = 0; i < CurrentSize; i++)
	{
		pStream->Serialize(&pArray[i]);
	}
}

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
