#ifndef __MEMORYSIZECALICULATESTREAM_H__
#define __MEMORYSIZECALICULATESTREAM_H__

#include "MemoryStreamInterface.h"

class MemorySizeCaliculateStream : public MemoryStreamInterface
{

public:

	//�R���X�g���N�^
	MemorySizeCaliculateStream()
		: Size(0){}

	// �f�X�g���N�^
	virtual ~MemorySizeCaliculateStream() {}

	//�v�Z���ʎ擾
	int GetSize(){ return Size; }
	
	//�����t���R�Q�r�b�g�V���A���C�Y
	virtual bool Serialize(s32 *pValue);

	//���������R�Q�r�b�g�V���A���C�Y
	virtual bool Serialize(u32 *pValue);

	//�����t���P�U�r�b�g�V���A���C�Y
	virtual bool Serialize(s16 *pValue);

	//���������P�U�r�b�g�V���A���C�Y
	virtual bool Serialize(u16 *pValue);

	//�����t���W�r�b�g�V���A���C�Y
	virtual bool Serialize(s8 *pValue);

	//���������W�r�b�g�V���A���C�Y
	virtual bool Serialize(u8 *pValue);

	//������V���A���C�Y
	virtual bool Serialize(std::string *pValue);

	// float�V���A���C�Y
	virtual bool Serialize(float *pValue);

	// �G���[���������Ă��邩�H
	// �T�C�Y�v�Z�ł̓G���[������
	virtual bool IsError() const { return false; }

	// ���Z�b�g
	virtual void Reset() { Size = 0; }

private:

	//�v�Z����
	int Size;

	//�ÖقŒ�`�������̂̕���
	MemorySizeCaliculateStream( const MemorySizeCaliculateStream &Arg );
	MemorySizeCaliculateStream operator =( const MemorySizeCaliculateStream &Arg );

};

#endif		//#ifndef __MEMORYSIZECALICULATESTREAM_H__
