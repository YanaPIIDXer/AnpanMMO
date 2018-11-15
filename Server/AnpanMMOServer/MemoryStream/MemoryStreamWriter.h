#ifndef __MEMORYSTREAMWRITER_H__
#define __MEMORYSTREAMWRITER_H__

#include "MemoryStreamInterface.h"

//メモリ書き込みクラス
class MemoryStreamWriter : public MemoryStreamInterface
{

public:

	//コンストラクタ
	MemoryStreamWriter(const int InSize);

	//デストラクタ
	virtual ~MemoryStreamWriter()
	{
		delete []pData;
	}

	//ストリーム取得
	const u8 *GetStream() const
	{
		return pData;	
	}

	//サイズ取得
	const int GetSize() const
	{
		return Size;
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

	// エラーが発生しているか？
	virtual bool IsError() const { return bError; }

private:

	//指定したサイズ分の書き込み
	bool Write(const void *pValue , const int ReadSize);

	//データのポインタ（先頭位置）
	u8 *pData;

	//データサイズ
	const int Size;

	//現在のストリーム位置
	int CurrentPosition;

	// エラーフラグ
	bool bError;

	//暗黙で定義されるものの封印
	MemoryStreamWriter();
	MemoryStreamWriter(const MemoryStreamWriter &Arg);
	MemoryStreamWriter operator =(const MemoryStreamWriter &Arg);

};

#endif		//#ifndef __MEMORYSTREAMWRITER_H__
