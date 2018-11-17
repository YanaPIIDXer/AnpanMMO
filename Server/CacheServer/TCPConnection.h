#ifndef __TCPCONNECTION_H__
#define __TCPCONNECTION_H__

#include "MemoryBuffer.h"

/**
 * TCP接続クラス
 */
class TCPConnection
{

public:

	// コンストラクタ
	TCPConnection(const shared_ptr<tcp::socket> &pInSocket);

	// デストラクタ
	virtual ~TCPConnection() = 0;

	// 接続されているか？
	bool IsConnected() const { return bIsConnected; }

protected:

	// 受信バッファ.
	MemoryBuffer RecvBuffer;

	// 受信開始.
	void AsyncRecv();

	// データを受信した。
	virtual void OnRecvData(size_t Size) {}

	// 送信.
	void AsyncSend(const u8 *pBuffer, int Size);

private:

	enum
	{
		RecvDataSize = 1024,
	};

	// Socket
	shared_ptr<tcp::socket> pSocket;

	// 接続されているか？
	bool bIsConnected;

	// 受信データ
	array<u8, RecvDataSize> RecvData;

	// 送信した。
	void OnSend(const boost::system::error_code &ErrorCode, size_t Size, shared_ptr<asio::streambuf> SendBuffer);

	// 受信した。
	void OnRecv(const boost::system::error_code &ErrorCode, size_t Size);

};

#endif		// #ifndef __TCPCONNECTION_H__
