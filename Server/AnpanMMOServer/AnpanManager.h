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
	typedef std::map<unsigned int, AnpanSharedPtr> AnpanMap;

public:

	// �R���X�g���N�^
	AnpanManager();

	// �f�X�g���N�^
	~AnpanManager() {}

	// ���t���[���̏���.
	void Poll();

	// �A���p������.
	void SpawnAnpan();

private:

	// �A���p�����X�g
	AnpanMap AnpanList;

	// ���̂t�t�h�c
	unsigned int NextUuid;

};

#endif		// #ifndef __ANPANMANAGER_H__
