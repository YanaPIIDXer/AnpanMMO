#ifndef __CLIENT_H__
#define __CLIENT_H__

/**
 * �N���C�A���g�N���X
 */
class Client
{

public:

	// �R���X�g���N�^
	Client(const shared_ptr<tcp::socket> &pInSocket);

	// �f�X�g���N�^
	~Client() {}

private:

	// Socket
	shared_ptr<tcp::socket> pSocket;

};

#endif		// #ifndef __CLIENT_H__
