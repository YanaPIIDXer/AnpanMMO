#ifndef __MEMORYSTREAMWRITER_H__
#define __MEMORYSTREAMWRITER_H__

#include "MemoryStreamInterface.h"

//�������������݃N���X
class MemoryStreamWriter : public MemoryStreamInterface
{

public:

	//�R���X�g���N�^
	MemoryStreamWriter(const int InSize);

	//�f�X�g���N�^
	virtual ~MemoryStreamWriter()
	{
		delete []pData;
	}

	//�X�g���[���擾
	const u8 *GetStream() const
	{
		return pData;	
	}

	//�T�C�Y�擾
	const int GetSize() const
	{
		return Size;
	}

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
	virtual bool IsError() const { return bError; }

private:

	//�w�肵���T�C�Y���̏�������
	bool Write(const void *pValue , const int ReadSize);

	//�f�[�^�̃|�C���^�i�擪�ʒu�j
	u8 *pData;

	//�f�[�^�T�C�Y
	const int Size;

	//���݂̃X�g���[���ʒu
	int CurrentPosition;

	// �G���[�t���O
	bool bError;

	//�ÖقŒ�`�������̂̕���
	MemoryStreamWriter();
	MemoryStreamWriter(const MemoryStreamWriter &Arg);
	MemoryStreamWriter operator =(const MemoryStreamWriter &Arg);

};

#endif		//#ifndef __MEMORYSTREAMWRITER_H__
