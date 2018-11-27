#ifndef __STRINGPACK_H__
#define __STRINGPACK_H__

#include "MemoryStream/MemoryStreamInterface.h"

/**
 * 文字列パック
 */
template<std::size_t SIZE>
class StringPack
{

public:

	// コンストラクタ
	StringPack()
	{
		pString = new u8[SIZE];
		memset(pString, 0, SIZE);
	}

	StringPack(char *pStr)
	{
		pString = new u8[SIZE];
		Set(pStr);
	}

	// デストラクタ
	~StringPack()
	{
		delete[] pString;
	}

	// 文字列をセット.
	void Set(char *pStr)
	{
		int Size = strlen(pStr);
		if (Size >= SIZE)
		{
			Size = SIZE - 1;
		}
		memset(pString, 0, SIZE);
		memcpy(pString, pStr, Size);
	}

	// 取得.
	const u8 *Get() const { return pString; }

	// 文字列長を取得.
	u32 GetLength() const
	{
		u32 Length = 0;
		for (unsigned int i = 0; i < SIZE; i++)
		{
			if (pString[i] == '\0') { break; }
			Length += GetByte(pString[i]);
		}
		return Length;
	}

	// シリアライズ
	bool Serialize(MemoryStreamInterface *pStream)
	{
		if (!pStream->Serialize(pString)) { return false; }
		return true;
	}

private:

	// 文字列.
	u8 *pString;


	// バイト数を取得.
	static u32 GetByte(unsigned char Ch)
	{
		if (Ch <= 0x7f) { return 1; }
		if ((Ch >= 0xc2) && (Ch <= 0xdf)) { return 2; }
		if ((Ch >= 0xe0) && (Ch <= 0xef)) { return 3; }
		if ((Ch >= 0xf0) && (Ch <= 0xf7)) { return 4; }
		if ((Ch >= 0xf8) && (Ch <= 0xfb)) { return 5; }
		if ((Ch >= 0xfc) && (Ch <= 0xfd)) { return 6; }

		return 0;
	}

};

#endif		// #ifndef __STRINGPACK_H__
