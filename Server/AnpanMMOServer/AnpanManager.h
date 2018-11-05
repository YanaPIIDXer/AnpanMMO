#ifndef __ANPANMANAGER_H__
#define __ANPANMANAGER_H__

#include <map>
#include <boost/function.hpp>
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
	typedef boost::function<void(AnpanPtr)> SpawnFunc;

public:

	// �R���X�g���N�^
	AnpanManager();

	// �f�X�g���N�^
	~AnpanManager() {}

	// ���t���[���̏���.
	void Poll();

	// �A���p������.
	void SpawnAnpan();

	// �������R�[���o�b�N��ݒ�.
	void SetSpawnCallback(const SpawnFunc &InOnSpawn) { OnSpawn = InOnSpawn; }

private:

	// �A���p�����X�g
	AnpanMap AnpanList;

	// ���̂t�t�h�c
	unsigned int NextUuid;

	// �������R�[���o�b�N
	SpawnFunc OnSpawn;

};

#endif		// #ifndef __ANPANMANAGER_H__
