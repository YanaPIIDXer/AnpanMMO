#ifndef __QUESTMANAGER_H__
#define __QUESTMANAGER_H__

#include "Packet/QuestData.h"
#include <boost/unordered_map.hpp>

/**
 * クエスト管理.
 */
class QuestManager
{

private:		// 別名定義.

	typedef boost::unordered_map<u32, QuestData> QuestMap;

public:

	// コンストラクタ
	QuestManager();

	// デストラクタ
	~QuestManager() {}

	// 追加.
	void Add(const QuestData &Data);

private:

	// クエストマップ
	QuestMap Quests;

};

#endif		// #ifndef __QUESTMANAGER_H__
