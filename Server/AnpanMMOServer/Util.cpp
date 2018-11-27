#include "stdafx.h"
#include "Util.h"

// 全角文字を考慮した文字列の長さを取得.
u32 Util::CalcStringLength(const std::string &Str)
{
	u32 Length = 0;
	for (u32 i = 0; i < Str.size(); i++)
	{
		unsigned char Ch = *(Str.c_str() + i);
		Length += CalcCharByte(Ch);
	}

	return Length;
}

// 文字のバイト数を取得.
u32 Util::CalcCharByte(unsigned char Ch)
{
	if (Ch <= 0x7f) { return 1; }
	if ((Ch >= 0xc2) && (Ch <= 0xdf)) { return 2; }
	if ((Ch >= 0xe0) && (Ch <= 0xef)) { return 3; }
	if ((Ch >= 0xf0) && (Ch <= 0xf7)) { return 4; }
	if ((Ch >= 0xf8) && (Ch <= 0xfb)) { return 5; }
	if ((Ch >= 0xfc) && (Ch <= 0xfd)) { return 6; }
	return 0;
}
