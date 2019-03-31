/**
 * @file CharacterJob.h
 * @brief �W���u�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __CHARACTERJOB_H__
#define __CHARACTERJOB_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"


/**
 * @brief �W���u�p�P�b�g
 */
class CharacterJob 
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	

	enum Type
	{
		//! �t�@�C�^�[
		Fighter,
		//! �\�[�T���[
		Sorcerer,
		//! �q�[���[
		Healer,
		//! �����T�[
		Lancer,
	};

	

	/**
	 * @brief �R���X�g���N�^
	 */
	CharacterJob()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __CHARACTERJOB_H__
