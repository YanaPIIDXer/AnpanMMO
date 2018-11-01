#ifndef __CLIENTACCEPTOR_H__
#define __CLIENTACCEPTOR_H__

/**
 * クライアントの接続を待機するクラス
 */
class ClientAcceptor
{

public:

	// コンストラクタ
	ClientAcceptor(asio::io_service &InIOService, int Port);

	// 定期処理.
	void Poll();

private:

	// IOService
	asio::io_service &IOService;

	// アクセプタ
	tcp::acceptor Acceptor;

};

#endif		// #ifndef __CLIENTACCEPTOR_H__
