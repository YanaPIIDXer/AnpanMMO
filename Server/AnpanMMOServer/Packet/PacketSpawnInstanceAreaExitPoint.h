/**
 * @file PacketSpawnInstanceAreaExitPoint.h
 * @brief インスタンスマップ脱出ポイント生成
 * @author NativePacketGenerator
 */

#ifndef __PACKETSPAWNINSTANCEAREAEXITPOINT_H__
#define __PACKETSPAWNINSTANCEAREAEXITPOINT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief インスタンスマップ脱出ポイント生成
 */
class PacketSpawnInstanceAreaExitPoint  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SpawnInstanceAreaExitPoint; }

	

	//! 
u32 WarpPointId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSpawnInstanceAreaExitPoint()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSpawnInstanceAreaExitPoint(u32 InWarpPointId)
	{
		WarpPointId = InWarpPointId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&WarpPointId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSPAWNINSTANCEAREAEXITPOINT_H__
