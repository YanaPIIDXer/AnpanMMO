#ifndef __MEMORYBUFFER_H__
#define __MEMORYBUFFER_H__

#include "TypeDefs.h"

// メモリバッファ
class MemoryBuffer
{

private:

	// バッファサイズ
	static const s32 BUFFER_SIZE = 1024;

public:

	// コンストラクタ
	MemoryBuffer()
		: CurrentSize(0) 
	{ for( s32 i = 0 ; i < BUFFER_SIZE ; i++ ){ Buffer[i] = 0; } }

	// デストラクタ
	~MemoryBuffer(){}

	// 先頭取得
	u8 *GetTop(){ return Buffer; }

	// 現在のサイズ取得
	s32 GetSize(){ return CurrentSize; }

	// 追加
	void Push(const u8 *Data, s32 Size);

	// 消去
	void Pop(s32 Size);

private:

	// バッファ本体
	u8 Buffer[BUFFER_SIZE];

	// 現在のサイズ
	int CurrentSize;

};

#endif		// #ifndef __MEMORYBUFFER_H__
