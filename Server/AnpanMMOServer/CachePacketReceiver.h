#ifndef __CACHEPACKETRECEIVER_H__
#define __CACHEPACKETRECEIVER_H__

#include <boost/function.hpp>
#include <boost/unordered_map.hpp>
#include "Packet/PacketID.h"

class CacheServerConnection;
class MemoryStreamInterface;

/**
 * パケットを受信するクラス
 */
class CachePacketReceiver
{

private:		// 別名定義.

	typedef function<void(MemoryStreamInterface *)> PacketFunc;
	typedef unordered_map<PacketID, PacketFunc> PacketFuncMap;

public:

	// コンストラクタ
	CachePacketReceiver(CacheServerConnection *pInParent);

	// デストラクタ
	~CachePacketReceiver() {}

	// パケット受信.
	void RecvPacket(PacketID ID, MemoryStreamInterface *pStream);

private:

	// 親.
	CacheServerConnection *pParent;

	// パケット受信関数マップ
	PacketFuncMap PacketFuncs;


	// パケット受信関数を追加.
	void AddPacketFunc(PacketID ID, const PacketFunc &Func);

};

#endif		// #ifndef __CACHEPACKETRECEIVER_H__
