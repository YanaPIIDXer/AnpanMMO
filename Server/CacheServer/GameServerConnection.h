#ifndef __GAMESERVERCONNECTION_H__
#define __GAMESERVERCONNECTION_H__

#include "TCPConnection.h"
#include "PacketReceiver.h"

class PacketBase;

/**
 * ゲームサーバへの接続クラス
 */
class GameServerConnection : public TCPConnection
{

public:

	// コンストラクタ
	GameServerConnection(asio::io_service &IOService, const shared_ptr<tcp::socket> &pInSocket);

	// デストラクタ
	virtual ~GameServerConnection() {}

	// パケット送信.
	void SendPacket(PacketBase *pPacket);

protected:

	// データを受信した。
	virtual void OnRecvData(size_t Size);

private:

	// アクセプタ
	tcp::acceptor Acceptor;

	// パケット受信.
	PacketReceiver Receiver;


	// Acceptする。
	void Accept();

	// Acceptした。
	void OnAccept(const boost::system::error_code &ErrorCode);

};

#endif		// #ifndef __GAMESERVERCONNECTION_H__
