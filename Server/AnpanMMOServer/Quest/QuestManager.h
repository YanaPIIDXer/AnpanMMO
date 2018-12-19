#ifndef __QUESTMANAGER_H__
#define __QUESTMANAGER_H__

#include "Packet/QuestData.h"
#include <boost/unordered_map.hpp>

/**
 * �N�G�X�g�Ǘ�.
 */
class QuestManager
{

private:		// �ʖ���`.

	typedef boost::unordered_map<u32, QuestData> QuestMap;

public:

	// �R���X�g���N�^
	QuestManager();

	// �f�X�g���N�^
	~QuestManager() {}

	// �ǉ�.
	void Add(const QuestData &Data);

private:

	// �N�G�X�g�}�b�v
	QuestMap Quests;

};

#endif		// #ifndef __QUESTMANAGER_H__
