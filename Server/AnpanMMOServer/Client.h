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

};

#endif		// #ifndef __CLIENT_H__
