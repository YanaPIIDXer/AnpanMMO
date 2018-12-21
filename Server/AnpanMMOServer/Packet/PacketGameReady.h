/**
 * @file PacketGameReady.h
 * @brief 準備完了
 * @author NativePacketGenerator
 */

#ifndef __PACKETGAMEREADY_H__
#define __PACKETGAMEREADY_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief 準備完了
 */
class PacketGameReady  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::GameReady; }

	

	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketGameReady()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETGAMEREADY_H__
