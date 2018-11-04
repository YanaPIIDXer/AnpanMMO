#include "stdafx.h"
#include "MemoryBuffer.h"

// ’Ç‰Á
void MemoryBuffer::Push(const u8 *Data, s32 Size)
{
	if(CurrentSize + Size >= BUFFER_SIZE)
	{
		Size = BUFFER_SIZE - CurrentSize;
	}

	for(s32 i = 0 ; i < Size ; i++ )
	{
		Buffer[CurrentSize + i] = *(Data + i);
	}

	CurrentSize += Size;
}

// Á‹Ž
void MemoryBuffer::Pop(s32 Size)
{
	if(CurrentSize < Size)
	{
		Size = CurrentSize;
	}

	for(s32 i = 0 ; i < BUFFER_SIZE ; i++)
	{
		s32 Index = Size + i;
		if(Index < BUFFER_SIZE)
		{
			Buffer[i] = Buffer[Index];
		}
		else
		{
			Buffer[i] = 0;
		}
	}
	CurrentSize -= Size;
}
