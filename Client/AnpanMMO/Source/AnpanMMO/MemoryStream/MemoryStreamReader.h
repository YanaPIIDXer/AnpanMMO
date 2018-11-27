#ifndef __MEMORYSTREAMREADER_H__
#define __MEMORYSTREAMREADER_H__

#include "MemoryStreamInterface.h"

//メモリストリーム読み込み
class MemoryStreamReader : public MemoryStreamInterface
{

public:

	//コンストラクタ
	MemoryStreamReader(const u8 *pInData, const int InSize);

	//デストラクタ
	virtual ~MemoryStreamReader()
	{
		delete []pData;
	}

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

	// 読み込み用か？
	virtual bool IsReadMode() { return true; }

	// エラーが発生しているか？
	virtual bool IsError() const { return bError; }

	// リセット
	virtual void Reset();

private:

	//指定したサイズ分の読み込み
	bool Read(void *pValue , int ReadSize);

	//データのポインタ（先頭位置）
	u8 *pData;

	//データサイズ
	const int Size;

	//現在のストリーム位置
	int CurrentPosition;

	// エラーフラグ
	bool bError;

	//暗黙で定義されるものの封印
	MemoryStreamReader();
	MemoryStreamReader(const MemoryStreamReader &Arg);
	MemoryStreamReader operator =(const MemoryStreamReader &Arg );

};

#endif		//#ifndef __MEMORYSTREAMREADER_H__
