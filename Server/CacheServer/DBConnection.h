#ifndef __DBCONNECTION_H__
#define __DBCONNECTION_H__

#include "MySQL/MySqlConnection.h"

/**
 * DB接続クラス
 */
class DBConnection : noncopyable
{

public:

	// 開く.
	bool Open();

	// ユーザデータ読み込み
	bool LoadUserData(char *pUserCode, int &OutId);

	// キャラクタデータが存在するか？
	bool IsExistCharacter(int Id, bool &OutResult);

	// キャラクタＩＤを取得.
	bool GetCharacterId(int Id, u32 &OutCharacterId);

	// キャラクタデータ登録.
	bool RegisterCharacterData(u32 Id, char *pCharacterName, u8 Job);

	// キャラクタパラメータ読み込み
	bool LoadCharacterParameter(int Id, u32 &OutCharacterId, std::string &OutName, u8 &OutJob, u32 &OutLevel, int &OutMaxHp, int &OutAtk, int &OutDef, int &OutExp, u32 &OutGold);

	// キャラクタパラメータ書き込み
	bool SaveCharacterParameter(u32 CharacterId, u32 Level, int MaxHp, int Atk, int Def, int Exp, int AreaId, float X, float Y, float Z);

	// スキルリスト読み込み
	bool LoadSkillList(u32 CharacterId, u32 &OutNormalAttackId, u32 &OutSkill1, u32 &OutSkill2, u32 &OutSkill3, u32 &OutSkill4);

	// ゴールド書き込み
	bool SaveGold(u32 CharacterId, u32 Gold);

	// 最後にログアウトした位置を読み込み
	bool ReadLastLogoutPosition(u32 CharacterId, u32 &OutAreaId, float &OutX, float &OutY, float &OutZ);

	// スクリプトフラグをロード
	bool LoadScriptFlags(u32 CharacterId, u32 &OutBitField1, u32 &OutBitField2, u32 &OutBitField3);

	// スクリプトフラグを保存.
	bool SaveScriptFlags(u32 CharacterId, u32 BitField1, u32 BitField2, u32 BitField3);

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
