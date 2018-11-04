#ifndef __MEMORYBUFFER_H__
#define __MEMORYBUFFER_H__

#include "TypeDefs.h"

// �������o�b�t�@
class MemoryBuffer
{

private:

	// �o�b�t�@�T�C�Y
	static const s32 BUFFER_SIZE = 1024;

public:

	// �R���X�g���N�^
	MemoryBuffer()
		: CurrentSize(0) 
	{ for( s32 i = 0 ; i < BUFFER_SIZE ; i++ ){ Buffer[i] = 0; } }

	// �f�X�g���N�^
	~MemoryBuffer(){}

	// �擪�擾
	u8 *GetTop(){ return Buffer; }

	// ���݂̃T�C�Y�擾
	s32 GetSize(){ return CurrentSize; }

	// �ǉ�
	void Push(const u8 *Data, s32 Size);

	// ����
	void Pop(s32 Size);

private:

	// �o�b�t�@�{��
	u8 Buffer[BUFFER_SIZE];

	// ���݂̃T�C�Y
	int CurrentSize;

};

#endif		// #ifndef __MEMORYBUFFER_H__
