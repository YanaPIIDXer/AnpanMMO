#ifndef __MASTERDATA_H__
#define __MASTERDATA_H__

/**
 * マスタデータクラス
 */
class MasterData : public noncopyable
{

public:

	// 読み込み
	bool Read();

private:

	// DBホスト
	static const char *DBHost;

	// DB名.
	static const char *DBName;

	// DBのユーザ名とか記述したファイル名.
	static const std::string DBDataFileName;

	// ======= Singleton ==========
public:

	static MasterData &GetInstance() { return Instance; }

private:

	MasterData() {}
	static MasterData Instance;

};

#endif		// #ifndef __MASTERDATA_H__
