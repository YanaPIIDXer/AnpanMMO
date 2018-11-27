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

	// キャラクタデータ登録.
	bool RegisterCharacterData(u32 Id, char *pCharacterName);

	// キャラクタパラメータ読み込み
	bool LoadCharacterParameter(int Id, std::string &OutName, int &OutMaxHp, int &OutAtk, int &OutDef, int &OutExp);

	// キャラクタパラメータ書き込み
	bool SaveCharacterParameter(int Id, int MaxHp, int Atk, int Def, int Exp, int AreaId, float X, float Y, float Z);

	// 最後にログアウトした位置を読み込み
	bool ReadLastLogoutPosition(int Id, u32 &OutAreaId, float &OutX, float &OutY, float &OutZ);

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
