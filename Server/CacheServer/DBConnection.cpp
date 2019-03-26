#include "stdafx.h"
#include "DBConnection.h"
#include <fstream>
#include "Packet/CharacterJob.h"
#include "Packet/ItemData.h"
#include "Packet/QuestData.h"

const std::string DBConnection::UserDataFileName = "DBUserData.txt";
const char *DBConnection::DBHost = "127.0.0.1";
const char *DBConnection::DBName = "AnpanMMO";
DBConnection DBConnection::Instance;

// 開く
bool DBConnection::Open()
{
	std::ifstream FileStream(UserDataFileName.c_str());
	if (!FileStream)
	{
		std::cout << UserDataFileName << " Open Failed..." << std::endl;
		return false;
	}

	char UserName[256];
	char PassWord[256];
	FileStream.getline(UserName, 256);
	FileStream.getline(PassWord, 256);
	FileStream.close();

	return Connection.Connect(DBHost, UserName, PassWord, DBName);
}

// ユーザデータ読み込み
bool DBConnection::LoadUserData(char *pUserCode, int &OutId, bool &bOutIsBunned)
{
	MySqlQuery Query = Connection.CreateQuery("select Id, IsBunned from UserData where UserCode = ?;");
	Query.BindString(pUserCode);

	int Id = 0;
	char IsBunnedFlag = 0;
	Query.BindResultInt(&Id);
	Query.BindResultChar(&IsBunnedFlag);
	if (!Query.ExecuteQuery()) { return false; }

	if (!Query.Fetch())
	{
		// 登録して検索し直す。
		if (!RegisterUserData(pUserCode)) { return false; }
		return LoadUserData(pUserCode, OutId, bOutIsBunned);
	}
	
	OutId = Id;
	bOutIsBunned = (IsBunnedFlag == 1);
	return true;
}

// キャラクタデータが存在するか？
bool DBConnection::IsExistCharacter(int Id, bool &OutResult)
{
	MySqlQuery Query = Connection.CreateQuery("select CustomerId from CharacterData where CustomerId = ?");
	Query.BindInt(&Id);

	int DummyId;
	Query.BindResultInt(&DummyId);

	if (!Query.ExecuteQuery()) { return false; }
	OutResult = Query.Fetch();
	
	return true;
}

// キャラクタＩＤを取得.
bool DBConnection::GetCharacterId(int Id, u32 &OutCharacterId)
{
	MySqlQuery Query = Connection.CreateQuery("select CharacterId from CharacterData where CustomerId = ?");

	Query.BindInt(&Id);
	Query.BindResultInt(&OutCharacterId);

	if (!Query.ExecuteQuery()) { return false; }
	if (!Query.Fetch()) { return false; }

	return true;
}

// キャラクタデータ登録.
bool DBConnection::RegisterCharacterData(u32 Id, char *pCharacterName, u8 Job)
{
	MySqlQuery Query = Connection.CreateQuery("insert into CharacterData(CustomerId, Name, Job, Level, Exp, Gold, RightEquip, LeftEquip, LastArea, LastX, LastY, LastZ) values(?, ?, ?, 1, 0, 0, ?, ?, 1, -1300.0, 4050.0, 42.0);");

	// 初期装備.
	u32 RightEquip = 0;
	u32 LeftEquip = 0;
	switch (Job)
	{
		case CharacterJob::Fighter:

			RightEquip = 10001;
			LeftEquip = 10002;
			break;

		case CharacterJob::Sorcerer:

			RightEquip = 10003;
			break;

		case CharacterJob::Healer:

			RightEquip = 10004;
			break;

		case CharacterJob::Lancer:

			RightEquip = 10005;
			break;
	}

	Query.BindInt(&Id);
	Query.BindString(pCharacterName);
	Query.BindChar(&Job);
	Query.BindInt(&RightEquip);
	Query.BindInt(&LeftEquip);
	if (!Query.ExecuteQuery()) { return false; }
	Query.Close();

	// スキルテーブル
	// まずはキャラクタＩＤを引っ張る。
	u32 CharacterId = 0;
	Query = Connection.CreateQuery("select CharacterId from CharacterData where CustomerId = ?;");
	Query.BindInt(&Id);
	Query.BindResultInt(&CharacterId);
	if (!Query.ExecuteQuery()) { return false; }
	if (!Query.Fetch()) { return false; }
	Query.Close();

	Query = Connection.CreateQuery("insert into SkillData Values(?, 0, 0, 0, 0);");
	Query.BindInt(&CharacterId);
	if (!Query.ExecuteQuery()) { return false; }
	
	return true;
}

// キャラクタパラメータ読み込み
bool DBConnection::LoadCharacterParameter(int Id, u32 &OutCharacterId, std::string &OutName, u8 &OutJob, u32 &OutLevel, u32 &OutExp, u32 &OutGold, bool &bOutIsGM, u32 &OutRightEquip, u32 &OutLeftEquip)
{
	MySqlQuery Query = Connection.CreateQuery("select CharacterId, Name, Job, Level, Exp, Gold, RightEquip, LeftEquip, IsGM from CharacterData where CustomerId = ?");
	Query.BindInt(&Id);

	char NameStr[256];

	u8 bIsGM = 0;
	
	Query.BindResultInt(&OutCharacterId);
	Query.BindResultString(NameStr);
	Query.BindResultChar(&OutJob);
	Query.BindResultInt(&OutLevel);
	Query.BindResultInt(&OutExp);
	Query.BindResultInt(&OutGold);
	Query.BindResultInt(&OutRightEquip);
	Query.BindResultInt(&OutLeftEquip);
	Query.BindResultChar(&bIsGM);

	if (!Query.ExecuteQuery()) { return false; }
	if (!Query.Fetch()) { return false; }

	bOutIsGM = (bIsGM == 1);

	OutName = NameStr;
	return true;
}

// キャラクタパラメータ書き込み
bool DBConnection::SaveCharacterParameter(u32 CharacterId, u32 Level, u32 Exp, int AreaId, float X, float Y, float Z)
{
	MySqlQuery Query = Connection.CreateQuery("update CharacterData set Level = ?, Exp = ?, LastArea = ?, LastX = ?, LastY = ?, LastZ = ? where CharacterId = ?");

	Query.BindInt(&Level);
	Query.BindInt(&Exp);
	Query.BindInt(&AreaId);
	Query.BindFloat(&X);
	Query.BindFloat(&Y);
	Query.BindFloat(&Z);
	Query.BindInt(&CharacterId);

	if (!Query.ExecuteQuery()) { return false; }

	return true;
}

// スキルリスト読み込み
bool DBConnection::LoadSkillList(u32 CharacterId, u32 &OutSkill1, u32 &OutSkill2, u32 &OutSkill3, u32 &OutSkill4)
{
	MySqlQuery Query = Connection.CreateQuery("select Skill1, Skill2, Skill3, Skill4 from SkillData where CharacterId = ?;");
	Query.BindInt(&CharacterId);
	Query.BindResultInt(&OutSkill1);
	Query.BindResultInt(&OutSkill2);
	Query.BindResultInt(&OutSkill3);
	Query.BindResultInt(&OutSkill4);

	if (!Query.ExecuteQuery()) { return false; }
	if (!Query.Fetch()) { return false; }

	return true;
}

// スキルリスト保存.
bool DBConnection::SaveSkillList(u32 CharacterId, u32 Skill1, u32 Skill2, u32 Skill3, u32 Skill4)
{
	MySqlQuery Query = Connection.CreateQuery("update SkillData set Skill1 = ?, Skill2 = ?, Skill3 = ?, Skill4 = ? where CharacterId = ?;");
	Query.BindInt(&Skill1);
	Query.BindInt(&Skill2);
	Query.BindInt(&Skill3);
	Query.BindInt(&Skill4);
	Query.BindInt(&CharacterId);
	if (!Query.ExecuteQuery()) { return false; }

	return true;
}

// スキルツリー読み込み
bool DBConnection::LoadSkillTree(u32 CharacterId, FlexArray<u32> &OutOpenedList)
{
	MySqlQuery Query = Connection.CreateQuery("select NodeId from SkillTree where CharacterId = ?;");
	Query.BindInt(&CharacterId);

	u32 NodeId;
	Query.BindResultInt(&NodeId);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		OutOpenedList.PushBack(NodeId);
	}

	return true;
}

// スキルツリー保存.
bool DBConnection::SaveSkillTree(u32 CharacterId, u32 NodeId)
{
	MySqlQuery Query = Connection.CreateQuery("insert into SkillTree Values(?, ?);");
	Query.BindInt(&CharacterId);
	Query.BindInt(&NodeId);

	if (!Query.ExecuteQuery()) { return false; }
	return true;
}

// アイテムリスト読み込み
bool DBConnection::LoadItemList(u32 CharacterId, FlexArray<ItemData> &OutItemList)
{
	MySqlQuery Query = Connection.CreateQuery("select ItemId, Count from ItemData where CharacterId = ?");

	Query.BindInt(&CharacterId);

	ItemData BindData;
	Query.BindResultInt(&BindData.ItemId);
	Query.BindResultInt(&BindData.Count);
	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		OutItemList.PushBack(BindData);
	}

	return true;
}

// アイテム数変化.
bool DBConnection::ChangeItemCount(u32 CharacterId, u32 ItemId, u32 Count)
{
	// まずは既にリストに存在するかどうかをチェック
	MySqlQuery Query = Connection.CreateQuery("select ItemId from ItemData where CharacterId = ? and ItemId = ?;");

	Query.BindInt(&CharacterId);
	Query.BindInt(&ItemId);

	u32 Dummy = 0;
	Query.BindResultInt(&Dummy);
	if (!Query.ExecuteQuery()) { return false; }
	if (Query.Fetch())
	{
		// 存在するのでupdate
		Query.Close();
		if (Count > 0)
		{
			Query = Connection.CreateQuery("update ItemData set Count = ? where CharacterId = ? and ItemId = ?;");

			Query.BindInt(&Count);
			Query.BindInt(&CharacterId);
			Query.BindInt(&ItemId);

			if (!Query.ExecuteQuery()) { return false; }
		}
		else
		{
			// ０個ならテーブルから削除。
			Query = Connection.CreateQuery("delete from ItemData where CharacterId = ? and ItemId = ?;");
			Query.BindInt(&CharacterId);
			Query.BindInt(&ItemId);

			if (!Query.ExecuteQuery()) { return false; }
		}
	}
	else
	{
		// 存在しないのでinsert
		Query.Close();
		if (Count == 0) { return true; }	// ０個なら何もしない。
		Query = Connection.CreateQuery("insert into ItemData values(?, ?, ?);");
		Query.BindInt(&CharacterId);
		Query.BindInt(&ItemId);
		Query.BindInt(&Count);

		if (!Query.ExecuteQuery()) { return false; }
	}

	return true;
}

// アイテムショートカット読み込み。
bool DBConnection::LoadItemShortcut(u32 CharacterId, u32 &OutItemId1, u32 &OutItemId2)
{
	MySqlQuery Query = Connection.CreateQuery("select ItemId1, ItemId2 from ItemShortcut where CharacterId = ?");

	Query.BindInt(&CharacterId);

	Query.BindResultInt(&OutItemId1);
	Query.BindResultInt(&OutItemId2);

	if (!Query.ExecuteQuery()) { return false; }
	if (!Query.Fetch())
	{
		// まだデータが存在しないので作成しておく。
		Query.Close();
		Query = Connection.CreateQuery("insert into ItemShortcut Values(?, 0, 0);");
		Query.BindInt(&CharacterId);

		if (!Query.ExecuteQuery()) { return false; }
		OutItemId1 = 0;
		OutItemId2 = 0;
	}

	return true;
}

// アイテムショートカット書き込み。
bool DBConnection::SaveItemShortcut(u32 CharacterId, u32 ItemId1, u32 ItemId2)
{
	MySqlQuery Query = Connection.CreateQuery("update ItemShortcut set ItemId1 = ?, ItemId2 = ? where CharacterId = ?;");
	Query.BindInt(&ItemId1);
	Query.BindInt(&ItemId2);
	Query.BindInt(&CharacterId);

	if (!Query.ExecuteQuery()) { return false; }
	return true;
}

// ゴールド書き込み
bool DBConnection::SaveGold(u32 CharacterId, u32 Gold)
{
	MySqlQuery Query = Connection.CreateQuery("update CharacterData set Gold = ? where CharacterId = ?");

	Query.BindInt(&Gold);
	Query.BindInt(&CharacterId);

	if (!Query.ExecuteQuery()) { return false; }

	return true;
}

// 最後にログアウトした位置を読み込み
bool DBConnection::ReadLastLogoutPosition(u32 CharacterId, u32 &OutAreaId, float &OutX, float &OutY, float &OutZ)
{
	MySqlQuery Query = Connection.CreateQuery("select LastArea, LastX, LastY, LastZ from CharacterData where CharacterId = ?");

	Query.BindInt(&CharacterId);
	Query.BindResultInt(&OutAreaId);
	Query.BindResultFloat(&OutX);
	Query.BindResultFloat(&OutY);
	Query.BindResultFloat(&OutZ);

	if (!Query.ExecuteQuery()) { return false; }
	if (!Query.Fetch()) { return false; }

	return true;
}

// スクリプトフラグをロード
bool DBConnection::LoadScriptFlags(u32 CharacterId, u32 &OutBitField1, u32 &OutBitField2, u32 &OutBitField3)
{
	MySqlQuery Query = Connection.CreateQuery("select BitField1, BitField2, BitField3 from ScriptFlags where CharacterId = ?");
	
	Query.BindInt(&CharacterId);

	Query.BindResultInt(&OutBitField1);
	Query.BindResultInt(&OutBitField2);
	Query.BindResultInt(&OutBitField3);

	if (!Query.ExecuteQuery()) { return false; }
	if (!Query.Fetch())
	{
		// 新規登録.
		MySqlQuery InsertQuery = Connection.CreateQuery("insert into ScriptFlags values(?, 0, 0, 0);");

		InsertQuery.BindInt(&CharacterId);
		if (InsertQuery.ExecuteQuery()) { return false; }
		OutBitField1 = 0;
		OutBitField2 = 0;
		OutBitField3 = 0;
	}
	return true;
}

// スクリプトフラグを保存.
bool DBConnection::SaveScriptFlags(u32 CharacterId, u32 BitField1, u32 BitField2, u32 BitField3)
{
	MySqlQuery Query = Connection.CreateQuery("update ScriptFlags set BitField1 = ?, BitField2 = ?, BitField3 = ? where CharacterId = ?");

	Query.BindInt(&BitField1);
	Query.BindInt(&BitField2);
	Query.BindInt(&BitField3);
	Query.BindInt(&CharacterId);

	if (!Query.ExecuteQuery()) { return false; }
	return true;
}

// クエストデータ読み込み
bool DBConnection::LoadQuestData(u32 CharacterId, FlexArray<QuestData> &OutDataList, u32 &OutActiveQuestId)
{
	MySqlQuery Query = Connection.CreateQuery("select QuestId, StageNo, KillCount, State, IsActive from QuestData where CharacterId = ?");
	Query.BindInt(&CharacterId);

	OutActiveQuestId = 0;

	QuestData BindData;
	u8 ActiveFlag = 0;
	Query.BindResultInt(&BindData.QuestId);
	Query.BindResultInt(&BindData.StageNo);
	Query.BindResultInt(&BindData.KillCount);
	Query.BindResultChar(&BindData.State);
	Query.BindResultChar(&ActiveFlag);
	
	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		OutDataList.PushBack(BindData);
		if (ActiveFlag)
		{
			OutActiveQuestId = BindData.QuestId;
		}
	}

	if (OutDataList.GetCurrentSize() == 0)
	{
		// クエストデータが無い場合、一番最初のメインクエストを受けている事にする。
		Query.Close();
		Query = Connection.CreateQuery("insert into QuestData Value(?, 1, 0, 0, 0, 1);");
		Query.BindInt(&CharacterId);
		if (!Query.ExecuteQuery()) { return false; }

		QuestData Data(1, 0, 0, QuestData::Active);
		OutDataList.PushBack(Data);

		OutActiveQuestId = 1;
	}

	return true;
}

// クエストデータ保存.
bool DBConnection::SaveQuestData(u32 CharacterId, u32 QuestId, u32 StageNo, u32 KillCount, u8 State)
{
	// まずは既に保存されているかどうかをチェック
	MySqlQuery Query = Connection.CreateQuery("select QuestId from QuestData where CharacterId = ? and QuestId = ?;");
	Query.BindInt(&CharacterId);
	Query.BindInt(&QuestId);
	if (!Query.ExecuteQuery()) { return false; }
	if (Query.Fetch())
	{
		// 存在するので上書き。
		Query.Close();
		Query = Connection.CreateQuery("update QuestData set StageNo = ?, KillCount = ?, State = ? where CharacterId = ? and QuestId = ?;");
		Query.BindInt(&StageNo);
		Query.BindInt(&KillCount);
		Query.BindChar(&State);
		Query.BindInt(&CharacterId);
		Query.BindInt(&QuestId);

		if (!Query.ExecuteQuery()) { return false; }
	}
	else
	{
		// 存在しないので新規追加。
		Query.Close();
		Query = Connection.CreateQuery("insert into QuestData Value(?, ?, ?, ?, ?, 0);");
		Query.BindInt(&CharacterId);
		Query.BindInt(&QuestId);
		Query.BindInt(&StageNo);
		Query.BindInt(&KillCount);
		Query.BindChar(&State);

		if (!Query.ExecuteQuery()) { return false; }
	}
	
	return true;
}

// アクティブクエストを保存.
bool DBConnection::SaveActiveQuest(u32 CharacterId, u32 QuestId)
{
	// まずは全部のフラグを下ろす。
	MySqlQuery Query = Connection.CreateQuery("update QuestData set IsActive = 0 where CharacterId = ?;");
	Query.BindInt(&CharacterId);

	if (!Query.ExecuteQuery()) { return false; }

	Query.Close();

	// 指定されたクエストＩＤをアクティブにする。
	Query = Connection.CreateQuery("update QuestData set IsActive = 1 where CharacterId = ? and QuestId = ?;");
	Query.BindInt(&CharacterId);
	Query.BindInt(&QuestId);

	if (!Query.ExecuteQuery()) { return false; }

	return true;
}

// クエストデータ破棄.
bool DBConnection::EraseQuestData(u32 CharacterId, u32 QuestId)
{
	MySqlQuery Query = Connection.CreateQuery("delete from QuestData where CharacterId = ? and QuestId = ?;");
	Query.BindInt(&CharacterId);
	Query.BindInt(&QuestId);

	if (!Query.ExecuteQuery()) { return false; }

	return true;
}

// 装備データ保存.
bool DBConnection::SaveEquipData(u32 CharacterId, u32 RightEquip, u32 LeftEquip)
{
	MySqlQuery Query = Connection.CreateQuery("update CharacterData set RightEquip = ?, LeftEquip = ? where CharacterId = ?");

	Query.BindInt(&RightEquip);
	Query.BindInt(&LeftEquip);
	Query.BindInt(&CharacterId);

	if (!Query.ExecuteQuery()) { return false; }

	return true;
}


// ユーザデータ登録.
bool DBConnection::RegisterUserData(char *pUserCode)
{
	// ユーザデータ
	MySqlQuery Query = Connection.CreateQuery("insert into UserData(UserCode) Values(?)");
	Query.BindString(pUserCode);
	if (!Query.ExecuteQuery()) { return false; }
	Query.Close();

	// キャラデータ
	MySqlQuery UserQuery = Connection.CreateQuery("select Id from UserData where UserCode = ?;");
	UserQuery.BindString(pUserCode);

	int Id = 0;
	UserQuery.BindResultInt(&Id);
	if (!UserQuery.ExecuteQuery()) { return false; }
	if (!UserQuery.Fetch()) { return false; }
	UserQuery.Close();

	return true;
}
