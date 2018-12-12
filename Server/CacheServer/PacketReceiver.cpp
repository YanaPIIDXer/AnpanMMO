#include "stdafx.h"
#include "PacketReceiver.h"
#include "GameServerConnection.h"
#include "DBConnection.h"
#include "Packet/CachePacketLogInRequest.h"
#include "Packet/CachePacketLogInResult.h"
#include "Packet/CachePacketCreateCharacterRequest.h"
#include "Packet/CachePacketCreateCharacterResult.h"
#include "Packet/CachePacketCharacterDataRequest.h"
#include "Packet/CachePacketCharacterDataResult.h"
#include "Packet/CachePacketCharacterDataSave.h"
#include "Packet/CachePacketScriptFlagRequest.h"
#include "Packet/CachePacketScriptFlagResponse.h"
#include "Packet/CachePacketScriptFlagSaveRequest.h"
#include "Packet/CachePacketGoldSave.h"

// コンストラクタ
PacketReceiver::PacketReceiver(GameServerConnection *pInParent)
	: pParent(pInParent)
{
	AddPacketFunc(CacheLogInRequest, bind(&PacketReceiver::OnRecvLogInRequest, this, _1));
	AddPacketFunc(CacheCreateCharacterRequest, bind(&PacketReceiver::OnRecvCreateCharacterRequest, this, _1));
	AddPacketFunc(CacheCharacterDataRequest, bind(&PacketReceiver::OnRecvCharacterDataRequest, this, _1));
	AddPacketFunc(CacheCharacterDataSave, bind(&PacketReceiver::OnRecvCharacterDataSaveRequest, this, _1));
	AddPacketFunc(CacheScriptFlagRequest, bind(&PacketReceiver::OnRecvLoadScriptFlagRequest, this, _1));
	AddPacketFunc(CacheScriptFlagSaveRequest, bind(&PacketReceiver::OnRecvSaveScriptFlagRequest, this, _1));
	AddPacketFunc(CacheGoldSave, bind(&PacketReceiver::OnRecvSaveGold, this, _1));
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

	bool bCharaExist = false;
	if (!DBConnection::GetInstance().IsExistCharacter(Id, bCharaExist))
	{
		ResultCode = CachePacketLogInResult::Error;
	}

	if (ResultCode == CachePacketLogInResult::Success && !bCharaExist)
	{
		ResultCode = CachePacketLogInResult::NoCharacter;
	}

	u32 LastAreaId = 0;
	if (ResultCode == CachePacketLogInResult::Success)
	{
		float LastX = 0.0f;
		float LastY = 0.0f;
		float LastZ = 0.0f;
		if (!DBConnection::GetInstance().ReadLastLogoutPosition(Id, LastAreaId, LastX, LastY, LastZ))
		{
			ResultCode = CachePacketLogInResult::Error;
		}
	}
	CachePacketLogInResult ResultPacket(Packet.ClientId, ResultCode, Id, LastAreaId);
	pParent->SendPacket(&ResultPacket);
}

// キャラクタ作成リクエストを受信した。
void PacketReceiver::OnRecvCreateCharacterRequest(MemoryStreamInterface *pStream)
{
	CachePacketCreateCharacterRequest Packet;
	Packet.Serialize(pStream);

	u8 ResultCode = CachePacketCreateCharacterResult::Success;
	char *pCharaName = const_cast<char *>(Packet.CharacterName.c_str());
	if (!DBConnection::GetInstance().RegisterCharacterData(Packet.CustomerId, pCharaName, Packet.Job))
	{
		ResultCode = CachePacketCreateCharacterResult::Error;
	}

	CachePacketCreateCharacterResult ResultPacket(Packet.ClientId, ResultCode);
	pParent->SendPacket(&ResultPacket);
}

// キャラクタ情報リクエストを受信した。
void PacketReceiver::OnRecvCharacterDataRequest(MemoryStreamInterface *pStream)
{
	CachePacketCharacterDataRequest Packet;
	Packet.Serialize(pStream);

	std::string Name;
	u8 Job = 0;
	u32 Level = 0;
	s32 MaxHp = 0;
	s32 Atk = 0;
	s32 Def = 0;
	s32 Exp = 0;
	u32 Gold = 0;
	CachePacketCharacterDataResult::ResultCode ResultCode = CachePacketCharacterDataResult::Success;
	if (!DBConnection::GetInstance().LoadCharacterParameter(Packet.CustomerId, Name, Job, Level, MaxHp, Atk, Def, Exp, Gold))
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

	CachePacketCharacterDataResult ResultPacket(Packet.ClientId, ResultCode, Name, Job, Level, MaxHp, Atk, Def, Exp, Gold, LastAreaId, LastX, LastY, LastZ);
	pParent->SendPacket(&ResultPacket);
}

// キャラクタ保存リクエストを受信した。
void PacketReceiver::OnRecvCharacterDataSaveRequest(MemoryStreamInterface *pStream)
{
	CachePacketCharacterDataSave Packet;
	Packet.Serialize(pStream);

	if (!DBConnection::GetInstance().SaveCharacterParameter(Packet.CustomerId, Packet.Level, Packet.MaxHp, Packet.Atk, Packet.Def, Packet.Exp, Packet.LastAreaId, Packet.LastX, Packet.LastY, Packet.LastZ))
	{
		std::cout << "Character Data Save Failed..." << std::endl;
	}
}

// スクリプトフラグ読み込みリクエストを受信した。
void PacketReceiver::OnRecvLoadScriptFlagRequest(MemoryStreamInterface *pStream)
{
	CachePacketScriptFlagRequest Packet;
	Packet.Serialize(pStream);

	u32 BitField1, BitField2, BitField3;
	u8 Result = CachePacketScriptFlagResponse::Success;
	if (!DBConnection::GetInstance().LoadScriptFlags(Packet.CustomerId, BitField1, BitField2, BitField3))
	{
		Result = CachePacketScriptFlagResponse::Error;
	}

	CachePacketScriptFlagResponse ResponsePacket(Packet.ClientId, Result, BitField1, BitField2, BitField3);
	pParent->SendPacket(&ResponsePacket);
}

// スクリプトフラグ保存リクエストを受信した。
void PacketReceiver::OnRecvSaveScriptFlagRequest(MemoryStreamInterface *pStream)
{
	CachePacketScriptFlagSaveRequest Packet;
	Packet.Serialize(pStream);

	DBConnection::GetInstance().SaveScriptFlags(Packet.CustomerId, Packet.BitField1, Packet.BitField2, Packet.BitField3);
}

// ゴールド保存リクエストを受信した。
void PacketReceiver::OnRecvSaveGold(MemoryStreamInterface *pStream)
{
	CachePacketGoldSave Packet;
	Packet.Serialize(pStream);

	DBConnection::GetInstance().SaveGold(Packet.CustomerId, Packet.Gold);
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
