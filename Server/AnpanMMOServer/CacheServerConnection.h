#ifndef __CACHESERVERCONNECTION_H__
#define __CACHESERVERCONNECTION_H__

#include "TCPConnection.h"

/**
 * キャッシュサーバとの接続.
 */
class CacheServerConnection : TCPConnection
{

public:

	// コンストラクタ
	CacheServerConnection(const shared_ptr<tcp::socket> &pInSocket);

	// デストラクタ
	virtual ~CacheServerConnection() {}

	// 接続.
	bool Connect();

protected:

private:

};

#endif		// #ifndef __CACHESERVERCONNECTION_H__
