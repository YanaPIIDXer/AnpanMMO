#ifndef __MEMORYSTREAMREADER_H__
#define __MEMORYSTREAMREADER_H__

#include "MemoryStreamInterface.h"

//�������X�g���[���ǂݍ���
class MemoryStreamReader : public MemoryStreamInterface
{

public:

	//�R���X�g���N�^
	MemoryStreamReader(const u8 *pInData, const int InSize);

	//�f�X�g���N�^
	virtual ~MemoryStreamReader()
	{
		delete []pData;
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

	// �ǂݍ��ݗp���H
	virtual bool IsReadMode() { return true; }

	// �G���[���������Ă��邩�H
	virtual bool IsError() const { return bError; }

	// ���Z�b�g
	virtual void Reset();

private:

	//�w�肵���T�C�Y���̓ǂݍ���
	bool Read(void *pValue , int ReadSize);

	//�f�[�^�̃|�C���^�i�擪�ʒu�j
	u8 *pData;

	//�f�[�^�T�C�Y
	const int Size;

	//���݂̃X�g���[���ʒu
	int CurrentPosition;

	// �G���[�t���O
	bool bError;

	//�ÖقŒ�`�������̂̕���
	MemoryStreamReader();
	MemoryStreamReader(const MemoryStreamReader &Arg);
	MemoryStreamReader operator =(const MemoryStreamReader &Arg );

};

#endif		//#ifndef __MEMORYSTREAMREADER_H__
