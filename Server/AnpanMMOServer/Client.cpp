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
	, QuestMgr(this)
{
	bIsConnected = true;
	Script.SetScriptDir("../../Script/Scripts");
	Script.SetClient(this);
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
void Client::CreateCharacter(u32 CharacterId, const std::string &Name, u8 Job, u32 Level, int MaxHp, int Atk, int Def, int Exp, u32 Gold)
{
	PlayerCharacter *pChara= new PlayerCharacter(this, CharacterId, Job, Level, MaxHp, Atk, Def, Exp, Gold);
	pChara->SetUuid(Uuid);
	pChara->SetName(Name);
	pCharacter = shared_ptr<PlayerCharacter>(pChara);
}

// �p�P�b�g����M.
void Client::RecvPacket(u8 ID, MemoryStreamInterface *pStream)
{
	pStream->Reset();
	pState->AnalyzePacket(ID, pStream);
}

// �X�N���v�g�t���O��ݒ�.
void Client::SetScriptFlag(int Key)
{
	FlagManager.Set(Key);
}

// �r�b�g�t�B�[���h����X�N���v�g�t���O�ɕϊ�.
void Client::ConvertScriptFlagFromBitFields(u32 BitField1, u32 BitField2, u32 BitField3)
{
	FlagManager.FromBitField(BitField1, BitField2, BitField3);
}

// �N�G�X�g�f�[�^�ǉ�.
void Client::AddQuestData(const QuestData &Data)
{
	QuestMgr.Add(Data);
}

// �N�G�X�g�i�s.
void Client::ProgressQuest(u32 QuestId)
{
	QuestMgr.ProgressStage(QuestId);
}

// �A���p�����E�Q�����B
void Client::OnKilledAnpan(u32 AreaId)
{
	QuestMgr.OnKilledAnpan(AreaId);
}

// �N�G�X�g�j��.
u8 Client::RetireQuest(u32 QuestId)
{
	return QuestMgr.Retire(QuestId);
}


// �f�[�^����M�����B
void Client::OnRecvData(size_t Size)
{
	u8 *pRecvData = RecvBuffer.GetTop();
	while (true)
	{
		MemoryStreamReader ReadStream(pRecvData, Size);
		PacketHeader Header;
		if (!Header.Serialize(&ReadStream) || RecvBuffer.GetSize() < Header.GetPacketSize() + 3) { break; }

		RecvBuffer.Pop(3);

		MemoryStreamReader BodyStream(RecvBuffer.GetTop(), Header.GetPacketSize());
		pState->AnalyzePacket(Header.GetPacketId(), &BodyStream);

		RecvBuffer.Pop(Header.GetPacketSize());
	}
}
