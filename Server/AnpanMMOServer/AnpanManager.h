#ifndef __ANPANMANAGER_H__
#define __ANPANMANAGER_H__

#include <vector>
#include "Character/Anpan.h"

/**
 * �A���p���Ǘ��N���X
 */
class AnpanManager
{

public:

	// �R���X�g���N�^
	AnpanManager();

	// �f�X�g���N�^
	~AnpanManager() {}

	// �A���p������.
	void SpawnAnpan();

private:

	// �A���p�����X�g
	std::vector<Anpan> AnpanList;

};

#endif		// #ifndef __ANPANMANAGER_H__
