
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

	// unsigned int型のバインド
	void BindInt(unsigned int *pPtr);

	// short型のバインド
	void BindShort(short *pPtr);

	// unsigned short型のバインド
	void BindShort(unsigned short *pPtr);

	// char型のバインド
	void BindChar(char *pPtr);

	// unsigned char型のバインド
	void BindChar(unsigned char *pPtr);

	// float型のバインド
	void BindFloat(float *pPtr);

	// 文字列のバインド
	void BindString(char *pPtr);

	// 結果のint型バインド
	void BindResultInt(int *pPtr);

	// 結果のunsigned int型のバインド
	void BindResultInt(unsigned int *pPtr);

	// 結果のshort型のバインド
	void BindResultShort(short *pPtr);

	// 結果のunsigned short型のバインド
	void BindResultShort(unsigned short *pPtr);

	// 結果のchar型のバインド
	void BindResultChar(char *pPtr);

	// 結果のunsigned char型のバインド
	void BindResultChar(unsigned char *pPtr);

	// 結果のfloat型バインド
	void BindResultFloat(float *pPtr);

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
