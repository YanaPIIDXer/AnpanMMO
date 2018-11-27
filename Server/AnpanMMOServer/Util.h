#ifndef __UTIL_H__
#define __UTIL_H__

class Util
{

public:

	// 全角文字を考慮した文字列の長さを取得.
	static u32 CalcStringLength(const std::string &Str);

	// 文字のバイト数を取得.
	static u32 CalcCharByte(unsigned char Ch);

};

#endif		// #ifndef __UTIL_H__
