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
#include "Packet/CachePacketSaveEquipRequest.h"
#include "Packet/CachePacketSaveEquipResponse.h"
#include "Packet/CachePacketMailListRequest.h"
#include "Packet/CachePacketMailListResponse.h"
#include "Packet/CachePacketMailRead.h"
#include "Packet/CachePacketMailAttachmentRecvRequest.h"
#include "Packet/CachePacketMailAttachmentRecvResult.h"

// �R���X�g���N�^
PacketReceiver::PacketReceiver(GameServerConnection *pInParent)
	: pParent(pInParent)
{
	AddPacketFunc(CachePacketID::CacheLogInRequest, bind(&PacketReceiver::OnRecvLogInRequest, this, _1));
	AddPacketFunc(CachePacketID::CacheCreateCharacterRequest, bind(&PacketReceiver::OnRecvCreateCharacterRequest, this, _1));
	AddPacketFunc(CachePacketID::CacheCharacterDataRequest, bind(&PacketReceiver::OnRecvCharacterDataRequest, this, _1));
	AddPacketFunc(CachePacketID::CacheCharacterDataSave, bind(&PacketReceiver::OnRecvCharacterDataSaveRequest, this, _1));
	AddPacketFunc(CachePacketID::CacheSkillListRequest, bind(&PacketReceiver::OnRecvSkillListRequest, this, _1));
	AddPacketFunc(CachePacketID::CacheSaveSkillListRequest, bind(&PacketReceiver::OnRecvSaveSkillListRequest, this, _1));
	AddPacketFunc(CachePacketID::CacheSkillTreeRequest, bind(&PacketReceiver::OnRecvSkillTreeRequest, this, _1));
	AddPacketFunc(CachePacketID::CacheOpenSkillTree, bind(&PacketReceiver::OnRecvSkillTreeSaveRequest, this, _1));
	AddPacketFunc(CachePacketID::CacheScriptFlagRequest, bind(&PacketReceiver::OnRecvLoadScriptFlagRequest, this, _1));
	AddPacketFunc(CachePacketID::CacheScriptFlagSaveRequest, bind(&PacketReceiver::OnRecvSaveScriptFlagRequest, this, _1));
	AddPacketFunc(CachePacketID::CacheItemListRequest, bind(&PacketReceiver::OnRecvItemListRequest, this, _1));
	AddPacketFunc(CachePacketID::CacheItemCountChangeRequest, bind(&PacketReceiver::OnRecvItemCountChange, this, _1));
	AddPacketFunc(CachePacketID::CacheItemShortcutRequest, bind(&PacketReceiver::OnRecvItemShortcutRequest, this, _1));
	AddPacketFunc(CachePacketID::CacheSaveItemShortcutRequest, bind(&PacketReceiver::OnRecvSaveItemShortcutRequest, this, _1));
	AddPacketFunc(CachePacketID::CacheGoldSave, bind(&PacketReceiver::OnRecvSaveGold, this, _1));
	AddPacketFunc(CachePacketID::CacheQuestDataRequest, bind(&PacketReceiver::OnRecvQuestDataRequest, this, _1));
	AddPacketFunc(CachePacketID::CacheSaveQuestDataRequest, bind(&PacketReceiver::OnRecvSaveQuestDataRequest, this, _1));
	AddPacketFunc(CachePacketID::CacheQuestRetireRequest, bind(&PacketReceiver::OnRecvRetireQuestDataRequest, this, _1));
	AddPacketFunc(CachePacketID::CacheSaveActiveQuestRequest, bind(&PacketReceiver::OnRecvSaveActiveQuestRequest, this, _1));
	AddPacketFunc(CachePacketID::CacheSaveEquipRequest, bind(&PacketReceiver::OnRecvSaveEquipRequest, this, _1));
	AddPacketFunc(CachePacketID::CacheMailListRequest, bind(&PacketReceiver::OnRecvMailListRequest, this, _1));
	AddPacketFunc(CachePacketID::CacheMailRead, bind(&PacketReceiver::OnRecvMailRead, this, _1));
	AddPacketFunc(CachePacketID::CacheMailAttachmentRecvRequest, bind(&PacketReceiver::OnRecvMailAttachmentRecvRequest, this, _1));
}

// ���O�C�����N�G�X�g����M�����B
bool PacketReceiver::OnRecvLogInRequest(MemoryStreamInterface *pStream)
{
	CachePacketLogInRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	u8 ResultCode = CachePacketLogInResult::Success;
	char *pUserCode = const_cast<char *>(Packet.UserCode.c_str());
	int Id = 0;
	bool bIsBunned = false;
	if (!DBConnection::GetInstance().LoadUserData(pUserCode, Id, bIsBunned))
	{
		ResultCode = CachePacketLogInResult::Error;
	}

	bool bCharaExist = false;
	if (!DBConnection::GetInstance().IsExistCharacter(Id, bCharaExist))
	{
		ResultCode = CachePacketLogInResult::Error;
	}

	if (bIsBunned)
	{
		ResultCode = CachePacketLogInResult::Bunned;
	}

	if (ResultCode == CachePacketLogInResult::Success && !bCharaExist)
	{
		ResultCode = CachePacketLogInResult::NoCharacter;
	}

	if (ResultCode == CachePacketLogInResult::Success)
	{
		// ���łɌÂ����[�����폜���Ă����B
		DBConnection::GetInstance().RemoveOldMails(Id);

		u32 CharacterId = 0;
		if (!DBConnection::GetInstance().GetCharacterId(Id, CharacterId))
		{
			ResultCode = CachePacketLogInResult::Error;
		}
	}
	CachePacketLogInResult ResultPacket(Packet.ClientId, ResultCode, Id);
	pParent->SendPacket(&ResultPacket);

	return true;
}

// �L�����N�^�쐬���N�G�X�g����M�����B
bool PacketReceiver::OnRecvCreateCharacterRequest(MemoryStreamInterface *pStream)
{
	CachePacketCreateCharacterRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	u8 ResultCode = CachePacketCreateCharacterResult::Success;
	char *pCharaName = const_cast<char *>(Packet.CharacterName.c_str());
	if (!DBConnection::GetInstance().RegisterCharacterData(Packet.CustomerId, pCharaName, Packet.Job))
	{
		ResultCode = CachePacketCreateCharacterResult::Error;
	}

	CachePacketCreateCharacterResult ResultPacket(Packet.ClientId, ResultCode);
	pParent->SendPacket(&ResultPacket);

	return true;
}

// �L�����N�^��񃊃N�G�X�g����M�����B
bool PacketReceiver::OnRecvCharacterDataRequest(MemoryStreamInterface *pStream)
{
	CachePacketCharacterDataRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	std::string Name;
	u32 CharacterId;
	u8 Job = 0;
	u32 Level = 0;
	u32 Exp = 0;
	u32 Gold = 0;
	bool bIsGM = false;
	u32 RightEquip = 0;
	u32 LeftEquip = 0;
	CachePacketCharacterDataResult::ResultCode ResultCode = CachePacketCharacterDataResult::Success;
	if (!DBConnection::GetInstance().LoadCharacterParameter(Packet.CustomerId, CharacterId, Name, Job, Level, Exp, Gold, bIsGM, RightEquip, LeftEquip))
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

	CachePacketCharacterDataResult ResultPacket(Packet.ClientId, CharacterId,ResultCode, Name, Job, Level, Exp, Gold, RightEquip, LeftEquip, (bIsGM ? 1 : 0), LastAreaId, LastX, LastY, LastZ);
	pParent->SendPacket(&ResultPacket);

	return true;
}

// �L�����N�^�ۑ����N�G�X�g����M�����B
bool PacketReceiver::OnRecvCharacterDataSaveRequest(MemoryStreamInterface *pStream)
{
	CachePacketCharacterDataSave Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (!DBConnection::GetInstance().SaveCharacterParameter(Packet.CharacterId, Packet.Level, Packet.Exp, Packet.LastAreaId, Packet.LastX, Packet.LastY, Packet.LastZ))
	{
		std::cout << "Character Data Save Failed..." << std::endl;
	}

	return true;
}

// �X�L�����X�g�v������M�����B
bool PacketReceiver::OnRecvSkillListRequest(MemoryStreamInterface *pStream)
{
	CachePacketSkillListRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	u8 Result = CachePacketSkillListResponse::Success;
	u32 Skill1 = 0;
	u32 Skill2 = 0;
	u32 Skill3 = 0;
	u32 Skill4 = 0;
	if (!DBConnection::GetInstance().LoadSkillList(Packet.CharacterId, Skill1, Skill2, Skill3, Skill4))
	{
		Result = CachePacketSkillListResponse::Error;
	}

	CachePacketSkillListResponse ResponsePacket(Packet.ClientId, Result, Skill1, Skill2, Skill3, Skill4);
	pParent->SendPacket(&ResponsePacket);

	return true;
}

// �X�L�����X�g�ۑ��v������M�����B
bool PacketReceiver::OnRecvSaveSkillListRequest(MemoryStreamInterface *pStream)
{
	CachePacketSaveSkillListRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	u8 Result = CachePacketSaveSkillListResponse::Success;
	if (!DBConnection::GetInstance().SaveSkillList(Packet.CharacterId, Packet.SkillId1, Packet.SkillId2, Packet.SkillId3, Packet.SkillId4))
	{
		Result = CachePacketSaveSkillListResponse::Error;
	}

	CachePacketSaveSkillListResponse ResponsePacket(Packet.ClientId, Result, Packet.SkillId1, Packet.SkillId2, Packet.SkillId3, Packet.SkillId4);
	pParent->SendPacket(&ResponsePacket);

	return true;
}

// �X�L���c���[���N�G�X�g����M�����B
bool PacketReceiver::OnRecvSkillTreeRequest(MemoryStreamInterface *pStream)
{
	CachePacketSkillTreeRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	u8 Result = CachePacketSkillTreeResponse::Success;
	CachePacketSkillTreeResponse ResponsePacket;
	if (!DBConnection::GetInstance().LoadSkillTree(Packet.CharacterId, ResponsePacket.OpenedList))
	{
		Result = CachePacketSkillTreeResponse::Error;
	}

	ResponsePacket.ClientId = Packet.ClientId;
	ResponsePacket.Result = Result;
	pParent->SendPacket(&ResponsePacket);

	return true;
}

// �X�L���c���[�ۑ��v������M�����B
bool PacketReceiver::OnRecvSkillTreeSaveRequest(MemoryStreamInterface *pStream)
{
	CachePacketOpenSkillTree Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (!DBConnection::GetInstance().SaveSkillTree(Packet.CharacterId, Packet.NodeId))
	{
		std::cout << "SkillTree Save Failed..." << std::endl;
	}

	return true;
}

// �X�N���v�g�t���O�ǂݍ��݃��N�G�X�g����M�����B
bool PacketReceiver::OnRecvLoadScriptFlagRequest(MemoryStreamInterface *pStream)
{
	CachePacketScriptFlagRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	u32 BitField1, BitField2, BitField3;
	u8 Result = CachePacketScriptFlagResponse::Success;
	if (!DBConnection::GetInstance().LoadScriptFlags(Packet.CharacterId, BitField1, BitField2, BitField3))
	{
		Result = CachePacketScriptFlagResponse::Error;
	}

	CachePacketScriptFlagResponse ResponsePacket(Packet.ClientId, Result, BitField1, BitField2, BitField3);
	pParent->SendPacket(&ResponsePacket);

	return true;
}

// �X�N���v�g�t���O�ۑ����N�G�X�g����M�����B
bool PacketReceiver::OnRecvSaveScriptFlagRequest(MemoryStreamInterface *pStream)
{
	CachePacketScriptFlagSaveRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (!DBConnection::GetInstance().SaveScriptFlags(Packet.CharacterId, Packet.BitField1, Packet.BitField2, Packet.BitField3))
	{
		std::cout << "ScriptFlags Save Failed..." << std::endl;
	}

	return true;
}

// �A�C�e�����X�g���N�G�X�g����M�����B
bool PacketReceiver::OnRecvItemListRequest(MemoryStreamInterface *pStream)
{
	CachePacketItemListRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	CachePacketItemListResponse ResponsePacket;
	ResponsePacket.ClientId = Packet.ClientId;
	ResponsePacket.Result = CachePacketItemListResponse::Success;
	if (!DBConnection::GetInstance().LoadItemList(Packet.CharacterId, ResponsePacket.Items))
	{
		ResponsePacket.Result = CachePacketItemListResponse::Error;
	}

	pParent->SendPacket(&ResponsePacket);

	return true;
}

// �A�C�e�����ϓ�����M�����B
bool PacketReceiver::OnRecvItemCountChange(MemoryStreamInterface *pStream)
{
	CachePacketItemCountChangeRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (!DBConnection::GetInstance().ChangeItemCount(Packet.CharacterId, Packet.ItemId, Packet.Count))
	{
		std::cout << "Item Count Change Failed..." << std::endl;
	}

	return true;
}

// �A�C�e���V���[�g�J�b�g�ǂݍ��݃��N�G�X�g����M�����B
bool PacketReceiver::OnRecvItemShortcutRequest(MemoryStreamInterface *pStream)
{
	CachePacketItemShortcutRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	u8 Result = CachePacketItemShortcutResponse::Success;
	u32 ItemId1 = 0, ItemId2 = 0;
	if (!DBConnection::GetInstance().LoadItemShortcut(Packet.CharacterId, ItemId1, ItemId2))
	{
		Result = CachePacketItemShortcutResponse::Error;
	}

	CachePacketItemShortcutResponse ResponsePacket(Packet.ClientId, Result, ItemId1, ItemId2);
	pParent->SendPacket(&ResponsePacket);

	return true;
}

// �A�C�e���V���[�g�J�b�g�������݃��N�G�X�g����M�����B
bool PacketReceiver::OnRecvSaveItemShortcutRequest(MemoryStreamInterface *pStream)
{
	CachePacketSaveItemShortcutRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	u8 Result = CachePacketSaveItemShortcutResponse::Success;
	if (!DBConnection::GetInstance().SaveItemShortcut(Packet.CharacterId, Packet.ItemId1, Packet.ItemId2))
	{
		Result = CachePacketSaveItemShortcutResponse::Error;
	}

	CachePacketSaveItemShortcutResponse ResponsePacket(Packet.ClientId, Result, Packet.ItemId1, Packet.ItemId2);
	pParent->SendPacket(&ResponsePacket);

	return true;
}

// �S�[���h�ۑ����N�G�X�g����M�����B
bool PacketReceiver::OnRecvSaveGold(MemoryStreamInterface *pStream)
{
	CachePacketGoldSave Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (!DBConnection::GetInstance().SaveGold(Packet.CharacterId, Packet.Gold))
	{
		std::cout << "Save Gold Failed..." << std::endl;
	}

	return true;
}

// �N�G�X�g�f�[�^���N�G�X�g����M�����B
bool PacketReceiver::OnRecvQuestDataRequest(MemoryStreamInterface *pStream)
{
	CachePacketQuestDataRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	CachePacketQuestDataResponse ResponsePacket;
	ResponsePacket.ClientId = Packet.ClientId;
	ResponsePacket.Result = CachePacketQuestDataResponse::Success;
	if (!DBConnection::GetInstance().LoadQuestData(Packet.CharacterId, ResponsePacket.Quests, ResponsePacket.ActiveQuestId))
	{
		ResponsePacket.Result = CachePacketQuestDataResponse::Error;
	}

	pParent->SendPacket(&ResponsePacket);

	return true;
}

// �N�G�X�g�f�[�^�ۑ����N�G�X�g����M�����B
bool PacketReceiver::OnRecvSaveQuestDataRequest(MemoryStreamInterface *pStream)
{
	CachePacketSaveQuestDataRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (!DBConnection::GetInstance().SaveQuestData(Packet.CharacterId, Packet.Data.QuestId, Packet.Data.StageNo, Packet.Data.KillCount, Packet.Data.State))
	{
		std::cout << "QuestData Save Failed..." << std::endl;
	}

	return true;
}

// �N�G�X�g�j�����N�G�X�g����M�����B
bool PacketReceiver::OnRecvRetireQuestDataRequest(MemoryStreamInterface *pStream)
{
	CachePacketQuestRetireRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (!DBConnection::GetInstance().EraseQuestData(Packet.CharacterId, Packet.QuestId))
	{
		std::cout << "Erase QuestData Failed..." << std::endl;
	}

	return true;
}

// �A�N�e�B�u�N�G�X�g�ۑ����N�G�X�g����M�����B
bool PacketReceiver::OnRecvSaveActiveQuestRequest(MemoryStreamInterface *pStream)
{
	CachePacketSaveActiveQuestRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (!DBConnection::GetInstance().SaveActiveQuest(Packet.CharacterId, Packet.QuestId))
	{
		std::cout << "Save Active Quest Failed..." << std::endl;
	}

	return true;
}

// �����f�[�^�ۑ����N�G�X�g����M�����B
bool PacketReceiver::OnRecvSaveEquipRequest(MemoryStreamInterface *pStream)
{
	CachePacketSaveEquipRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	u8 Result = CachePacketSaveEquipResponse::Success;
	if (!DBConnection::GetInstance().SaveEquipData(Packet.CharacterId, Packet.RightEquip, Packet.LeftEquip))
	{
		Result = CachePacketSaveEquipResponse::Error;
	}

	CachePacketSaveEquipResponse ResponsePacket(Packet.ClientId, Result, Packet.RightEquip, Packet.LeftEquip);
	pParent->SendPacket(&ResponsePacket);

	return true;
}

// ���[�����X�g���N�G�X�g����M�����B
bool PacketReceiver::OnRecvMailListRequest(MemoryStreamInterface *pStream)
{
	CachePacketMailListRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	CachePacketMailListResponse ResponsePacket;
	ResponsePacket.ClientId = Packet.ClientId;

	if (!DBConnection::GetInstance().LoadMailList(Packet.CustomerId, ResponsePacket.List))
	{
		std::cout << "LoadMailList Failed... CustomerId:" << Packet.CustomerId << std::endl;
	}
	pParent->SendPacket(&ResponsePacket);

	return true;
}

// ���[���J������M�����B
bool PacketReceiver::OnRecvMailRead(MemoryStreamInterface *pStream)
{
	CachePacketMailRead Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	MailData Data;
	if (!DBConnection::GetInstance().LoadMailData(Packet.Id, Data))
	{
		std::cout << "Mail Not Found... Id:" << Packet.Id << std::endl;
		return true;
	}

	// �t���O�����ǂɂȂ��Ă��Ȃ��ꍇ�͉������Ȃ��B
	if (Data.Flag != MailData::NotRead) { return true; }

	if (!DBConnection::GetInstance().ChangeMailFlag(Packet.Id, MailData::Read))
	{
		std::cout << "Mail Read Failed... Mail ID:" << Packet.Id << std::endl;
	}

	return true;
}

// ���[���Y�t����M�v������M�����B
bool PacketReceiver::OnRecvMailAttachmentRecvRequest(MemoryStreamInterface *pStream)
{
	CachePacketMailAttachmentRecvRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	MailData Data;
	u8 Result = CachePacketMailAttachmentRecvResult::Error;
	if (DBConnection::GetInstance().LoadMailData(Packet.Id, Data))
	{
		Result = CachePacketMailAttachmentRecvResult::Success;
		if (Data.Flag == MailData::RecvAttachment)
		{
			Result = CachePacketMailAttachmentRecvResult::AlreadyRecv;
		}
	}

	if (Result == CachePacketMailAttachmentRecvResult::Success)
	{
		if (!DBConnection::GetInstance().ChangeMailFlag(Packet.Id, MailData::RecvAttachment))
		{
			Result = CachePacketMailAttachmentRecvResult::Error;
		}
	}

	CachePacketMailAttachmentRecvResult ResultPacket(Packet.ClientId, Packet.Id, Result, Data.AttachmentType, Data.AttachmentId, Data.AttachmentCount);
	pParent->SendPacket(&ResultPacket);

	return true;
}


// �p�P�b�g��M.
void PacketReceiver::RecvPacket(u8 ID, MemoryStreamInterface *pStream)
{
	if (PacketFuncs.find(ID) == PacketFuncs.end()) { return; }
	if (!PacketFuncs[ID](pStream))
	{
		std::cout << "PacketID:" << (int)ID << " Serialize Failed..." << std::endl;
	}
}


// �p�P�b�g��M�֐���ǉ�.
void PacketReceiver::AddPacketFunc(u8 ID, const PacketFunc &Func)
{
	PacketFuncs[ID] = Func;
}
