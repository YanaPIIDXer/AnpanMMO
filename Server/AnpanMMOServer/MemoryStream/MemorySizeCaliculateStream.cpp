#include "stdafx.h"
#include "MemorySizeCaliculateStream.h"


//符号付き３２ビットシリアライズ
bool MemorySizeCaliculateStream::Serialize( s32 *pValue )
{

	Size += sizeof( s32 );
	return true;

}

//符号無し３２ビットシリアライズ
bool MemorySizeCaliculateStream::Serialize( u32 *pValue )
{

	Size += sizeof( u32 );
	return true;

}

//符号付き１６ビットシリアライズ
bool MemorySizeCaliculateStream::Serialize( s16 *pValue )
{

	Size += sizeof( s16 );
	return true;

}

//符号無し１６ビットシリアライズ
bool MemorySizeCaliculateStream::Serialize( u16 *pValue )
{

	Size += sizeof( u16 );
	return true;

}

//符号付き８ビットシリアライズ
bool MemorySizeCaliculateStream::Serialize( s8 *pValue )
{

	Size += sizeof( s8 );
	return true;

}

//符号無し８ビットシリアライズ
bool MemorySizeCaliculateStream::Serialize( u8 *pValue )
{

	Size += sizeof( u8 );
	return true;

}

//文字列シリアライズ
bool MemorySizeCaliculateStream::Serialize( std::string *pValue )
{

	Size += sizeof( s32 ) + pValue->size();
	return true;

}

// floatシリアライズ
bool MemorySizeCaliculateStream::Serialize(float *pValue)
{

	Size += sizeof(float);
	return true;

}
