/**
 * @file PacketInstanceAreaTicketProcess.h
 * @brief インスタンスマップチケット処理
 * @author NativePacketGenerator
 */

#ifndef __PACKETINSTANCEAREATICKETPROCESS_H__
#define __PACKETINSTANCEAREATICKETPROCESS_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief インスタンスマップチケット処理
 */
class PacketInstanceAreaTicketProcess  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::InstanceAreaTicketProcess; }

	enum ProcessType
	{
		//! 
		Enter = 入る,
		//! 
		Discard = 破棄,
	};

	//! 
u32 TicketId;
	//! 
u8 Process;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketInstanceAreaTicketProcess()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketInstanceAreaTicketProcess(u32 InTicketId, u8 InProcess)
	{
		TicketId = InTicketId;
		Process = InProcess;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&TicketId);
		pStream->Serialize(&Process);
		
		return true;
	}
};

#endif		// #ifndef __PACKETINSTANCEAREATICKETPROCESS_H__
