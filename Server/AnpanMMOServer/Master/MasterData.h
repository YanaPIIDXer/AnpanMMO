#ifndef __MASTERDATA_H__
#define __MASTERDATA_H__

#include "AreaMaster.h"
#include "WarpDataMaster.h"
#include "AnpanPopAreaMaster.h"

/**
 * マスタデータクラス
 */
class MasterData : public noncopyable
{

public:

	// 読み込み
	bool Read();

	// エリアマスタ取得.
	const AreaMaster &GetAreaMaster() { return Area; }

	// ワープデータマスタ取得.
	const WarpDataMaster &GetWarpDataMaster() { return WarpData; }

	// アンパンポップエリアマスタ取得.
	const AnpanPopAreaMaster &GetAnpanPopAreaMaster() { return AnpanPopArea; }

private:

	// DBホスト
	static const char *DBHost;

	// DB名.
	static const char *DBName;

	// DBのユーザ名とか記述したファイル名.
	static const std::string DBDataFileName;

	// エリアマスタ
	AreaMaster Area;

	// ワープデータマスタ
	WarpDataMaster WarpData;

	// アンパンポップエリアマスタ
	AnpanPopAreaMaster AnpanPopArea;

	// ======= Singleton ==========
public:

	static MasterData &GetInstance() { return Instance; }

private:

	MasterData() {}
	static MasterData Instance;

};

#endif		// #ifndef __MASTERDATA_H__
