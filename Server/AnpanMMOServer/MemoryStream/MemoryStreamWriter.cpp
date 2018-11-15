#include "stdafx.h"
#include "MemoryStreamWriter.h"
#include <stdio.h>
#include <string.h>
#include "EndianConverter.h"

//コンストラクタ
MemoryStreamWriter::MemoryStreamWriter(const int InSize)
	: Size(InSize) ,
	  CurrentPosition(0) ,
	  bError(false)
{
	pData = new u8[Size];
}

//符号付き３２ビットシリアライズ
bool MemoryStreamWriter::Serialize(s32 *pValue)
{
	s32 NetworkValue = EndianConverter::Convert(*pValue);
	if (!Write(&NetworkValue, sizeof(s32))) { return false; }

	return true;
}

//符号無し３２ビットシリアライズ
bool MemoryStreamWriter::Serialize(u32 *pValue)
{
	u32 NetworkValue = EndianConverter::Convert(*pValue);
	if (!Write(&NetworkValue, sizeof(u32))) { return false; }

	return true;
}

//符号付き１６ビットシリアライズ
bool MemoryStreamWriter::Serialize(s16 *pValue)
{
	s16 NetworkValue = EndianConverter::Convert(*pValue);
	if (!Write(&NetworkValue, sizeof(s16))) { return false; }

	return true;
}

//符号無し１６ビットシリアライズ
bool MemoryStreamWriter::Serialize(u16 *pValue)
{
	u16 NetworkValue = EndianConverter::Convert(*pValue);
	if (!Write(&NetworkValue, sizeof(u16))) { return false; }

	return true;
}

//符号付き８ビットシリアライズ
bool MemoryStreamWriter::Serialize(s8 *pValue)
{
	return Write(pValue, sizeof(s8));
}

//符号無し８ビットシリアライズ
bool MemoryStreamWriter::Serialize(u8 *pValue)
{
	return Write(pValue, sizeof(u8));

}

//文字列シリアライズ
bool MemoryStreamWriter::Serialize(std::string *pValue)
{
	//文字列の長さ
	s32 Length = pValue->size();
	if (!Serialize(&Length)) { return false; }

	//文字列本文
	return Write(pValue->c_str(), Length);
}

// floatシリアライズ
bool MemoryStreamWriter::Serialize(float *pValue)
{
	float NetworkValue = EndianConverter::Convert(*pValue);
	return Write(&NetworkValue, sizeof(float));
}

//指定したサイズ分の読み込み
bool MemoryStreamWriter::Write(const void *pValue ,const int WriteSize)
{
	if(CurrentPosition >= Size)
	{
		bError = true;
		return false;
	}

	memcpy((pData + CurrentPosition), pValue, WriteSize);
	CurrentPosition += WriteSize;
	return true;

}
