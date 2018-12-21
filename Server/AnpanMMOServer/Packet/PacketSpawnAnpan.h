/**
 * @file PacketSpawnAnpan.h
 * @brief アンパン生成
 * @author NativePacketGenerator
 */

#ifndef __PACKETSPAWNANPAN_H__
#define __PACKETSPAWNANPAN_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "AnpanData.h"
#include "PacketID.h"


/**
 * @brief アンパン生成
 */
class PacketSpawnAnpan  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SpawnAnpan; }

	

	//! 
AnpanData Data;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSpawnAnpan()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSpawnAnpan(AnpanData InData)
	{
		Data = InData;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		Data.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSPAWNANPAN_H__
