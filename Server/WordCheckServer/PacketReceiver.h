#ifndef __PACKETRECEIVER_H__
#define __PACKETRECEIVER_H__

#include <boost/function.hpp>
#include <boost/unordered_map.hpp>

class GameServerConnection;
class MemoryStreamInterface;

/**
 * パケットを受信するクラス
 */
class PacketReceiver
{

private:		// 別名定義.

	typedef function<void(MemoryStreamInterface *)> PacketFunc;
	typedef unordered_map<u8, PacketFunc> PacketFuncMap;

public:

	// コンストラクタ
	PacketReceiver(GameServerConnection *pInParent);

	// デストラクタ
	~PacketReceiver() {}

	// パケット受信.
	void RecvPacket(u8 ID, MemoryStreamInterface *pStream);

private:

	// 親.
	GameServerConnection *pParent;

	// パケット受信関数マップ
	PacketFuncMap PacketFuncs;


	// パケット受信関数を追加.
	void AddPacketFunc(u8 ID, const PacketFunc &Func);

	// チャットのワードチェック要求を受信した。
	void OnRecvChatWordCheckRequest(MemoryStreamInterface *pStream);

};

#endif		// #ifndef __PACKETRECEIVER_H__
