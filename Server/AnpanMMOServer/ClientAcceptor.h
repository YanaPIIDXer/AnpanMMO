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

	// Accept開始.
	void Start();

private:

	// IOService
	asio::io_service &IOService;

	// アクセプタ
	tcp::acceptor Acceptor;

	// Socket
	shared_ptr<tcp::socket> pSocket;

	// Accept待機中？
	bool bWaitingAccept;


	// Accept開始.
	void StartAccept();

	// Acceptした
	void OnAccept(const boost::system::error_code &ErrorCode);

};

#endif		// #ifndef __CLIENTACCEPTOR_H__
