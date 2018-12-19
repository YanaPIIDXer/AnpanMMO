#ifndef __QUESTMANAGER_H__
#define __QUESTMANAGER_H__

#include "Packet/QuestData.h"
#include <boost/unordered_map.hpp>

class Client;

/**
 * クエスト管理.
 */
class QuestManager
{

private:		// 別名定義.

	typedef boost::unordered_map<u32, QuestData> QuestMap;

public:

	// コンストラクタ
	QuestManager(Client *pInClient);

	// デストラクタ
	~QuestManager() {}

	// 追加.
	void Add(const QuestData &Data);

	// 受注.
	void Accept(u32 QuestId);

	// ステージ進行.
	void ProgressStage(u32 QuestId);

private:

	// クライアント
	Client *pClient;

	// クエストマップ
	QuestMap Quests;

};

#endif		// #ifndef __QUESTMANAGER_H__
