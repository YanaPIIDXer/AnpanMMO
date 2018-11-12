#ifndef __MYSQLBINDS_H__
#define __MYSQLBINDS_H__

#ifdef _WIN32
#include <mysql.h>
#else
#include <mysql/mysql.h>
#endif

#include <vector>

/**
 * バインド
 */
class MySqlBinds
{

public:

	// コンストラクタ
	MySqlBinds();

	// デストラクタ
	~MySqlBinds();

	// int追加.
	void AddInt(int *pPtr);

	// unsigned int追加。
	void AddInt(unsigned int *pPtr);

	// float追加.
	void AddFloat(float *pPtr);

	// 文字列追加.
	void AddString(char *pPtr);

	// 取得.
	MYSQL_BIND *Get() { return pBinds; }

private:

	// バインド
	MYSQL_BIND *pBinds;

	// 配列長.
	int Length;

	// 領域拡張.
	void Reallocate();

};

#endif		// #ifndef __MYSQLBINDS_H__

