/**
 * @file GMCommandExecuter.cpp
 * @brief ＧＭコマンド実行クラス
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

// コンストラクタ
GMCommandExecuter::GMCommandExecuter(Client *pInClient, const GMCommandParser &InParser)
	: pClient(pInClient)
	, Parser(InParser)
{
}

// 実行.
u8 GMCommandExecuter::Execute()
{
	u8 Result = Success;
	u8 Type = Parser.GetCommandType();
	std::vector<GMCommandArg> Args = Parser.GetArgList();
	switch (Type)
	{
		case EGMCommandType::Invalid:

			// 無効なコマンド
			Result = InvalidCommand;
			break;

		case EGMCommandType::AddItem:

			// アイテム追加.
			Result = AddItem(Args);
			break;

		case EGMCommandType::AddExp:

			// 経験値追加.
			Result = AddExp(Args);
			break;

		case EGMCommandType::GMMessage:

			// ＧＭメッセージ送信.
			Result = SendGMMessage(Args);
			break;
	}

	return Result;
}


// アイテム追加.
u8 GMCommandExecuter::AddItem(const std::vector<GMCommandArg> &Args)
{
	// 引数は２つ。
	if (Args.size() < 2) { return InvalidArg; }

	// 引数の取得.
	s32 ItemId = 0;
	s32 Count = 0;
	if (!Args[0].TryGetAsNumber(ItemId) || !Args[1].TryGetAsNumber(Count)) { return InvalidArg; }

	// 有効なアイテム？
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

	// アイテム追加.
	pClient->GetCharacter().lock()->AddItem(ItemId, Count);

	return Success;
}

// 経験値追加.
u8 GMCommandExecuter::AddExp(const std::vector<GMCommandArg> &Args)
{
	// 引数は１つ。
	if (Args.size() < 1) { return InvalidArg; }

	// 引数の取得.
	s32 Exp = 0;
	if (!Args[0].TryGetAsNumber(Exp)) { return InvalidArg; }

	// 経験値の追加.
	pClient->GetCharacter().lock()->AddExp(Exp);

	return Success;
}

// ＧＭメッセージ送信.
u8 GMCommandExecuter::SendGMMessage(const std::vector<GMCommandArg> &Args)
{
	// 引数は１つ。
	if (Args.size() < 1) { return InvalidArg; }

	std::string Message = Args[0].Get();
	PacketReceiveGMMessage Packet(Message);

	ClientManager::GetInstance().BroadcastPacket(&Packet);

	return Success;
}
