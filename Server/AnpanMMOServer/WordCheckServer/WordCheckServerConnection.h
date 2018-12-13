#ifndef __WORDCHECKSERVERCONNECTION_H__
#define __WORDCHECKSERVERCONNECTION_H__

#include "TCPConnection.h"

class PacketBase;

/**
 * キャッシュサーバとの接続.
 */
class WordCheckServerConnection : public TCPConnection, public noncopyable
{

public:

	// コンストラクタ
	WordCheckServerConnection(const shared_ptr<tcp::socket> &pInSocket);

	// デストラクタ
	virtual ~WordCheckServerConnection() {}

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

	static WordCheckServerConnection *GetInstance() { return pInstance; }

private:

	static WordCheckServerConnection *pInstance;

};

#endif		// #ifndef __WORDCHECKSERVERCONNECTION_H__
