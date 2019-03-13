/**
 * @file GMCommandParser.cpp
 * @brief �f�l�R�}���h��̓N���X
 * @author YanaP
 */
#include "stdafx.h"
#include "GMCommandParser.h"
#include <algorithm>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include "GMCommandType.h"

// �R���X�g���N�^
GMCommandParser::GMCommandParser(const std::string &InCommand)
	: Command(InCommand)
{
}

// �R�}���h�̎�ނ��擾.
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

// �������X�g���擾
std::vector<GMCommandArg> GMCommandParser::GetArgList() const
{
	std::vector<GMCommandArg> ArgList;
	if (!IsCommand()) { return ArgList; }

	std::vector<std::string> List;
	algorithm::split(List, Command, is_any_of(" "));
	List.erase(List.begin());

	for (u32 i = 0; i < List.size(); i++)
	{
		GMCommandArg Arg(List[i]);
		ArgList.push_back(Arg);
	}

	return ArgList;
}
