#include "stdafx.h"
#include "MemorySizeCaliculateStream.h"


//�����t���R�Q�r�b�g�V���A���C�Y
bool MemorySizeCaliculateStream::Serialize( s32 *pValue )
{

	Size += sizeof( s32 );
	return true;

}

//���������R�Q�r�b�g�V���A���C�Y
bool MemorySizeCaliculateStream::Serialize( u32 *pValue )
{

	Size += sizeof( u32 );
	return true;

}

//�����t���P�U�r�b�g�V���A���C�Y
bool MemorySizeCaliculateStream::Serialize( s16 *pValue )
{

	Size += sizeof( s16 );
	return true;

}

//���������P�U�r�b�g�V���A���C�Y
bool MemorySizeCaliculateStream::Serialize( u16 *pValue )
{

	Size += sizeof( u16 );
	return true;

}

//�����t���W�r�b�g�V���A���C�Y
bool MemorySizeCaliculateStream::Serialize( s8 *pValue )
{

	Size += sizeof( s8 );
	return true;

}

//���������W�r�b�g�V���A���C�Y
bool MemorySizeCaliculateStream::Serialize( u8 *pValue )
{

	Size += sizeof( u8 );
	return true;

}

//������V���A���C�Y
bool MemorySizeCaliculateStream::Serialize( std::string *pValue )
{

	Size += sizeof( s32 ) + pValue->size();
	return true;

}

// float�V���A���C�Y
bool MemorySizeCaliculateStream::Serialize(float *pValue)
{

	Size += sizeof(float);
	return true;

}
