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
	GameServerConnection(const shared_ptr<tcp::socket> &pInSocket);

	// デストラクタ
	virtual ~GameServerConnection() {}

protected:

private:

};

#endif		// #ifndef __GAMESERVERCONNECTION_H__
