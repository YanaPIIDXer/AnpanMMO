#ifndef __CACHESERVERCONNECTION_H__
#define __CACHESERVERCONNECTION_H__

#include "TCPConnection.h"
#include "CachePacketReceiver.h"

/**
 * キャッシュサーバとの接続.
 */
class CacheServerConnection : public TCPConnection, public noncopyable
{

public:

	// コンストラクタ
	CacheServerConnection(const shared_ptr<tcp::socket> &pInSocket);

	// デストラクタ
	virtual ~CacheServerConnection() {}

	// 接続.
	bool Connect();

protected:

	// データを受信した。
	virtual void OnRecvData(size_t Size);

private:

	// パケット受信.
	CachePacketReceiver Receiver;

	// ============ Singletonもどき ================

public:

	static CacheServerConnection *GetInstance() { return pInstance; }

private:

	static CacheServerConnection *pInstance;

};

#endif		// #ifndef __CACHESERVERCONNECTION_H__
