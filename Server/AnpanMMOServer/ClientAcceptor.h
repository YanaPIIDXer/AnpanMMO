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

private:

	// IOService
	asio::io_service &IOService;

	// �A�N�Z�v�^
	tcp::acceptor Acceptor;

};

#endif		// #ifndef __CLIENTACCEPTOR_H__
