#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "MemoryBuffer.h"

class PacketBase;
class ClientStateBase;
class PlayerCharacter;

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
	void SetUuid(u32 InUuid) { Uuid = InUuid; }

	// UUID���擾.
	int GetUuid() const { return Uuid; }

	// �J�X�^�}�h�c���Z�b�g.
	void SetCustomerId(u32 InCustomerId) { CustomerId = InCustomerId; }

	// �J�X�^�}�h�c���擾.
	u32 GetCustomerId() const { return CustomerId; }

	// �L�����N�^�擾.
	weak_ptr<PlayerCharacter> GetCharacter() const { return pCharacter; }

	// �L�����N�^�쐬.
	void CreateCharacter(int MaxHp, int Atk, int Def, int Exp);

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
	shared_ptr<ClientStateBase> pState;

	// Uuid
	u32 Uuid;

	// �J�X�^�}�h�c
	u32 CustomerId;

	// �L�����N�^
	shared_ptr<PlayerCharacter> pCharacter;


	// ��M�J�n.
	void AsyncRecv(u8 *pBuffer, int Offset);

	// ��M�����B
	void OnRecv(const boost::system::error_code &ErrorCode, size_t Size);

	// ���M.
	void AsyncSend(const u8 *pBuffer, int Size);

	// ���M�����B
	void OnSend(const boost::system::error_code &ErrorCode, size_t Size, shared_ptr<asio::streambuf> SendBuffer);

};

#endif		// #ifndef __CLIENT_H__
