/**
 * @file PacketReceiveNotice.h
 * @brief 通知
 * @author NativePacketGenerator
 */

#ifndef __PACKETRECEIVENOTICE_H__
#define __PACKETRECEIVENOTICE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "NoticeData.h"
#include "PacketID.h"


/**
 * @brief 通知
 */
class PacketReceiveNotice  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::ReceiveNotice; }

	

	//! 通知データ
	NoticeData Notice;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketReceiveNotice()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketReceiveNotice(NoticeData InNotice)
	{
		Notice = InNotice;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrn 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		Notice.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETRECEIVENOTICE_H__
