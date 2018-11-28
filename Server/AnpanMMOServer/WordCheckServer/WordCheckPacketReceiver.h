#ifndef __WORDCHECKPACKETRECEIVER_H__
#define __WORDCHECKPACKETRECEIVER_H__

#include <boost/function.hpp>
#include <boost/unordered_map.hpp>
#include "Packet/PacketID.h"

class WordCheckServerConnection;
class MemoryStreamInterface;

/**
 * パケットを受信するクラス
 */
class WordCheckPacketReceiver
{

private:		// 別名定義.

	typedef function<void(MemoryStreamInterface *)> PacketFunc;
	typedef unordered_map<PacketID, PacketFunc> PacketFuncMap;

public:

	// コンストラクタ
	WordCheckPacketReceiver(WordCheckServerConnection *pInParent);

	// デストラクタ
	~WordCheckPacketReceiver() {}

	// パケット受信.
	void RecvPacket(PacketID ID, MemoryStreamInterface *pStream);

private:

	// 親.
	WordCheckServerConnection *pParent;

	// パケット受信関数マップ
	PacketFuncMap PacketFuncs;


	// パケット受信関数を追加.
	void AddPacketFunc(PacketID ID, const PacketFunc &Func);

	// チャットのワードチェック結果を受信した。
	void OnRecvChatWordCheckResult(MemoryStreamInterface *pStream);

};

#endif		// #ifndef __WORDCHECKPACKETRECEIVER_H__
