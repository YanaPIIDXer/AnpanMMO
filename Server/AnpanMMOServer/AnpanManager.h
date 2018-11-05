#ifndef __ANPANMANAGER_H__
#define __ANPANMANAGER_H__

#include <map>
#include "Character/Anpan.h"

typedef weak_ptr<Anpan> AnpanPtr;

/**
 * アンパン管理クラス
 */
class AnpanManager
{

private:		// 別名定義.

	typedef shared_ptr<Anpan> AnpanSharedPtr;
	typedef std::map<unsigned int, AnpanSharedPtr> AnpanMap;

public:

	// コンストラクタ
	AnpanManager();

	// デストラクタ
	~AnpanManager() {}

	// 毎フレームの処理.
	void Poll();

	// アンパン生成.
	void SpawnAnpan();

private:

	// アンパンリスト
	AnpanMap AnpanList;

	// 次のＵＵＩＤ
	unsigned int NextUuid;

};

#endif		// #ifndef __ANPANMANAGER_H__
