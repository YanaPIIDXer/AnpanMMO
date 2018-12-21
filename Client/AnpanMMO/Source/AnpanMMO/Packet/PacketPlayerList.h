/**
 * @file PacketPlayerList.h
 * @brief プレイヤーリスト
 * @author NativePacketGenerator
 */

#ifndef __PACKETPLAYERLIST_H__
#define __PACKETPLAYERLIST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PlayerData.h"
#include "FlexArray.h"
#include "PacketID.h"


/**
 * @brief プレイヤーリスト
 */
class PacketPlayerList  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::PlayerList; }

	

	//! 
FlexArray<PlayerData> List;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPlayerList()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPlayerList(FlexArray<PlayerData> InList)
	{
		List = InList;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		List.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPLAYERLIST_H__
