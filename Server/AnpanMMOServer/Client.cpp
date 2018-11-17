#include "stdafx.h"
#include "Client.h"
#include "Packet/PacketBase.h"
#include "MemoryStream/MemorySizeCaliculateStream.h"
#include "MemoryStream/MemoryStreamWriter.h"
#include "MemoryStream/MemoryStreamReader.h"
#include "Packet/PacketHeader.h"
#include "ClientState/ClientStateBase.h"
#include "ClientState/ClientStateTitle.h"
#include "Character/Player/PlayerCharacter.h"

// �R���X�g���N�^
Client::Client(const shared_ptr<tcp::socket> &pInSocket)
	: TCPConnection(pInSocket)
	, pState(new ClientStateTitle(this))
	, Uuid(0)
	, CustomerId(0)
{
	bIsConnected = true;
	AsyncRecv();
}

// �f�X�g���N�^
Client::~Client()
{
}

// �p�P�b�g���M.
void Client::SendPacket(PacketBase *pPacket)
{
	//�܂��̓T�C�Y�����߂�
	MemorySizeCaliculateStream SizeStream;
	pPacket->Serialize(&SizeStream);

	//�V���A���C�Y�{��
	MemoryStreamWriter WriteStream(SizeStream.GetSize() + 3);

	u8 Id = (u8)pPacket->GetPacketID();
	u16 Size = SizeStream.GetSize();
	WriteStream.Serialize(&Id);
	WriteStream.Serialize(&Size);
	pPacket->Serialize(&WriteStream);

	//���M
	AsyncSend(WriteStream.GetStream(), WriteStream.GetSize());
}

// �X�e�[�g�؂�ւ�
void Client::ChangeState(ClientStateBase *pNextState)
{
	pState = shared_ptr<ClientStateBase>(pNextState);
	pState->BeginState();
}

// �L�����N�^�쐬.
void Client::CreateCharacter(int MaxHp, int Atk, int Def, int Exp)
{
	PlayerCharacter *pChara= new PlayerCharacter(this, MaxHp, Atk, Def, Exp);
	pChara->SetUuid(Uuid);
	pCharacter = shared_ptr<PlayerCharacter>(pChara);
}


// �f�[�^����M�����B
void Client::OnRecvData(size_t Size)
{
	u8 *pRecvData = RecvBuffer.GetTop();
	MemoryStreamReader ReadStream(pRecvData, Size);
	PacketHeader Header;
	if (Header.Serialize(&ReadStream) && RecvBuffer.GetSize() >= Header.GetPacketSize() + 3)
	{
		RecvBuffer.Pop(3);

		MemoryStreamReader BodyStream(RecvBuffer.GetTop(), Header.GetPacketSize());
		pState->AnalyzePacket(Header.GetPacketId(), &BodyStream);

		RecvBuffer.Pop(Header.GetPacketSize());
	}
}
