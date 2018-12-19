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
#include "Packet/CachePacketSkillListRequest.h"
#include "Packet/CachePacketSkillListResponse.h"
#include "Packet/CachePacketSaveSkillListRequest.h"
#include "Packet/CachePacketSaveSkillListResponse.h"
#include "Packet/CachePacketSkillTreeRequest.h"
#include "Packet/CachePacketSkillTreeResponse.h"
#include "Packet/CachePacketOpenSkillTree.h"
#include "Packet/CachePacketItemListRequest.h"
#include "Packet/CachePacketItemListResponse.h"
#include "Packet/CachePacketItemCountChangeRequest.h"
#include "Packet/CachePacketItemShortcutRequest.h"
#include "Packet/CachePacketItemShortcutResponse.h"
#include "Packet/CachePacketSaveItemShortcutRequest.h"
#include "Packet/CachePacketSaveItemShortcutResponse.h"
#include "Packet/CachePacketQuestDataRequest.h"
#include "Packet/CachePacketQuestDataResponse.h"
#include "Packet/CachePacketSaveQuestDataRequest.h"
#include "Packet/CachePacketQuestRetireRequest.h"
#include "Packet/CachePacketSaveActiveQuestRequest.h"

// コンストラクタ
PacketReceiver::PacketReceiver(GameServerConnection *pInParent)
	: pParent(pInParent)
{
	AddPacketFunc(PacketID::CacheLogInRequest, bind(&PacketReceiver::OnRecvLogInRequest, this, _1));
	AddPacketFunc(PacketID::CacheCreateCharacterRequest, bind(&PacketReceiver::OnRecvCreateCharacterRequest, this, _1));
	AddPacketFunc(PacketID::CacheCharacterDataRequest, bind(&PacketReceiver::OnRecvCharacterDataRequest, this, _1));
	AddPacketFunc(PacketID::CacheCharacterDataSave, bind(&PacketReceiver::OnRecvCharacterDataSaveRequest, this, _1));
	AddPacketFunc(PacketID::CacheSkillListRequest, bind(&PacketReceiver::OnRecvSkillListRequest, this, _1));
	AddPacketFunc(PacketID::CacheSaveSkillListRequest, bind(&PacketReceiver::OnRecvSaveSkillListRequest, this, _1));
	AddPacketFunc(PacketID::CacheSkillTreeRequest, bind(&PacketReceiver::OnRecvSkillTreeRequest, this, _1));
	AddPacketFunc(PacketID::CacheOpenSkillTree, bind(&PacketReceiver::OnRecvSkillTreeSaveRequest, this, _1));
	AddPacketFunc(PacketID::CacheScriptFlagRequest, bind(&PacketReceiver::OnRecvLoadScriptFlagRequest, this, _1));
	AddPacketFunc(PacketID::CacheScriptFlagSaveRequest, bind(&PacketReceiver::OnRecvSaveScriptFlagRequest, this, _1));
	AddPacketFunc(PacketID::CacheItemListRequest, bind(&PacketReceiver::OnRecvItemListRequest, this, _1));
	AddPacketFunc(PacketID::CacheItemCountChangeRequest, bind(&PacketReceiver::OnRecvItemCountChange, this, _1));
	AddPacketFunc(PacketID::CacheItemShortcutRequest, bind(&PacketReceiver::OnRecvItemShortcutRequest, this, _1));
	AddPacketFunc(PacketID::CacheSaveItemShortcutRequest, bind(&PacketReceiver::OnRecvSaveItemShortcutRequest, this, _1));
	AddPacketFunc(PacketID::CacheGoldSave, bind(&PacketReceiver::OnRecvSaveGold, this, _1));
	AddPacketFunc(PacketID::CacheQuestDataRequest, bind(&PacketReceiver::OnRecvQuestDataRequest, this, _1));
	AddPacketFunc(PacketID::CacheSaveQuestDataRequest, bind(&PacketReceiver::OnRecvSaveQuestDataRequest, this, _1));
	AddPacketFunc(PacketID::CacheQuestRetireRequest, bind(&PacketReceiver::OnRecvRetireQuestDataRequest, this, _1));
	AddPacketFunc(PacketID::CacheSaveActiveQuestRequest, bind(&PacketReceiver::OnRecvSaveActiveQuestRequest, this, _1));
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
		u32 CharacterId = 0;
		if (DBConnection::GetInstance().GetCharacterId(Id, CharacterId))
		{
			float LastX = 0.0f;
			float LastY = 0.0f;
			float LastZ = 0.0f;
			if (!DBConnection::GetInstance().ReadLastLogoutPosition(CharacterId, LastAreaId, LastX, LastY, LastZ))
			{
				ResultCode = CachePacketLogInResult::Error;
			}
		}
		else
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
	u32 CharacterId;
	u8 Job = 0;
	u32 Level = 0;
	s32 MaxHp = 0;
	s32 Atk = 0;
	s32 Def = 0;
	s32 Exp = 0;
	u32 Gold = 0;
	CachePacketCharacterDataResult::ResultCode ResultCode = CachePacketCharacterDataResult::Success;
	if (!DBConnection::GetInstance().LoadCharacterParameter(Packet.CustomerId, CharacterId, Name, Job, Level, MaxHp, Atk, Def, Exp, Gold))
	{
		ResultCode = CachePacketCharacterDataResult::Error;
	}

	u32 LastAreaId = 0;
	float LastX = 0.0f;
	float LastY = 0.0f;
	float LastZ = 0.0f;
	if (!DBConnection::GetInstance().ReadLastLogoutPosition(CharacterId, LastAreaId, LastX, LastY, LastZ))
	{
		ResultCode = CachePacketCharacterDataResult::Error;
	}

	CachePacketCharacterDataResult ResultPacket(Packet.ClientId, CharacterId,ResultCode, Name, Job, Level, MaxHp, Atk, Def, Exp, Gold, LastAreaId, LastX, LastY, LastZ);
	pParent->SendPacket(&ResultPacket);
}

// キャラクタ保存リクエストを受信した。
void PacketReceiver::OnRecvCharacterDataSaveRequest(MemoryStreamInterface *pStream)
{
	CachePacketCharacterDataSave Packet;
	Packet.Serialize(pStream);

	if (!DBConnection::GetInstance().SaveCharacterParameter(Packet.CharacterId, Packet.Level, Packet.MaxHp, Packet.Atk, Packet.Def, Packet.Exp, Packet.LastAreaId, Packet.LastX, Packet.LastY, Packet.LastZ))
	{
		std::cout << "Character Data Save Failed..." << std::endl;
	}
}

// スキルリスト要求を受信した。
void PacketReceiver::OnRecvSkillListRequest(MemoryStreamInterface *pStream)
{
	CachePacketSkillListRequest Packet;
	Packet.Serialize(pStream);

	u8 Result = CachePacketSkillListResponse::Success;
	u32 NormalAttackId = 0;
	u32 Skill1 = 0;
	u32 Skill2 = 0;
	u32 Skill3 = 0;
	u32 Skill4 = 0;
	if (!DBConnection::GetInstance().LoadSkillList(Packet.CharacterId, NormalAttackId, Skill1, Skill2, Skill3, Skill4))
	{
		Result = CachePacketSkillListResponse::Error;
	}

	CachePacketSkillListResponse ResponsePacket(Packet.ClientId, Result, NormalAttackId, Skill1, Skill2, Skill3, Skill4);
	pParent->SendPacket(&ResponsePacket);
}

// スキルリスト保存要求を受信した。
void PacketReceiver::OnRecvSaveSkillListRequest(MemoryStreamInterface *pStream)
{
	CachePacketSaveSkillListRequest Packet;
	Packet.Serialize(pStream);

	u8 Result = CachePacketSaveSkillListResponse::Success;
	if (!DBConnection::GetInstance().SaveSkillList(Packet.CharacterId, Packet.SkillId1, Packet.SkillId2, Packet.SkillId3, Packet.SkillId4))
	{
		Result = CachePacketSaveSkillListResponse::Error;
	}

	CachePacketSaveSkillListResponse ResponsePacket(Packet.ClientId, Result, Packet.SkillId1, Packet.SkillId2, Packet.SkillId3, Packet.SkillId4);
	pParent->SendPacket(&ResponsePacket);
}

// スキルツリーリクエストを受信した。
void PacketReceiver::OnRecvSkillTreeRequest(MemoryStreamInterface *pStream)
{
	CachePacketSkillTreeRequest Packet;
	Packet.Serialize(pStream);

	u8 Result = CachePacketSkillTreeResponse::Success;
	CachePacketSkillTreeResponse ResponsePacket;
	if (!DBConnection::GetInstance().LoadSkillTree(Packet.CharacterId, ResponsePacket.OpenedList))
	{
		Result = CachePacketSkillTreeResponse::Error;
	}

	ResponsePacket.ClientId = Packet.ClientId;
	ResponsePacket.Result = Result;
	pParent->SendPacket(&ResponsePacket);
}

// スキルツリー保存要求を受信した。
void PacketReceiver::OnRecvSkillTreeSaveRequest(MemoryStreamInterface *pStream)
{
	CachePacketOpenSkillTree Packet;
	Packet.Serialize(pStream);

	if (!DBConnection::GetInstance().SaveSkillTree(Packet.CharacterId, Packet.NodeId))
	{
		std::cout << "SkillTree Save Failed..." << std::endl;
	}
}

// スクリプトフラグ読み込みリクエストを受信した。
void PacketReceiver::OnRecvLoadScriptFlagRequest(MemoryStreamInterface *pStream)
{
	CachePacketScriptFlagRequest Packet;
	Packet.Serialize(pStream);

	u32 BitField1, BitField2, BitField3;
	u8 Result = CachePacketScriptFlagResponse::Success;
	if (!DBConnection::GetInstance().LoadScriptFlags(Packet.CharacterId, BitField1, BitField2, BitField3))
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

	DBConnection::GetInstance().SaveScriptFlags(Packet.CharacterId, Packet.BitField1, Packet.BitField2, Packet.BitField3);
}

// アイテムリストリクエストを受信した。
void PacketReceiver::OnRecvItemListRequest(MemoryStreamInterface *pStream)
{
	CachePacketItemListRequest Packet;
	Packet.Serialize(pStream);

	CachePacketItemListResponse ResponsePacket;
	ResponsePacket.ClientId = Packet.ClientId;
	ResponsePacket.Result = CachePacketItemListResponse::Success;
	if (!DBConnection::GetInstance().LoadItemList(Packet.CharacterId, ResponsePacket.Items))
	{
		ResponsePacket.Result = CachePacketItemListResponse::Error;
	}

	pParent->SendPacket(&ResponsePacket);
}

// アイテム数変動を受信した。
void PacketReceiver::OnRecvItemCountChange(MemoryStreamInterface *pStream)
{
	CachePacketItemCountChangeRequest Packet;
	Packet.Serialize(pStream);

	if (!DBConnection::GetInstance().ChangeItemCount(Packet.CharacterId, Packet.ItemId, Packet.Count))
	{
		std::cout << "Item Count Change Failed..." << std::endl;
	}
}

// アイテムショートカット読み込みリクエストを受信した。
void PacketReceiver::OnRecvItemShortcutRequest(MemoryStreamInterface *pStream)
{
	CachePacketItemShortcutRequest Packet;
	Packet.Serialize(pStream);

	u8 Result = CachePacketItemShortcutResponse::Success;
	u32 ItemId1 = 0, ItemId2 = 0;
	if (!DBConnection::GetInstance().LoadItemShortcut(Packet.CharacterId, ItemId1, ItemId2))
	{
		Result = CachePacketItemShortcutResponse::Error;
	}

	CachePacketItemShortcutResponse ResponsePacket(Packet.ClientId, Result, ItemId1, ItemId2);
	pParent->SendPacket(&ResponsePacket);
}

// アイテムショートカット書き込みリクエストを受信した。
void PacketReceiver::OnRecvSaveItemShortcutRequest(MemoryStreamInterface *pStream)
{
	CachePacketSaveItemShortcutRequest Packet;
	Packet.Serialize(pStream);

	u8 Result = CachePacketSaveItemShortcutResponse::Success;
	if (!DBConnection::GetInstance().SaveItemShortcut(Packet.CharacterId, Packet.ItemId1, Packet.ItemId2))
	{
		Result = CachePacketSaveItemShortcutResponse::Error;
	}

	CachePacketSaveItemShortcutResponse ResponsePacket(Packet.ClientId, Result, Packet.ItemId1, Packet.ItemId2);
	pParent->SendPacket(&ResponsePacket);
}

// ゴールド保存リクエストを受信した。
void PacketReceiver::OnRecvSaveGold(MemoryStreamInterface *pStream)
{
	CachePacketGoldSave Packet;
	Packet.Serialize(pStream);

	DBConnection::GetInstance().SaveGold(Packet.CharacterId, Packet.Gold);
}

// クエストデータリクエストを受信した。
void PacketReceiver::OnRecvQuestDataRequest(MemoryStreamInterface *pStream)
{
	CachePacketQuestDataRequest Packet;
	Packet.Serialize(pStream);

	CachePacketQuestDataResponse ResponsePacket;
	ResponsePacket.ClientId = Packet.ClientId;
	ResponsePacket.Result = CachePacketQuestDataResponse::Success;
	if (!DBConnection::GetInstance().LoadQuestData(Packet.CharacterId, ResponsePacket.Quests, ResponsePacket.ActiveQuestId))
	{
		ResponsePacket.Result = CachePacketQuestDataResponse::Error;
	}

	pParent->SendPacket(&ResponsePacket);
}

// クエストデータ保存リクエストを受信した。
void PacketReceiver::OnRecvSaveQuestDataRequest(MemoryStreamInterface *pStream)
{
	CachePacketSaveQuestDataRequest Packet;
	Packet.Serialize(pStream);

	if (!DBConnection::GetInstance().SaveQuestData(Packet.CharacterId, Packet.Data.QuestId, Packet.Data.StageNo, Packet.Data.KillCount, Packet.Data.State))
	{
		std::cout << "QuestData Save Failed..." << std::endl;
	}
}

// クエスト破棄リクエストを受信した。
void PacketReceiver::OnRecvRetireQuestDataRequest(MemoryStreamInterface *pStream)
{
	CachePacketQuestRetireRequest Packet;
	Packet.Serialize(pStream);

	if (!DBConnection::GetInstance().EraseQuestData(Packet.CharacterId, Packet.QuestId))
	{
		std::cout << "Erase QuestData Failed..." << std::endl;
	}
}

// アクティブクエスト保存リクエストを受信した。
void PacketReceiver::OnRecvSaveActiveQuestRequest(MemoryStreamInterface *pStream)
{
	CachePacketSaveActiveQuestRequest Packet;
	Packet.Serialize(pStream);

	if (!DBConnection::GetInstance().SaveActiveQuest(Packet.CharacterId, Packet.QuestId))
	{
		std::cout << "Save Active Quest Failed..." << std::endl;
	}
}


// パケット受信.
void PacketReceiver::RecvPacket(u8 ID, MemoryStreamInterface *pStream)
{
	if (PacketFuncs.find(ID) == PacketFuncs.end()) { return; }
	PacketFuncs[ID](pStream);
}


// パケット受信関数を追加.
void PacketReceiver::AddPacketFunc(u8 ID, const PacketFunc &Func)
{
	PacketFuncs[ID] = Func;
}
