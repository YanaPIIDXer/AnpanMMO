#ifndef __ANPANMANAGER_H__
#define __ANPANMANAGER_H__

#include <vector>
#include "Character/Anpan.h"

/**
 * アンパン管理クラス
 */
class AnpanManager
{

public:

	// コンストラクタ
	AnpanManager();

	// デストラクタ
	~AnpanManager() {}

	// アンパン生成.
	void SpawnAnpan();

private:

	// アンパンリスト
	std::vector<Anpan> AnpanList;

};

#endif		// #ifndef __ANPANMANAGER_H__
