#ifndef __MEMORYSIZECALICULATESTREAM_H__
#define __MEMORYSIZECALICULATESTREAM_H__

#include "MemoryStreamInterface.h"

class MemorySizeCaliculateStream : public MemoryStreamInterface
{

public:

	//コンストラクタ
	MemorySizeCaliculateStream()
		: Size(0){}

	// デストラクタ
	virtual ~MemorySizeCaliculateStream() {}

	//計算結果取得
	int GetSize(){ return Size; }
	
	//符号付き３２ビットシリアライズ
	virtual bool Serialize(s32 *pValue);

	//符号無し３２ビットシリアライズ
	virtual bool Serialize(u32 *pValue);

	//符号付き１６ビットシリアライズ
	virtual bool Serialize(s16 *pValue);

	//符号無し１６ビットシリアライズ
	virtual bool Serialize(u16 *pValue);

	//符号付き８ビットシリアライズ
	virtual bool Serialize(s8 *pValue);

	//符号無し８ビットシリアライズ
	virtual bool Serialize(u8 *pValue);

	//文字列シリアライズ
	virtual bool Serialize(std::string *pValue);

	// floatシリアライズ
	virtual bool Serialize(float *pValue);

	// エラーが発生しているか？
	// サイズ計算ではエラーが無い
	virtual bool IsError() const { return false; }

	// リセット
	virtual void Reset() { Size = 0; }

private:

	//計算結果
	int Size;

	//暗黙で定義されるものの封印
	MemorySizeCaliculateStream( const MemorySizeCaliculateStream &Arg );
	MemorySizeCaliculateStream operator =( const MemorySizeCaliculateStream &Arg );

};

#endif		//#ifndef __MEMORYSIZECALICULATESTREAM_H__
