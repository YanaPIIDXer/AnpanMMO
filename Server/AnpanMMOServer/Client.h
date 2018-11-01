#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "MemoryBuffer.h"

/**
 * クライアントクラス
 */
class Client
{

public:

	// コンストラクタ
	Client(const shared_ptr<tcp::socket> &pInSocket);

	// デストラクタ
	~Client() {}

	// 接続されているか？
	bool IsConnected() const { return bIsConnected; }

private:

	enum
	{
		RecvDataSize = 1024,
	};

	// Socket
	shared_ptr<tcp::socket> pSocket;

	// 接続されているか？
	bool bIsConnected;

	// 受信バッファ.
	MemoryBuffer RecvBuffer;

	// 受信データ
	array<u8, RecvDataSize> RecvData;


	// 受信開始.
	void AsyncRecv(u8 *pBuffer, int Offset);

	// 受信した。
	void OnRecv(const system::error_code &ErrorCode, size_t Size);

	// 送信.
	void AsyncSend(u8 *pBuffer, int Size);

	// 送信した。
	void OnSend(const system::error_code &ErrorCode, size_t Size);

};

#endif		// #ifndef __CLIENT_H__
