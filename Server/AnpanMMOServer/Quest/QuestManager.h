#ifndef __QUESTMANAGER_H__
#define __QUESTMANAGER_H__

#include "Packet/QuestData.h"
#include <boost/unordered_map.hpp>

class Client;
struct QuestStageItem;

/**
 * クエスト管理.
 */
class QuestManager
{

private:		// 別名定義.

	typedef boost::unordered_map<u32, QuestData> QuestMap;
	typedef boost::unordered_map<u32, QuestData *> ActiveQuestMap;

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

	// アンパンを殺害した。
	void OnKilledAnpan(u32 AreaId);

private:

	// クライアント
	Client *pClient;

	// クエストマップ
	QuestMap Quests;

	// 進行中のクエストマップ
	ActiveQuestMap ActiveQuests;


	// 現在のステージ情報を取得.
	const QuestStageItem *GetCurrentStageData(u32 QuestId) const;

};

#endif		// #ifndef __QUESTMANAGER_H__
