#ifndef __CLIENT_H__
#define __CLIENT_H__

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

	// Socket
	shared_ptr<tcp::socket> pSocket;

	// 接続されているか？
	bool bIsConnected;

	// 受信バッファ.
	array<u8, 1024> RecvBuffer;


	// 受信開始.
	void AsyncRecv(u8 *pBuffer, int Offset);

	// 受信した。
	void OnRecv(const system::error_code &Error, size_t Size);

};

#endif		// #ifndef __CLIENT_H__
