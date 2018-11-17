#ifndef __TCPCONNECTION_H__
#define __TCPCONNECTION_H__

#include "MemoryBuffer.h"

/**
 * TCP�ڑ��N���X
 */
class TCPConnection
{

public:

	// �R���X�g���N�^
	TCPConnection(const shared_ptr<tcp::socket> &pInSocket);

	// �f�X�g���N�^
	virtual ~TCPConnection() = 0;

	// �ڑ�����Ă��邩�H
	bool IsConnected() const { return bIsConnected; }

protected:

	// ��M�o�b�t�@.
	MemoryBuffer RecvBuffer;

	// ��M�J�n.
	void AsyncRecv();

	// �f�[�^����M�����B
	virtual void OnRecvData(size_t Size) {}

	// ���M.
	void AsyncSend(const u8 *pBuffer, int Size);

private:

	enum
	{
		RecvDataSize = 1024,
	};

	// Socket
	shared_ptr<tcp::socket> pSocket;

	// �ڑ�����Ă��邩�H
	bool bIsConnected;

	// ��M�f�[�^
	array<u8, RecvDataSize> RecvData;

	// ���M�����B
	void OnSend(const boost::system::error_code &ErrorCode, size_t Size, shared_ptr<asio::streambuf> SendBuffer);

	// ��M�����B
	void OnRecv(const boost::system::error_code &ErrorCode, size_t Size);

};

#endif		// #ifndef __TCPCONNECTION_H__
