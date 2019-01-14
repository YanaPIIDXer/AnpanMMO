/**
 * @file ClientStateTitle.cpp
 * @brief �N���C�A���g�X�e�[�g�F�^�C�g�����
 * @author YanaP
 */
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
#include "Packet/PacketItemList.h"
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
#include "Packet/CachePacketItemListRequest.h"
#include "Packet/CachePacketItemListResponse.h"
#include "Packet/CachePacketItemShortcutRequest.h"
#include "Packet/CachePacketItemShortcutResponse.h"
#include "Packet/PacketItemShortcut.h"
#include "Packet/CachePacketScriptFlagRequest.h"
#include "Packet/CachePacketScriptFlagResponse.h"
#include "Packet/CachePacketQuestDataRequest.h"
#include "Packet/CachePacketQuestDataResponse.h"
#include "Packet/PacketQuestData.h"

// �R���X�g���N�^
ClientStateTitle::ClientStateTitle(Client *pInParent)
	: ClientStateBase(pInParent)
	, LastAreaId(0)
	, LastPosition(Vector3D::Zero)
{
	AddPacketFunction(PacketID::LogInRequest, boost::bind(&ClientStateTitle::OnRecvLogInRequest, this, _2));
	AddPacketFunction(PacketID::CreateCharacterRequest, boost::bind(&ClientStateTitle::OnRecvCreateCharacterRequest, this, _2));
	AddPacketFunction(CachePacketID::CacheLogInResult, boost::bind(&ClientStateTitle::OnRecvCacheLogInResult, this, _2));
	AddPacketFunction(CachePacketID::CacheCreateCharacterResult, boost::bind(&ClientStateTitle::OnRecvCacheCreateCharacterResult, this, _2));
	AddPacketFunction(CachePacketID::CacheCharacterDataResult, boost::bind(&ClientStateTitle::OnRecvCacheCharacterDataResult, this, _2));
	AddPacketFunction(CachePacketID::CacheSkillListResponse, boost::bind(&ClientStateTitle::OnRecvCacheSkillListResponse, this, _2));
	AddPacketFunction(CachePacketID::CacheSkillTreeResponse, boost::bind(&ClientStateTitle::OnRecvCacheSkillTreeResponse, this, _2));
	AddPacketFunction(CachePacketID::CacheItemListResponse, boost::bind(&ClientStateTitle::OnRecvCacheItemListResponse, this, _2));
	AddPacketFunction(CachePacketID::CacheItemShortcutResponse, boost::bind(&ClientStateTitle::OnRecvCacheItemShortcutResponse, this, _2));
	AddPacketFunction(CachePacketID::CacheScriptFlagResponse, boost::bind(&ClientStateTitle::OnRecvCacheScriptFlagResponse, this, _2));
	AddPacketFunction(CachePacketID::CacheQuestDataResponse, boost::bind(&ClientStateTitle::OnRecvCacheQuestDataResponse, this, _2));
}


// ���O�C�����N�G�X�g����M�����B
bool ClientStateTitle::OnRecvLogInRequest(MemoryStreamInterface *pStream)
{
	PacketLogInRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	CachePacketLogInRequest CachePacket(GetParent()->GetUuid(), Packet.UserCode);
	CacheServerConnection::GetInstance()->SendPacket(&CachePacket);

	return true;
}

// �L�����N�^�쐬���N�G�X�g����M�����B
bool ClientStateTitle::OnRecvCreateCharacterRequest(MemoryStreamInterface *pStream)
{
	PacketCreateCharacterRequest Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (Packet.CharacterName.size() == 0)
	{
		PacketCreateCharacterResult ResultPacket(PacketCreateCharacterResult::EmptyName);
		GetParent()->SendPacket(&ResultPacket);
		return true;
	}

	if (Util::CalcStringLength(Packet.CharacterName) > Config::CharacterNameMaxLength)
	{
		PacketCreateCharacterResult ResultPacket(PacketCreateCharacterResult::TooLongName);
		GetParent()->SendPacket(&ResultPacket);
		return true;
	}

	CachePacketCreateCharacterRequest CacheRequestPacket(GetParent()->GetUuid(), GetParent()->GetCustomerId(), Packet.CharacterName, Packet.Job);
	CacheServerConnection::GetInstance()->SendPacket(&CacheRequestPacket);

	return true;
}

// �L���b�V���T�[�o���烍�O�C�����ʂ���M�����B
bool ClientStateTitle::OnRecvCacheLogInResult(MemoryStreamInterface *pStream)
{
	CachePacketLogInResult Packet;
	if (!Packet.Serialize(pStream)) { return false; }

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
		// �_�u�����O�C���`�F�b�N�̓��U���g�R�[�h��Success�������ꍇ�̂ݍs���B
		// �J�X�^�}�h�c����擾�ł����ꍇ�A
		// �������������g�ȊO��������_�u�����O�C���ƊŘ􂷁B
		ClientPtr pDoubleCheck = ClientManager::GetInstance().GetFromCustomerId(Packet.CustomerId);
		if (!pDoubleCheck.expired() && pDoubleCheck.lock().get() != GetParent())
		{
			ResultCode = PacketLogInResult::DoubleLogIn;
		}
	}

	Client *pClient = GetParent();

	// ���U���g�R�[�h��Success�������ꍇ�͏��X��������ɑ���B
	// �����X�����Ă�r���Ŏ��s����\��������̂ŁB
	if (ResultCode != PacketLogInResult::Success)
	{
		PacketLogInResult ResultPacket(ResultCode, pClient->GetUuid(), 0);
		pClient->SendPacket(&ResultPacket);
	}

	if (ResultCode != PacketLogInResult::Success && ResultCode != PacketLogInResult::NoCharacter) { return true; }

	// �L�����N�^�����݂��Ȃ������ꍇ�ł��J�X�^�}�h�c�͓o�^���Ă����B
	pClient->SetCustomerId(Packet.CustomerId);

	if (ResultCode != PacketLogInResult::Success) { return true; }

	CachePacketCharacterDataRequest CharaRequestPacket(pClient->GetUuid(), Packet.CustomerId);
	CacheServerConnection::GetInstance()->SendPacket(&CharaRequestPacket);

	return true;
}

// �L���b�V���T�[�o����L�����N�^�쐬���ʂ���M�����B
bool ClientStateTitle::OnRecvCacheCreateCharacterResult(MemoryStreamInterface *pStream)
{
	CachePacketCreateCharacterResult Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	u8 ResultCode = PacketCreateCharacterResult::Success;
	if (Packet.Result == CachePacketCreateCharacterResult::Error)
	{
		ResultCode = PacketCreateCharacterResult::Error;
	}

	PacketCreateCharacterResult ResultPacket(ResultCode);
	GetParent()->SendPacket(&ResultPacket);

	return true;
}

// �L���b�V���T�[�o����L�����N�^�f�[�^����M�����B
bool ClientStateTitle::OnRecvCacheCharacterDataResult(MemoryStreamInterface *pStream)
{
	CachePacketCharacterDataResult Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (Packet.Result != CachePacketCharacterDataResult::Success)
	{
		std::cout << "CharacterData Load Failed..." << std::endl;
		PacketLogInResult LogInResultPacket(PacketLogInResult::Error, GetParent()->GetUuid(), 0);
		GetParent()->SendPacket(&LogInResultPacket);
		return true;
	}

	Client *pClient = GetParent();
	pClient->CreateCharacter(Packet.CharacterId, Packet.Name, Packet.Job, Packet.Level, Packet.Exp, Packet.Gold, Packet.RightEquip, Packet.LeftEquip);
	const CharacterParameter &Param = pClient->GetCharacter().lock()->GetParameter();
	PacketCharacterStatus StatusPacket(pClient->GetUuid(), Packet.Name, Packet.Job, Packet.Level, Param.GetMaxHp(), Param.GetMaxHp(), Param.GetBaseMaxHp(), Param.GetNaturalStr(), Param.GetNaturalDef(), Param.GetNaturalInt(), Param.GetNaturalMnd(), Param.GetNaturalVit(), Packet.Exp, Packet.Gold, Packet.RightEquip, Packet.LeftEquip);
	pClient->SendPacket(&StatusPacket);

	LastAreaId = Packet.LastAreaId;
	LastPosition = Vector3D(Packet.LastX, Packet.LastY, Packet.LastZ);

	// �X�L�����X�g��v��.
	CachePacketSkillListRequest RequestPacket(pClient->GetUuid(), pClient->GetCharacter().lock()->GetCharacterId());
	CacheServerConnection::GetInstance()->SendPacket(&RequestPacket);

	return true;
}

// �L���b�V���T�[�o����X�L�����X�g����M�����B
bool ClientStateTitle::OnRecvCacheSkillListResponse(MemoryStreamInterface *pStream)
{
	CachePacketSkillListResponse Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (Packet.Result != CachePacketSkillListResponse::Success)
	{
		std::cout << "SkillList Load Failed..." << std::endl;
		PacketLogInResult LogInResultPacket(PacketLogInResult::Error, GetParent()->GetUuid(), 0);
		GetParent()->SendPacket(&LogInResultPacket);
		return true;
	}

	PacketSkillList SkillListPacket(Packet.SkillId1, Packet.SkillId2, Packet.SkillId3, Packet.SkillId4);
	GetParent()->SendPacket(&SkillListPacket);

	// �X�L���c���[����v��.
	CachePacketSkillTreeRequest RequestPacket(GetParent()->GetUuid(), GetParent()->GetCharacter().lock()->GetCharacterId());
	CacheServerConnection::GetInstance()->SendPacket(&RequestPacket);

	return true;
}

// �L���b�V���T�[�o����X�L���c���[�����擾�����B
bool ClientStateTitle::OnRecvCacheSkillTreeResponse(MemoryStreamInterface *pStream)
{
	CachePacketSkillTreeResponse Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (Packet.Result != CachePacketSkillTreeResponse::Success)
	{
		std::cout << "SkillTree Load Failed..." << std::endl;
		PacketLogInResult LogInResultPacket(PacketLogInResult::Error, GetParent()->GetUuid(), 0);
		GetParent()->SendPacket(&LogInResultPacket);
		return true;
	}

	GetParent()->GetCharacter().lock()->InitializeSkillTree(Packet.OpenedList);
	PacketSkillTreeData SkillTreePacket;
	GetParent()->GetCharacter().lock()->GetSkillTree().GenerateNodeDataList(SkillTreePacket.Nodes);
	GetParent()->SendPacket(&SkillTreePacket);
	
	// �A�C�e�����X�g��v��.
	CachePacketItemListRequest RequestPacket(GetParent()->GetUuid(), GetParent()->GetCharacter().lock()->GetCharacterId());
	CacheServerConnection::GetInstance()->SendPacket(&RequestPacket);

	return true;
}

// �L���b�V���T�[�o����A�C�e�����X�g����M�����B
bool ClientStateTitle::OnRecvCacheItemListResponse(MemoryStreamInterface *pStream)
{
	CachePacketItemListResponse Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (Packet.Result != CachePacketItemListResponse::Success)
	{
		std::cout << "Item List Load Failed..." << std::endl;
		PacketLogInResult LogInResultPacket(PacketLogInResult::Error, GetParent()->GetUuid(), 0);
		GetParent()->SendPacket(&LogInResultPacket);
		return true;
	}

	GetParent()->GetCharacter().lock()->OnRecvItemList(Packet.Items);

	PacketItemList ListPacket;
	for (int i = 0; i < Packet.Items.GetCurrentSize(); i++)
	{
		ListPacket.Items.PushBack(Packet.Items[i]);
	}

	GetParent()->SendPacket(&ListPacket);

	// �A�C�e���V���[�g�J�b�g��v��.
	CachePacketItemShortcutRequest RequestPacket(GetParent()->GetUuid(), GetParent()->GetCharacter().lock()->GetCharacterId());
	CacheServerConnection::GetInstance()->SendPacket(&RequestPacket);

	return true;
}

// �L���b�V���T�[�o����A�C�e���V���[�g�J�b�g����M�����B
bool ClientStateTitle::OnRecvCacheItemShortcutResponse(MemoryStreamInterface *pStream)
{
	CachePacketItemShortcutResponse Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (Packet.Result != CachePacketItemShortcutResponse::Success)
	{
		std::cout << "Item Shortcut Load Failed..." << std::endl;
		PacketLogInResult LogInResultPacket(PacketLogInResult::Error, GetParent()->GetUuid(), 0);
		GetParent()->SendPacket(&LogInResultPacket);
		return true;
	}

	// �A�C�e���V���[�g�J�b�g�̓N���C�A���g�ɒʒm���邾���B
	// ���T�[�o�������ɉ����������ł͂Ȃ��B
	PacketItemShortcut ShortcutPacket(Packet.ItemId1, Packet.ItemId2);
	GetParent()->SendPacket(&ShortcutPacket);

	// �X�N���v�g�t���O��v��.
	CachePacketScriptFlagRequest RequestPacket(GetParent()->GetUuid(), GetParent()->GetCharacter().lock()->GetCharacterId());
	CacheServerConnection::GetInstance()->SendPacket(&RequestPacket);

	return true;
}

// �L���b�V���T�[�o����X�N���v�g�t���O����M�����B
bool ClientStateTitle::OnRecvCacheScriptFlagResponse(MemoryStreamInterface *pStream)
{
	CachePacketScriptFlagResponse Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (Packet.Result == CachePacketScriptFlagResponse::Success)
	{
		GetParent()->ConvertScriptFlagFromBitFields(Packet.BitField1, Packet.BitField2, Packet.BitField3);

		PacketScriptFlag FlagPacket(Packet.BitField1, Packet.BitField2, Packet.BitField3);
		GetParent()->SendPacket(&FlagPacket);
	}
	else
	{
		std::cout << "CachePacketScriptFlagResponse Error..." << std::endl;
		PacketLogInResult LogInResultPacket(PacketLogInResult::Error, GetParent()->GetUuid(), 0);
		GetParent()->SendPacket(&LogInResultPacket);
		return true;
	}

	// �N�G�X�g�f�[�^�v��.
	CachePacketQuestDataRequest RequestPacket(GetParent()->GetUuid(), GetParent()->GetCharacter().lock()->GetCharacterId());
	CacheServerConnection::GetInstance()->SendPacket(&RequestPacket);

	return true;
}

// �L���b�V���T�[�o����N�G�X�g�f�[�^����M�����B
bool ClientStateTitle::OnRecvCacheQuestDataResponse(MemoryStreamInterface *pStream)
{
	CachePacketQuestDataResponse Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	if (Packet.Result != CachePacketQuestDataResponse::Success)
	{
		std::cout << "CachePacketQuestDataResponse Error..." << std::endl;
		PacketLogInResult LogInResultPacket(PacketLogInResult::Error, GetParent()->GetUuid(), 0);
		GetParent()->SendPacket(&LogInResultPacket);
		return true;
	}

	// �N���C�A���g�ɓ����t����B
	// �{�������̃N�G�X�g�Ǘ��ɂ��ǉ����Ă����B
	PacketQuestData DataPacket;
	for (int i = 0; i < Packet.Quests.GetCurrentSize(); i++)
	{
		GetParent()->AddQuestData(Packet.Quests[i]);
		DataPacket.Quests.PushBack(Packet.Quests[i]);
	}
	DataPacket.ActiveQuestId = Packet.ActiveQuestId;
	GetParent()->SendPacket(&DataPacket);

	// ���O�C�������p�P�b�g
	PacketLogInResult LogInResultPacket(PacketLogInResult::Success, GetParent()->GetUuid(), LastAreaId);
	GetParent()->SendPacket(&LogInResultPacket);

	// �}�b�v�؂�ւ�State�ցB
	ClientStateAreaChange *pNextState = new ClientStateAreaChange(GetParent(), LastAreaId, LastPosition);
	GetParent()->ChangeState(pNextState);

	return true;
}
