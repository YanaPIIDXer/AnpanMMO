#ifndef __CACHESERVERCONNECTION_H__
#define __CACHESERVERCONNECTION_H__

#include "TCPConnection.h"

class PacketBase;

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

	// パケット送信.
	void SendPacket(PacketBase *pPacket);

protected:

	// データを受信した。
	virtual void OnRecvData(size_t Size);

	// 切断された。
	virtual void OnDisconnected();

private:

	// ============ Singletonもどき ================

public:

	static CacheServerConnection *GetInstance() { return pInstance; }

private:

	static CacheServerConnection *pInstance;

};

#endif		// #ifndef __CACHESERVERCONNECTION_H__
