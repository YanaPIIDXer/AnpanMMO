#ifndef __CLIENTACCEPTOR_H__
#define __CLIENTACCEPTOR_H__

/**
 * �N���C�A���g�̐ڑ���ҋ@����N���X
 */
class ClientAcceptor
{

public:

	// �R���X�g���N�^
	ClientAcceptor(asio::io_service &InIOService, int Port);

	// �������.
	void Poll();

	// Accept�J�n.
	void Start();

private:

	// IOService
	asio::io_service &IOService;

	// �A�N�Z�v�^
	tcp::acceptor Acceptor;

	// Socket
	shared_ptr<tcp::socket> pSocket;

	// Accept�ҋ@���H
	bool bWaitingAccept;


	// Accept�J�n.
	void StartAccept();

	// Accept����
	void OnAccept(const boost::system::error_code &ErrorCode);

};

#endif		// #ifndef __CLIENTACCEPTOR_H__
