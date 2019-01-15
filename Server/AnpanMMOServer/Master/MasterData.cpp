/**
 * @file MasterData.cpp
 * @brief マスタデータクラス
 * @author YanaP
 */
#include "stdafx.h"
#include "MasterData.h"
#include <fstream>
#include "MySQL/MySqlConnection.h"

const char *MasterData::DBHost = "127.0.0.1";
const char *MasterData::DBName = "AnpanMMOMaster";
const std::string MasterData::DBDataFileName = "MasterDBUserData.txt";
MasterData MasterData::Instance;

// 読み込み
bool MasterData::Read()
{
	std::ifstream FileStream(DBDataFileName.c_str());
	if (!FileStream)
	{
		std::cout << DBDataFileName << " Open Failed..." << std::endl;
		return false;
	}

	char UserName[128];
	char Password[128];
	FileStream.getline(UserName, 128);
	FileStream.getline(Password, 128);
	FileStream.close();

	MySqlConnection Connection;
	if (!Connection.Connect(DBHost, UserName, Password, DBName))
	{
		std::cout << "Master Database Connection Failed..." << std::endl;
		return false;
	}

	if (!Area.Load(Connection))
	{
		std::cout << "Area Master Load Failed..." << std::endl;
		return false;
	}

	if (!WarpData.Load(Connection))
	{
		std::cout << "WarpData Master Load Failed..." << std::endl;
		return false;
	}

	if (!Anpan.Load(Connection))
	{
		std::cout << "Anpan Master Load Failed..." << std::endl;
		return false;
	}

	if (!AnpanPopArea.Load(Connection))
	{
		std::cout << "AnpanPopArea Master Load Failed..." << std::endl;
		return false;
	}

	if (!AnpanPopData.Load(Connection))
	{
		std::cout << "AnpanPopData Master Load Failed..." << std::endl;
		return false;
	}

	if (!InstanceInfo.Load(Connection))
	{
		std::cout << "InstanceInfo Master Load Failed..." << std::endl;
		return false;
	}

	if (!TimeInfo.Load(Connection))
	{
		std::cout << "TimeInfo Master Load Failed..." << std::endl;
		return false;
	}

	if (!NPC.Load(Connection))
	{
		std::cout << "NPC Master Load Failed..." << std::endl;
		return false;
	}

	if (!Skill.Load(Connection))
	{
		std::cout << "Skill Master Load Failed..." << std::endl;
		return false;
	}

	if (!SkillTree.Load(Connection))
	{
		std::cout << "SkillTree Master Load Failed..." << std::endl;
		return false;
	}

	if (!Item.Load(Connection))
	{
		std::cout << "Item Master Load Failed..." << std::endl;
		return false;
	}

	if (!ItemDrop.Load(Connection))
	{
		std::cout << "ItemDrop Master Load Failed..." << std::endl;
		return false;
	}

	if (!Quest.Load(Connection))
	{
		std::cout << "Quest Master Load Failed..." << std::endl;
		return false;
	}

	if (!QuestStage.Load(Connection))
	{
		std::cout << "QuestStage Master Load Failed..." << std::endl;
		return false;
	}

	if (!QuestReward.Load(Connection))
	{
		std::cout << "QuestReward Master Load Failed..." << std::endl;
		return false;
	}

	if (!Level.Load(Connection))
	{
		std::cout << "Level Master Load Failed..." << std::endl;
		return false;
	}

	if (!Equip.Load(Connection))
	{
		std::cout << "Equip Master Load Failed..." << std::endl;
		return false;
	}

	if (!Buff.Load(Connection))
	{
		std::cout << "Buff Master Load Failed..." << std::endl;
		return false;
	}

	return true;
}
