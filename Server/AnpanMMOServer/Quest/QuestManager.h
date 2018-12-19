#ifndef __QUESTMANAGER_H__
#define __QUESTMANAGER_H__

#include "Packet/QuestData.h"
#include <boost/unordered_map.hpp>

class Client;
struct QuestStageItem;

/**
 * �N�G�X�g�Ǘ�.
 */
class QuestManager
{

private:		// �ʖ���`.

	typedef boost::unordered_map<u32, QuestData> QuestMap;
	typedef boost::unordered_map<u32, QuestData *> ActiveQuestMap;

public:

	// �R���X�g���N�^
	QuestManager(Client *pInClient);

	// �f�X�g���N�^
	~QuestManager() {}

	// �ǉ�.
	void Add(const QuestData &Data);

	// ��.
	void Accept(u32 QuestId);

	// �X�e�[�W�i�s.
	void ProgressStage(u32 QuestId);

	// �A���p�����E�Q�����B
	void OnKilledAnpan(u32 AreaId);

private:

	// �N���C�A���g
	Client *pClient;

	// �N�G�X�g�}�b�v
	QuestMap Quests;

	// �i�s���̃N�G�X�g�}�b�v
	ActiveQuestMap ActiveQuests;


	// ���݂̃X�e�[�W�����擾.
	const QuestStageItem *GetCurrentStageData(u32 QuestId) const;

};

#endif		// #ifndef __QUESTMANAGER_H__
