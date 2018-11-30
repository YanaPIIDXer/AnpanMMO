#ifndef __MASTERDATA_H__
#define __MASTERDATA_H__

#include "AreaMaster.h"
#include "WarpDataMaster.h"
#include "AnpanMaster.h"
#include "AnpanPopAreaMaster.h"
#include "AnpanPopDataMaster.h"

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

	// アンパンマスタ取得.
	const AnpanMaster &GetAnpanMaster() { return Anpan; }

	// アンパンポップエリアマスタ取得.
	const AnpanPopAreaMaster &GetAnpanPopAreaMaster() { return AnpanPopArea; }

	// アンパンポップデータマスタ取得.
	const AnpanPopDataMaster &GetAnpanPopDataMaster() { return AnpanPopData; }

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

	// アンパンマスタ
	AnpanMaster Anpan;

	// アンパンポップエリアマスタ
	AnpanPopAreaMaster AnpanPopArea;

	// アンパンポップデータマスタ
	AnpanPopDataMaster AnpanPopData;

	// ======= Singleton ==========
public:

	static MasterData &GetInstance() { return Instance; }

private:

	MasterData() {}
	static MasterData Instance;

};

#endif		// #ifndef __MASTERDATA_H__
