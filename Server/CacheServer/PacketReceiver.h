#ifndef __PACKETRECEIVER_H__
#define __PACKETRECEIVER_H__

#include <boost/function.hpp>
#include <boost/unordered_map.hpp>
#include "Packet/PacketID.h"

class GameServerConnection;
class MemoryStreamInterface;

/**
 * パケットを受信するクラス
 */
class PacketReceiver
{

private:		// 別名定義.

	typedef function<void(MemoryStreamInterface *)> PacketFunc;
	typedef unordered_map<PacketID, PacketFunc> PacketFuncMap;

public:

	// コンストラクタ
	PacketReceiver(GameServerConnection *pInParent);

	// デストラクタ
	~PacketReceiver() {}

	// パケット受信.
	void RecvPacket(PacketID ID, MemoryStreamInterface *pStream);

private:

	// 親.
	GameServerConnection *pParent;

	// パケット受信関数マップ
	PacketFuncMap PacketFuncs;


	// パケット受信関数を追加.
	void AddPacketFunc(PacketID ID, const PacketFunc &Func);

	// ログインリクエストを受信した。
	void OnRecvLogInRequest(MemoryStreamInterface *pStream);

	// キャラクタ情報リクエストを受信した。
	void OnRecvCharacterDataRequest(MemoryStreamInterface *pStream);

};

#endif		// #ifndef __PACKETRECEIVER_H__
