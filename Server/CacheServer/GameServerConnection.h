#ifndef __GAMESERVERCONNECTION_H__
#define __GAMESERVERCONNECTION_H__

#include "TCPConnection.h"
#include "PacketReceiver.h"

class PacketBase;

/**
 * �Q�[���T�[�o�ւ̐ڑ��N���X
 */
class GameServerConnection : public TCPConnection
{

public:

	// �R���X�g���N�^
	GameServerConnection(asio::io_service &IOService, const shared_ptr<tcp::socket> &pInSocket);

	// �f�X�g���N�^
	virtual ~GameServerConnection() {}

	// �p�P�b�g���M.
	void SendPacket(PacketBase *pPacket);

protected:

	// �f�[�^����M�����B
	virtual void OnRecvData(size_t Size);

private:

	// �A�N�Z�v�^
	tcp::acceptor Acceptor;

	// �p�P�b�g��M.
	PacketReceiver Receiver;


	// Accept����B
	void Accept();

	// Accept�����B
	void OnAccept(const boost::system::error_code &ErrorCode);

};

#endif		// #ifndef __GAMESERVERCONNECTION_H__
