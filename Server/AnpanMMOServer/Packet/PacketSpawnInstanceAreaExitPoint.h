/**
 * @file PacketSpawnInstanceAreaExitPoint.h
 * @brief �C���X�^���X�}�b�v�E�o�|�C���g����
 * @author NativePacketGenerator
 */

#ifndef __PACKETSPAWNINSTANCEAREAEXITPOINT_H__
#define __PACKETSPAWNINSTANCEAREAEXITPOINT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �C���X�^���X�}�b�v�E�o�|�C���g����
 */
class PacketSpawnInstanceAreaExitPoint  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SpawnInstanceAreaExitPoint; }

	

	//! ���[�v�|�C���g�h�c
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
	 * @param[in] pStream �X�g���[��
	 * @retrn ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&WarpPointId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSPAWNINSTANCEAREAEXITPOINT_H__
