#ifndef __GAMESERVERCONNECTION_H__
#define __GAMESERVERCONNECTION_H__

#include "TCPConnection.h"

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

protected:

private:

	// アクセプタ
	tcp::acceptor Acceptor;

};

#endif		// #ifndef __GAMESERVERCONNECTION_H__
