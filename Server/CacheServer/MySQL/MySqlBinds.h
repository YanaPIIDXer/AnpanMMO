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

	// short追加.
	void AddShort(short *pPtr);

	// unsigned short追加.
	void AddShort(unsigned short *pPtr);

	// char追加.
	void AddChar(char *pPtr);

	// unsigned char追加.
	void AddChar(unsigned char *pPtr);

	// float追加.
	void AddFloat(float *pPtr);

	// 文字列追加.
	void AddString(char *pPtr, bool bForResult);

	// ワイド文字列追加.
	void AddWString(wchar_t *pPtr, bool bForResult);

	// 取得.
	MYSQL_BIND *Get() { return pBinds; }

private:

	// String型のバッファ長.
	static const int StringBufferLength;

	// バインド
	MYSQL_BIND *pBinds;

	// 配列長.
	int Length;

	// 領域拡張.
	void Reallocate();

};

#endif		// #ifndef __MYSQLBINDS_H__

