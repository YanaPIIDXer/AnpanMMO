#include "stdafx.h"
#include "MemoryStreamReader.h"
#include <stdio.h>
#include <string.h>
#include "EndianConverter.h"

//コンストラクタ
MemoryStreamReader::MemoryStreamReader(const u8 *pInData , const int InSize)
	: Size(InSize) ,
	  CurrentPosition(0) ,
	  bError(false)
{
	pData = new u8[Size];
	memcpy(pData, pInData, Size);
}

//符号付き３２ビットシリアライズ
bool MemoryStreamReader::Serialize( s32 *pValue )
{
	s32 NetworkValue;

	if (!Read(&NetworkValue, sizeof(s32))) { return false; }

	*pValue = EndianConverter::Convert( NetworkValue );
	return true;

}

//符号無し３２ビットシリアライズ
bool MemoryStreamReader::Serialize(u32 *pValue)
{
	u32 NetworkValue;
	if (!Read(&NetworkValue, sizeof(u32))) { return false; }

	*pValue = EndianConverter::Convert( NetworkValue );
	return true;

}

//符号付き１６ビットシリアライズ
bool MemoryStreamReader::Serialize( s16 *pValue )
{
	s16 NetworkValue;
	if (!Read(&NetworkValue, sizeof(s16))) { return false; }

	*pValue = EndianConverter::Convert( NetworkValue );
	return true;

}

//符号無し１６ビットシリアライズ
bool MemoryStreamReader::Serialize( u16 *pValue )
{
	u16 NetworkValue;
	if (!Read(&NetworkValue, sizeof(u16))) { return false; }

	*pValue = EndianConverter::Convert( NetworkValue );
	return true;

}

//符号付き８ビットシリアライズ
bool MemoryStreamReader::Serialize(s8 *pValue)
{
	return Read(pValue, sizeof(s8));
}

//符号無し８ビットシリアライズ
bool MemoryStreamReader::Serialize(u8 *pValue)
{
	return Read(pValue, sizeof(u8));
}

//文字列シリアライズ
bool MemoryStreamReader::Serialize(std::string *pValue)
{
	//文字列の長さ
	s32 Length = 0;
	if (!Serialize(&Length)) { return false; }

	//文字列本文
	char *pStr = new char[Length + 1];
	bool bResult = Read(pStr, Length);

	if(bResult)
	{
		pStr[Length] = '\0';
		*pValue = pStr;
	}

	delete []pStr;
	return bResult;
}

// floatシリアライズ
bool MemoryStreamReader::Serialize(float *pValue)
{
	float NetworkValue;
	if (!Read(&NetworkValue, sizeof(float))) { return false; }
	*pValue = EndianConverter::Convert(NetworkValue);
	return true;
}

// リセット
void MemoryStreamReader::Reset()
{
	CurrentPosition = 0;
}


//指定したサイズ分の読み込み
bool MemoryStreamReader::Read(void *pValue, int ReadSize)
{
	if(ReadSize + CurrentPosition > Size)
	{
		//データサイズオーバー
		bError = true;
		return false;
	}

	memcpy(pValue, (pData + CurrentPosition), ReadSize);

	CurrentPosition += ReadSize;
	return true;
}
