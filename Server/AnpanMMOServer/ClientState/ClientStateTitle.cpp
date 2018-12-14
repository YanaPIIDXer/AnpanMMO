#include "stdafx.h"
#include "ClientStateTitle.h"
#include "Client.h"
#include "ClientStateAreaChange.h"
#include "ClientManager.h"
#include "CacheServer/CacheServerConnection.h"
#include "Config.h"
#include "Util.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Character/Player/PlayerCharacter.h"
#include "Packet/PacketLogInRequest.h"
#include "Packet/PacketLogInResult.h"
#include "Packet/PacketCreateCharacterRequest.h"
#include "Packet/PacketCreateCharacterResult.h"
#include "Packet/PacketSkillList.h"
#include "Packet/PacketSkillTreeData.h"
#include "Packet/PacketCharacterStatus.h"
#include "Packet/PacketScriptFlag.h"
#include "Packet/CachePacketLogInRequest.h"
#include "Packet/CachePacketLogInResult.h"
#include "Packet/CachePacketCreateCharacterRequest.h"
#include "Packet/CachePacketCreateCharacterResult.h"
#include "Packet/CachePacketCharacterDataRequest.h"
#include "Packet/CachePacketCharacterDataResult.h"
#include "Packet/CachePacketSkillListRequest.h"
#include "Packet/CachePacketSkillTreeRequest.h"
#include "Packet/CachePacketSkillTreeResponse.h"
#include "Packet/CachePacketSkillListResponse.h"
#include "Packet/CachePacketScriptFlagRequest.h"
#include "Packet/CachePacketScriptFlagResponse.h"

// コンストラクタ
ClientStateTitle::ClientStateTitle(Client *pInParent)
	: ClientStateBase(pInParent)
	, LastAreaId(0)
	, LastPosition(Vector3D::Zero)
{
	AddPacketFunction(LogInRequest, boost::bind(&ClientStateTitle::OnRecvLogInRequest, this, _2));
	AddPacketFunction(CreateCharacterRequest, boost::bind(&ClientStateTitle::OnRecvCreateCharacterRequest, this, _2));
	AddPacketFunction(CacheLogInResult, boost::bind(&ClientStateTitle::OnRecvCacheLogInResult, this, _2));
	AddPacketFunction(CacheCreateCharacterResult, boost::bind(&ClientStateTitle::OnRecvCacheCreateCharacterResult, this, _2));
	AddPacketFunction(CacheCharacterDataResult, boost::bind(&ClientStateTitle::OnRecvCacheCharacterDataResult, this, _2));
	AddPacketFunction(CacheSkillListResponse, boost::bind(&ClientStateTitle::OnRecvCacheSkillListResponse, this, _2));
	AddPacketFunction(CacheSkillTreeResponse, boost::bind(&ClientStateTitle::OnRecvCacheSkillTreeResponse, this, _2));
	AddPacketFunction(CacheScriptFlagResponse, boost::bind(&ClientStateTitle::OnRecvCacheScriptFlagResponse, this, _2));
}


// ログインリクエストを受信した。
void ClientStateTitle::OnRecvLogInRequest(MemoryStreamInterface *pStream)
{
	PacketLogInRequest Packet;
	Packet.Serialize(pStream);

	CachePacketLogInRequest CachePacket(GetParent()->GetUuid(), Packet.UserCode);
	CacheServerConnection::GetInstance()->SendPacket(&CachePacket);
}

// キャラクタ作成リクエストを受信した。
void ClientStateTitle::OnRecvCreateCharacterRequest(MemoryStreamInterface *pStream)
{
	PacketCreateCharacterRequest Packet;
	Packet.Serialize(pStream);

	if (Packet.CharacterName.size() == 0)
	{
		PacketCreateCharacterResult ResultPacket(PacketCreateCharacterResult::EmptyName);
		GetParent()->SendPacket(&ResultPacket);
		return;
	}

	if (Util::CalcStringLength(Packet.CharacterName) > Config::CharacterNameMaxLength)
	{
		PacketCreateCharacterResult ResultPacket(PacketCreateCharacterResult::TooLongName);
		GetParent()->SendPacket(&ResultPacket);
		return;
	}

	CachePacketCreateCharacterRequest CacheRequestPacket(GetParent()->GetUuid(), GetParent()->GetCustomerId(), Packet.CharacterName, Packet.Job);
	CacheServerConnection::GetInstance()->SendPacket(&CacheRequestPacket);
}

// キャッシュサーバからログイン結果を受信した。
void ClientStateTitle::OnRecvCacheLogInResult(MemoryStreamInterface *pStream)
{
	CachePacketLogInResult Packet;
	Packet.Serialize(pStream);

	PacketLogInResult::ResultCode ResultCode = PacketLogInResult::Success;
	switch (Packet.Result)
	{
		case CachePacketLogInResult::NoCharacter:

			ResultCode = PacketLogInResult::NoCharacter;
			break;

		case CachePacketLogInResult::Error:

			ResultCode = PacketLogInResult::Error;
			break;
	}

	if (Packet.Result == CachePacketLogInResult::Success)
	{
		// ダブルログインチェックはリザルトコードがSuccessだった場合のみ行う。
		// カスタマＩＤから取得できた場合、
		// そいつが自分自身以外だったらダブルログインと看做す。
		ClientPtr pDoubleCheck = ClientManager::GetInstance().GetFromCustomerId(Packet.CustomerId);
		if (!pDoubleCheck.expired() && pDoubleCheck.lock().get() != GetParent())
		{
			ResultCode = PacketLogInResult::DoubleLogIn;
		}
	}

	Client *pClient = GetParent();
	PacketLogInResult ResultPacket(ResultCode, pClient->GetUuid(), Packet.LastAreaId);
	pClient->SendPacket(&ResultPacket);

	if (ResultCode != PacketLogInResult::Success && ResultCode != PacketLogInResult::NoCharacter) { return; }

	// キャラクタが存在しなかった場合でもカスタマＩＤは登録しておく。
	pClient->SetCustomerId(Packet.CustomerId);

	if (ResultCode != PacketLogInResult::Success) { return; }

	CachePacketCharacterDataRequest CharaRequestPacket(pClient->GetUuid(), Packet.CustomerId);
	CacheServerConnection::GetInstance()->SendPacket(&CharaRequestPacket);
}

// キャッシュサーバからキャラクタ作成結果を受信した。
void ClientStateTitle::OnRecvCacheCreateCharacterResult(MemoryStreamInterface *pStream)
{
	CachePacketCreateCharacterResult Packet;
	Packet.Serialize(pStream);

	u8 ResultCode = PacketCreateCharacterResult::Success;
	if (Packet.Result == CachePacketCreateCharacterResult::Error)
	{
		ResultCode = PacketCreateCharacterResult::Error;
	}

	PacketCreateCharacterResult ResultPacket(ResultCode);
	GetParent()->SendPacket(&ResultPacket);
}

// キャッシュサーバからキャラクタデータを受信した。
void ClientStateTitle::OnRecvCacheCharacterDataResult(MemoryStreamInterface *pStream)
{
	CachePacketCharacterDataResult Packet;
	Packet.Serialize(pStream);

	if (Packet.Result != CachePacketCharacterDataResult::Success)
	{
		std::cout << "CharacterData Load Failed..." << std::endl;
		return;
	}

	Client *pClient = GetParent();
	pClient->CreateCharacter(Packet.CharacterId, Packet.Name, Packet.Job, Packet.Level, Packet.MaxHp, Packet.Atk, Packet.Def, Packet.Exp, Packet.Gold);
	PacketCharacterStatus StatusPacket(pClient->GetUuid(), Packet.Name, Packet.Job, Packet.Level, Packet.MaxHp, Packet.MaxHp, Packet.Atk, Packet.Def, Packet.Exp, Packet.Gold);
	pClient->SendPacket(&StatusPacket);

	LastAreaId = Packet.LastAreaId;
	LastPosition = Vector3D(Packet.LastX, Packet.LastY, Packet.LastZ);

	// スキルリストを要求.
	CachePacketSkillListRequest RequestPacket(pClient->GetUuid(), pClient->GetCharacter().lock()->GetCharacterId());
	CacheServerConnection::GetInstance()->SendPacket(&RequestPacket);
}

// キャッシュサーバからスキルリストを受信した。
void ClientStateTitle::OnRecvCacheSkillListResponse(MemoryStreamInterface *pStream)
{
	CachePacketSkillListResponse Packet;
	Packet.Serialize(pStream);

	if (Packet.Result != CachePacketSkillListResponse::Success)
	{
		std::cout << "SkillList Load Failed..." << std::endl;
		return;
	}

	PacketSkillList SkillListPacket(Packet.NormalAttackId, Packet.SkillId1, Packet.SkillId2, Packet.SkillId3, Packet.SkillId4);
	GetParent()->SendPacket(&SkillListPacket);

	// スキルツリー情報を要求.
	CachePacketSkillTreeRequest RequestPacket(GetParent()->GetUuid(), GetParent()->GetCharacter().lock()->GetCharacterId());
	CacheServerConnection::GetInstance()->SendPacket(&RequestPacket);
}

// キャッシュサーバからスキルツリー情報を取得した。
void ClientStateTitle::OnRecvCacheSkillTreeResponse(MemoryStreamInterface *pStream)
{
	CachePacketSkillTreeResponse Packet;
	Packet.Serialize(pStream);

	if (Packet.Result != CachePacketSkillTreeResponse::Success)
	{
		std::cout << "SkillTree Load Failed..." << std::endl;
		return;
	}

	GetParent()->GetCharacter().lock()->InitializeSkillTree(Packet.OpenedList);
	PacketSkillTreeData SkillTreePacket;
	GetParent()->GetCharacter().lock()->GetSkillTree().GenerateNodeDataList(SkillTreePacket.Nodes);
	GetParent()->SendPacket(&SkillTreePacket);
	
	// スクリプトフラグを要求.
	CachePacketScriptFlagRequest RequestPacket(GetParent()->GetUuid(), GetParent()->GetCharacter().lock()->GetCharacterId());
	CacheServerConnection::GetInstance()->SendPacket(&RequestPacket);
}

// キャッシュサーバからスクリプトフラグを受信した。
void ClientStateTitle::OnRecvCacheScriptFlagResponse(MemoryStreamInterface *pStream)
{
	CachePacketScriptFlagResponse Packet;
	Packet.Serialize(pStream);

	if (Packet.Result == CachePacketScriptFlagResponse::Success)
	{
		GetParent()->ConvertScriptFlagFromBitFields(Packet.BitField1, Packet.BitField2, Packet.BitField3);

		PacketScriptFlag FlagPacket(Packet.BitField1, Packet.BitField2, Packet.BitField3);
		GetParent()->SendPacket(&FlagPacket);
	}
	else
	{
		std::cout << "CachePacketScriptFlagResponse Error..." << std::endl;
	}

	ClientStateAreaChange *pNextState = new ClientStateAreaChange(GetParent(), LastAreaId, LastPosition);
	GetParent()->ChangeState(pNextState);
}
