#ifndef __GAMESERVERCONNECTION_H__
#define __GAMESERVERCONNECTION_H__

#include "TCPConnection.h"

/**
 * �Q�[���T�[�o�ւ̐ڑ��N���X
 */
class GameServerConnection : public TCPConnection
{

public:

	// �R���X�g���N�^
	GameServerConnection(const shared_ptr<tcp::socket> &pInSocket);

	// �f�X�g���N�^
	virtual ~GameServerConnection() {}

protected:

private:

};

#endif		// #ifndef __GAMESERVERCONNECTION_H__
