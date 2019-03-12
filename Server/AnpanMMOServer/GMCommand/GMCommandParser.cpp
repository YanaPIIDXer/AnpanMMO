/**
 * @file GMCommandParser.cpp
 * @brief ＧＭコマンド解析クラス
 * @author YanaP
 */
#include "stdafx.h"
#include "GMCommandParser.h"
#include <algorithm>
#include "GMCommandType.h"

// コンストラクタ
GMCommandParser::GMCommandParser(const std::string &InCommand)
	: Command(InCommand)
{
}

// コマンドの種類を取得.
u8 GMCommandParser::GetCommandType() const
{
	if (!IsCommand()) { return EGMCommandType::Invalid; }
	u8 Type = EGMCommandType::Invalid;
	std::string Cmd = Command.substr(1);
	transform(Cmd.begin(), Cmd.end(), Cmd.begin(), toupper);
	if (Cmd == "additem")
	{
		Type = EGMCommandType::AddItem;
	}
	else if (Cmd == "addexp")
	{
		Type = EGMCommandType::AddExp;
	}
	else if (Cmd == "gmmessage")
	{
		Type = EGMCommandType::GMMessage;
	}
	
	return Type;
}
