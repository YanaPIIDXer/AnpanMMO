#include "stdafx.h"
#include "ClientAcceptor.h"

// �R���X�g���N�^
ClientAcceptor::ClientAcceptor(asio::io_service &InIOService, int Port)
	: IOService(InIOService)
	, Acceptor(InIOService, tcp::endpoint(tcp::v4(), Port))
{
}

// �������.
void ClientAcceptor::Poll()
{

}
