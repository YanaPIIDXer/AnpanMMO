#include "stdafx.h"
#include "MemoryStreamWriter.h"
#include <stdio.h>
#include <string.h>
#include "EndianConverter.h"

//�R���X�g���N�^
MemoryStreamWriter::MemoryStreamWriter(const int InSize)
	: Size(InSize) ,
	  CurrentPosition(0) ,
	  bError(false)
{
	pData = new u8[Size];
}

//�����t���R�Q�r�b�g�V���A���C�Y
bool MemoryStreamWriter::Serialize(s32 *pValue)
{
	s32 NetworkValue = EndianConverter::Convert(*pValue);
	if (!Write(&NetworkValue, sizeof(s32))) { return false; }

	return true;
}

//���������R�Q�r�b�g�V���A���C�Y
bool MemoryStreamWriter::Serialize(u32 *pValue)
{
	u32 NetworkValue = EndianConverter::Convert(*pValue);
	if (!Write(&NetworkValue, sizeof(u32))) { return false; }

	return true;
}

//�����t���P�U�r�b�g�V���A���C�Y
bool MemoryStreamWriter::Serialize(s16 *pValue)
{
	s16 NetworkValue = EndianConverter::Convert(*pValue);
	if (!Write(&NetworkValue, sizeof(s16))) { return false; }

	return true;
}

//���������P�U�r�b�g�V���A���C�Y
bool MemoryStreamWriter::Serialize(u16 *pValue)
{
	u16 NetworkValue = EndianConverter::Convert(*pValue);
	if (!Write(&NetworkValue, sizeof(u16))) { return false; }

	return true;
}

//�����t���W�r�b�g�V���A���C�Y
bool MemoryStreamWriter::Serialize(s8 *pValue)
{
	return Write(pValue, sizeof(s8));
}

//���������W�r�b�g�V���A���C�Y
bool MemoryStreamWriter::Serialize(u8 *pValue)
{
	return Write(pValue, sizeof(u8));

}

//������V���A���C�Y
bool MemoryStreamWriter::Serialize(std::string *pValue)
{
	//������̒���
	s32 Length = pValue->size();
	if (!Serialize(&Length)) { return false; }

	//������{��
	return Write(pValue->c_str(), Length);
}

// float�V���A���C�Y
bool MemoryStreamWriter::Serialize(float *pValue)
{
	float NetworkValue = EndianConverter::Convert(*pValue);
	return Write(&NetworkValue, sizeof(float));
}

//�w�肵���T�C�Y���̓ǂݍ���
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
