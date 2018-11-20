#include "stdafx.h"
#include "PacketReceiver.h"
#include "GameServerConnection.h"
#include "DBConnection.h"
#include "Packet/CachePacketLogInRequest.h"
#include "Packet/CachePacketLogInResult.h"
#include "Packet/CachePacketCharacterDataRequest.h"
#include "Packet/CachePacketCharacterDataResult.h"
#include "Packet/CachePacketCharacterDataSave.h"

// コンストラクタ
PacketReceiver::PacketReceiver(GameServerConnection *pInParent)
	: pParent(pInParent)
{
	AddPacketFunc(CacheLogInRequest, bind(&PacketReceiver::OnRecvLogInRequest, this, _1));
	AddPacketFunc(CacheCharacterDataRequest, bind(&PacketReceiver::OnRecvCharacterDataRequest, this, _1));
	AddPacketFunc(CacheCharacterDataSave, bind(&PacketReceiver::OnRecvCharacterDataSave, this, _1));
}

// ログインリクエストを受信した。
void PacketReceiver::OnRecvLogInRequest(MemoryStreamInterface *pStream)
{
	CachePacketLogInRequest Packet;
	Packet.Serialize(pStream);

	u8 ResultCode = CachePacketLogInResult::Success;
	char *pUserCode = const_cast<char *>(Packet.UserCode.c_str());
	int Id = 0;
	if (!DBConnection::GetInstance().LoadUserData(pUserCode, Id))
	{
		ResultCode = CachePacketLogInResult::Error;
	}

	// キャラデータを一旦読み込む。
	// （ここで読み込んだデータそのものは使用しないが、キャラが存在しなければ勝手に生成するため）
	s32 MaxHp = 0;
	s32 Atk = 0;
	s32 Def = 0;
	s32 Exp = 0;
	if (!DBConnection::GetInstance().LoadCharacterParameter(Id, MaxHp, Atk, Def, Exp, true))
	{
		ResultCode = CachePacketLogInResult::Error;
	}

	u32 LastAreaId = 0;
	float LastX = 0.0f;
	float LastY = 0.0f;
	float LastZ = 0.0f;
	if (!DBConnection::GetInstance().ReadLastLogoutPosition(Id, LastAreaId, LastX, LastY, LastZ))
	{
		ResultCode = CachePacketLogInResult::Error;
	}

	CachePacketLogInResult ResultPacket(Packet.ClientId, ResultCode, Id, LastAreaId);
	pParent->SendPacket(&ResultPacket);
}

// キャラクタ情報リクエストを受信した。
void PacketReceiver::OnRecvCharacterDataRequest(MemoryStreamInterface *pStream)
{
	CachePacketCharacterDataRequest Packet;
	Packet.Serialize(pStream);

	s32 MaxHp = 0;
	s32 Atk = 0;
	s32 Def = 0;
	s32 Exp = 0;
	CachePacketCharacterDataResult::ResultCode ResultCode = CachePacketCharacterDataResult::Success;
	if (!DBConnection::GetInstance().LoadCharacterParameter(Packet.CustomerId, MaxHp, Atk, Def, Exp, true))
	{
		ResultCode = CachePacketCharacterDataResult::Error;
	}

	u32 LastAreaId = 0;
	float LastX = 0.0f;
	float LastY = 0.0f;
	float LastZ = 0.0f;
	if (!DBConnection::GetInstance().ReadLastLogoutPosition(Packet.CustomerId, LastAreaId, LastX, LastY, LastZ))
	{
		ResultCode = CachePacketCharacterDataResult::Error;
	}

	CachePacketCharacterDataResult ResultPacket(Packet.ClientId, ResultCode, MaxHp, Atk, Def, Exp, LastAreaId, LastX, LastY, LastZ);
	pParent->SendPacket(&ResultPacket);
}

// キャラクタ保存リクエストを受信した。
void PacketReceiver::OnRecvCharacterDataSave(MemoryStreamInterface *pStream)
{
	CachePacketCharacterDataSave Packet;
	Packet.Serialize(pStream);

	if (!DBConnection::GetInstance().SaveCharacterParameter(Packet.CustomerId, Packet.MaxHp, Packet.Atk, Packet.Def, Packet.Exp, Packet.LastAreaId, Packet.LastX, Packet.LastY, Packet.LastZ))
	{
		std::cout << "Character Data Save Failed..." << std::endl;
	}
}


// パケット受信.
void PacketReceiver::RecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{
	if (PacketFuncs.find(ID) == PacketFuncs.end()) { return; }
	PacketFuncs[ID](pStream);
}


// パケット受信関数を追加.
void PacketReceiver::AddPacketFunc(PacketID ID, const PacketFunc &Func)
{
	PacketFuncs[ID] = Func;
}
