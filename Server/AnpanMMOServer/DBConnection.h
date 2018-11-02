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
	bool LoadUserData(char *pUserName, char *pPassWord, int &OutId);

private:

	// ユーザ情報を格納したファイル名.
	static const std::string UserDataFileName;

	// DBのホスト
	static const char *DBHost;

	// データベース名.
	static const char *DBName;

	// 接続.
	MySqlConnection Connection;

	// ======== Singleton ===========
public:

	static DBConnection &GetInstance() { return Instance; }

private:

	DBConnection() {}
	static DBConnection Instance;

};

#endif		// #ifndef __DBCONNECTION_H__
