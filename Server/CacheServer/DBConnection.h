#ifndef __DBCONNECTION_H__
#define __DBCONNECTION_H__

#include "MySQL/MySqlConnection.h"
#include "FlexArray.h"

class ItemData;
class QuestData;

/**
 * DB接続クラス
 */
class DBConnection : noncopyable
{

public:

	// 開く.
	bool Open();

	// ユーザデータ読み込み
	bool LoadUserData(char *pUserCode, int &OutId, bool &bOutIsBunned);

	// キャラクタデータが存在するか？
	bool IsExistCharacter(int Id, bool &OutResult);

	// キャラクタＩＤを取得.
	bool GetCharacterId(int Id, u32 &OutCharacterId);

	// キャラクタデータ登録.
	bool RegisterCharacterData(u32 Id, char *pCharacterName, u8 Job);

	// キャラクタパラメータ読み込み
	bool LoadCharacterParameter(int Id, u32 &OutCharacterId, std::string &OutName, u8 &OutJob, u32 &OutLevel, u32 &OutExp, u32 &OutGold, bool &bOutIsGM, u32 &OutRightEquip, u32 &OutLeftEquip);

	// キャラクタパラメータ書き込み
	bool SaveCharacterParameter(u32 CharacterId, u32 Level, u32 Exp, int AreaId, float X, float Y, float Z);

	// スキルリスト読み込み
	bool LoadSkillList(u32 CharacterId, u32 &OutSkill1, u32 &OutSkill2, u32 &OutSkill3, u32 &OutSkill4);

	// スキルリスト保存.
	bool SaveSkillList(u32 CharacterId, u32 Skill1, u32 Skill2, u32 Skill3, u32 Skill4);

	// スキルツリー読み込み
	bool LoadSkillTree(u32 CharacterId, FlexArray<u32> &OutOpenedList);

	// スキルツリー保存.
	bool SaveSkillTree(u32 CharacterId, u32 NodeId);

	// アイテムリスト読み込み
	bool LoadItemList(u32 CharacterId, FlexArray<ItemData> &OutItemList);

	// アイテム数変化.
	bool ChangeItemCount(u32 CharacterId, u32 ItemId, u32 Count);

	// アイテムショートカット読み込み。
	bool LoadItemShortcut(u32 CharacterId, u32 &OutItemId1, u32 &OutItemId2);

	// アイテムショートカット書き込み。
	bool SaveItemShortcut(u32 CharacterId, u32 ItemId1, u32 ItemId2);

	// ゴールド書き込み
	bool SaveGold(u32 CharacterId, u32 Gold);

	// 最後にログアウトした位置を読み込み
	bool ReadLastLogoutPosition(u32 CharacterId, u32 &OutAreaId, float &OutX, float &OutY, float &OutZ);

	// スクリプトフラグをロード
	bool LoadScriptFlags(u32 CharacterId, u32 &OutBitField1, u32 &OutBitField2, u32 &OutBitField3);

	// スクリプトフラグを保存.
	bool SaveScriptFlags(u32 CharacterId, u32 BitField1, u32 BitField2, u32 BitField3);

	// クエストデータ読み込み。
	bool LoadQuestData(u32 CharacterId, FlexArray<QuestData> &OutDataList, u32 &OutActiveQuestId);

	// クエストデータ保存.
	bool SaveQuestData(u32 CharacterId, u32 QuestId, u32 StageNo, u32 KillCount, u8 State);

	// アクティブクエストを保存.
	bool SaveActiveQuest(u32 CharacterId, u32 QuestId);

	// クエストデータ破棄.
	bool EraseQuestData(u32 CharacterId, u32 QuestId);

	// 装備データ保存.
	bool SaveEquipData(u32 CharacterId, u32 RightEquip, u32 LeftEquip);

private:

	// ユーザ情報を格納したファイル名.
	static const std::string UserDataFileName;

	// DBのホスト
	static const char *DBHost;

	// データベース名.
	static const char *DBName;

	// 接続.
	MySqlConnection Connection;


	// ユーザデータ登録.
	bool RegisterUserData(char *pUserCode);

	// ======== Singleton ===========
public:

	static DBConnection &GetInstance() { return Instance; }

private:

	DBConnection() {}
	static DBConnection Instance;

};

#endif		// #ifndef __DBCONNECTION_H__
