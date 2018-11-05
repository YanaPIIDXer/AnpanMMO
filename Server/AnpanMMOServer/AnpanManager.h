#ifndef __ANPANMANAGER_H__
#define __ANPANMANAGER_H__

#include <map>
#include "Character/Anpan.h"

typedef weak_ptr<Anpan> AnpanPtr;

/**
 * �A���p���Ǘ��N���X
 */
class AnpanManager
{

private:		// �ʖ���`.

	typedef shared_ptr<Anpan> AnpanSharedPtr;

public:

	// �R���X�g���N�^
	AnpanManager();

	// �f�X�g���N�^
	~AnpanManager() {}

	// �A���p������.
	void SpawnAnpan();

private:

	// �A���p�����X�g
	std::map<unsigned int, AnpanSharedPtr> AnpanList;

	// ���̂t�t�h�c
	unsigned int NextUuid;

};

#endif		// #ifndef __ANPANMANAGER_H__
