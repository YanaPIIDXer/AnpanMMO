/**
 * @file GMCommandExecuter.cpp
 * @brief �f�l�R�}���h���s�N���X
 * @author YanaP
 */
#include "stdafx.h"
#include "GMCommandExecuter.h"
#include "GMCommandType.h"
#include "Client.h"
#include "Character/Player/PlayerCharacter.h"
#include "Master/MasterData.h"
#include "ClientManager.h"
#include "Packet/PacketReceiveGMMessage.h"

// �R���X�g���N�^
GMCommandExecuter::GMCommandExecuter(Client *pInClient, const GMCommandParser &InParser)
	: pClient(pInClient)
	, Parser(InParser)
{
}

// ���s.
u8 GMCommandExecuter::Execute()
{
	u8 Result = Success;
	u8 Type = Parser.GetCommandType();
	std::vector<GMCommandArg> Args = Parser.GetArgList();
	switch (Type)
	{
		case EGMCommandType::Invalid:

			// �����ȃR�}���h
			Result = InvalidCommand;
			break;

		case EGMCommandType::AddItem:

			// �A�C�e���ǉ�.
			Result = AddItem(Args);
			break;

		case EGMCommandType::AddExp:

			// �o���l�ǉ�.
			Result = AddExp(Args);
			break;

		case EGMCommandType::GMMessage:

			// �f�l���b�Z�[�W���M.
			Result = SendGMMessage(Args);
			break;
	}

	return Result;
}


// �A�C�e���ǉ�.
u8 GMCommandExecuter::AddItem(const std::vector<GMCommandArg> &Args)
{
	// �����͂Q�B
	if (Args.size() < 2) { return InvalidArg; }

	// �����̎擾.
	s32 ItemId = 0;
	s32 Count = 0;
	if (!Args[0].TryGetAsNumber(ItemId) || !Args[1].TryGetAsNumber(Count)) { return InvalidArg; }

	// �L���ȃA�C�e���H
	if (ItemId < 10000)
	{
		const ItemItem *pItem = MasterData::GetInstance().GetItemMaster().GetItem(ItemId);
		if (pItem == NULL) { return InvalidItem; }
	}
	else
	{
		const EquipItem *pItem = MasterData::GetInstance().GetEquipMaster().GetItem(ItemId);
		if (pItem == NULL) { return InvalidItem; }
	}

	// �A�C�e���ǉ�.
	pClient->GetCharacter().lock()->AddItem(ItemId, Count);

	return Success;
}

// �o���l�ǉ�.
u8 GMCommandExecuter::AddExp(const std::vector<GMCommandArg> &Args)
{
	// �����͂P�B
	if (Args.size() < 1) { return InvalidArg; }

	// �����̎擾.
	s32 Exp = 0;
	if (!Args[0].TryGetAsNumber(Exp)) { return InvalidArg; }

	// �o���l�̒ǉ�.
	pClient->GetCharacter().lock()->AddExp(Exp);

	return Success;
}

// �f�l���b�Z�[�W���M.
u8 GMCommandExecuter::SendGMMessage(const std::vector<GMCommandArg> &Args)
{
	// �����͂P�B
	if (Args.size() < 1) { return InvalidArg; }

	std::string Message = Args[0].Get();
	PacketReceiveGMMessage Packet(Message);

	ClientManager::GetInstance().BroadcastPacket(&Packet);

	return Success;
}
