
#ifndef __MYSQLQUERY_H__
#define __MYSQLQUERY_H__

#ifdef _WIN32
#include <mysql.h>
#else
#include <mysql/mysql.h>
#endif

#include "MySqlBinds.h"

/**
 * MySQLクエリクラス
 */
class MySqlQuery
{

public:

	// コンストラクタ
	MySqlQuery(const shared_ptr<MYSQL> &pInConnection, const char *pInQuery);

	// デストラクタ
	~MySqlQuery();

	// int型のバインド
	void BindInt(int *pPtr);

	// 文字列のバインド
	void BindString(char *pPtr);

	// 結果のint型バインド
	void BindResultInt(int *pPtr);

	// 結果の文字列バインド
	void BindResultString(char *pPtr);

	// クエリ実行.
	bool ExecuteQuery();

	// フェッチ
	bool Fetch();

	// 閉じる
	void Close();

private:

	// クエリ
	const char *pQuery;

	// MYSQLへの接続.
	weak_ptr<MYSQL> pConnection;

	// ステートメント
	MYSQL_STMT *pStatement;

	// バインド
	MySqlBinds Binds;

	// 結果バインド
	MySqlBinds Results;

};

#endif		// #ifndef __MYSQLQUERY_H__
