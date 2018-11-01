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

private:

	// Socket
	shared_ptr<tcp::socket> pSocket;

};

#endif		// #ifndef __CLIENT_H__
