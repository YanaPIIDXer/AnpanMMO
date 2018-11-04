#ifndef __PACKETBASE_H__
#define __PACKETBASE_H__

class MemoryStreamInterface;
#include "PacketID.h"

// パケット基底クラス
// 各種パケットはこのクラスを派生して定義する。
class PacketBase
{

public:

	// デストラクタ
	virtual ~PacketBase() {}

	// パケットＩＤ取得
	virtual PacketID GetPacketID() const = 0;

	//シリアライズ
	virtual bool Serialize(MemoryStreamInterface *pStream) = 0;

};

#endif		//#ifndef __PACKETBASE_H__