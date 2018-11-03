#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "MemoryBuffer.h"

class PacketBase;
class ClientStateBase;

/**
 * �N���C�A���g�N���X
 */
class Client
{

public:

	// �R���X�g���N�^
	Client(const shared_ptr<tcp::socket> &pInSocket);

	// �f�X�g���N�^
	~Client();

	// �ڑ�����Ă��邩�H
	bool IsConnected() const { return bIsConnected; }

	// �p�P�b�g���M.
	void SendPacket(PacketBase *pPacket);

	// �X�e�[�g�؂�ւ�
	void ChangeState(ClientStateBase *pNextState);

	// UUID���Z�b�g
	void SetUuid(int InUuid) { Uuid = InUuid; }

	// UUID���擾.
	int GetUuid() const { return Uuid; }

private:

	enum
	{
		RecvDataSize = 1024,
	};

	// Socket
	shared_ptr<tcp::socket> pSocket;

	// �ڑ�����Ă��邩�H
	bool bIsConnected;

	// ��M�o�b�t�@.
	MemoryBuffer RecvBuffer;

	// ��M�f�[�^
	array<u8, RecvDataSize> RecvData;

	// State
	ClientStateBase *pState;

	// Uuid
	int Uuid;


	// ��M�J�n.
	void AsyncRecv(u8 *pBuffer, int Offset);

	// ��M�����B
	void OnRecv(const system::error_code &ErrorCode, size_t Size);

	// ���M.
	void AsyncSend(const u8 *pBuffer, int Size);

	// ���M�����B
	void OnSend(const system::error_code &ErrorCode, size_t Size);

};

#endif		// #ifndef __CLIENT_H__
