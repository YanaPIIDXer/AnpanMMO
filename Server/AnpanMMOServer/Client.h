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

	// �ڑ�����Ă��邩�H
	bool IsConnected() const { return bIsConnected; }

private:

	// Socket
	shared_ptr<tcp::socket> pSocket;

	// �ڑ�����Ă��邩�H
	bool bIsConnected;

	// ��M�o�b�t�@.
	array<u8, 1024> RecvBuffer;

	// ���M�o�b�t�@
	array<u8, 1024> SendBuffer;


	// ��M�J�n.
	void AsyncRecv(u8 *pBuffer, int Offset);

	// ��M�����B
	void OnRecv(const system::error_code &ErrorCode, size_t Size);

	// ���M.
	void AsyncSend(u8 *pBuffer, int Size);

	// ���M�����B
	void OnSend(const system::error_code &ErrorCode, size_t Size);

};

#endif		// #ifndef __CLIENT_H__
