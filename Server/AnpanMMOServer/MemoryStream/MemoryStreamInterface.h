#ifndef __MEMORYSTREAMINTERFACE_H__
#define __MEMORYSTREAMINTERFACE_H__

#include "TypeDefs.h"
#include <string>

//�������X�g���[���𑀍삷��N���X����������C���^�t�F�[�X
class MemoryStreamInterface
{

public:

	//�����t���R�Q�r�b�g�V���A���C�Y
	virtual bool Serialize( s32 *pValue ) = 0;

	//���������R�Q�r�b�g�V���A���C�Y
	virtual bool Serialize( u32 *pValue ) = 0;

	//�����t���P�U�r�b�g�V���A���C�Y
	virtual bool Serialize( s16 *pValue ) = 0;

	//���������P�U�r�b�g�V���A���C�Y
	virtual bool Serialize( u16 *pValue ) = 0;

	//�����t���W�r�b�g�V���A���C�Y
	virtual bool Serialize( s8 *pValue ) = 0;

	//���������W�r�b�g�V���A���C�Y
	virtual bool Serialize( u8 *pValue ) = 0;

	//������V���A���C�Y
	virtual bool Serialize( std::string *pValue ) = 0;

	// float�V���A���C�Y
	virtual bool Serialize(float *pValue) = 0;

	// �G���[���������Ă��邩�H
	virtual bool IsError() const = 0;

};

#endif			//#ifndef __MEMORYSTREAMINTERFACE_H__
