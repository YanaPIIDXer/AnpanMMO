#ifndef __MYSQLCONNECTION_H__
#define __MYSQLCONNECTION_H__

#ifdef _WIN32
#include <mysql.h>
#else
#include <mysql/mysql.h>
#endif

#include "MySqlQuery.h"

/**
 * MySQL接続クラス
 */
class MySqlConnection
{

public:

	// コンストラクタ
	MySqlConnection();

	// デストラクタ
	~MySqlConnection();

	// 接続.
	bool Connect(const char *pHost, const char *pUserName, const char *pPassword, const char *pDBName);

	// 単純なクエリ実行.
	bool SimpleQuery(const char *pQuery) const;

	// クエリ生成.
	MySqlQuery CreateQuery(const char *pQuery) const;

	// 閉じる.
	void Close();

private:

	// MySQLへの接続.
	shared_ptr<MYSQL> pConnection;

};

#endif		// #ifndef __MYSQLCONNECTION_H__
