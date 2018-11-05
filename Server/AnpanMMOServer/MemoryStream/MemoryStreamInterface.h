#ifndef __MEMORYSTREAMINTERFACE_H__
#define __MEMORYSTREAMINTERFACE_H__

#include "TypeDefs.h"
#include <string>

//メモリストリームを操作するクラスが実装するインタフェース
class MemoryStreamInterface
{

public:

	//符号付き３２ビットシリアライズ
	virtual bool Serialize( s32 *pValue ) = 0;

	//符号無し３２ビットシリアライズ
	virtual bool Serialize( u32 *pValue ) = 0;

	//符号付き１６ビットシリアライズ
	virtual bool Serialize( s16 *pValue ) = 0;

	//符号無し１６ビットシリアライズ
	virtual bool Serialize( u16 *pValue ) = 0;

	//符号付き８ビットシリアライズ
	virtual bool Serialize( s8 *pValue ) = 0;

	//符号無し８ビットシリアライズ
	virtual bool Serialize( u8 *pValue ) = 0;

	//文字列シリアライズ
	virtual bool Serialize( std::string *pValue ) = 0;

	// floatシリアライズ
	virtual bool Serialize(float *pValue) = 0;

	// エラーが発生しているか？
	virtual bool IsError() const = 0;

};

#endif			//#ifndef __MEMORYSTREAMINTERFACE_H__
