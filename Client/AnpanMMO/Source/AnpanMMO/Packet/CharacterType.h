/**
 * @file CharacterType.h
 * @brief �L�����N�^�[�^�C�v�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __CHARACTERTYPE_H__
#define __CHARACTERTYPE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"


/**
 * @brief �L�����N�^�[�^�C�v�p�P�b�g
 */
class CharacterType 
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	

	enum Type
	{
		//! �v���C���[
		Player,
		//! �G�i�A���p���j
		Enemy,
	};

	

	/**
	 * @brief �R���X�g���N�^
	 */
	CharacterType()
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

#endif		// #ifndef __CHARACTERTYPE_H__
