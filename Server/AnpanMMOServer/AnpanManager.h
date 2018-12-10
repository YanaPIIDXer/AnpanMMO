#ifndef __ANPANMANAGER_H__
#define __ANPANMANAGER_H__

#include <boost/unordered_map.hpp>
#include <boost/function.hpp>
#include "WeakPtrDefine.h"

class PacketAnpanList;
class AnpanPopArea;
class Vector3D;

/**
 * �A���p���Ǘ��N���X
 */
class AnpanManager
{

private:		// �ʖ���`.

	typedef shared_ptr<Anpan> AnpanSharedPtr;
	typedef unordered_map<unsigned int, AnpanSharedPtr> AnpanMap;
	typedef boost::function<void(unsigned int, AnpanPtr)> SpawnFunc;
	typedef std::vector<AnpanPopArea *> AnpanPopAreaList;

public:

	// �R���X�g���N�^
	AnpanManager();

	// �f�X�g���N�^
	~AnpanManager();

	// ������.
	void Initialize(u32 AreaId);

	// ���t���[���̏���.
	void Poll(int DeltaTime);

	// �擾.
	AnpanPtr Get(u32 Uuid) const;

	// �������R�[���o�b�N��ݒ�.
	void SetSpawnCallback(const SpawnFunc &InOnSpawn) { OnSpawn = InOnSpawn; }

	// �A���p�����X�g�p�P�b�g�𐶐�.
	void MakeListPacket(PacketAnpanList &Packet);

	// �A���p���̐����擾.
	u32 GetCount() const { return AnpanList.size(); }

	// �O������Spawn������B
	void Spawn(u32 MasterId, const Vector3D &Position);

	// CharacterPtr�Ƃ��đS�擾.
	void GetAllAsCharacterPtr(std::vector<CharacterPtr> &OutList) const;

private:

	// �A���p�����X�g
	AnpanMap AnpanList;

	// ���̂t�t�h�c
	unsigned int NextUuid;

	// �������R�[���o�b�N
	SpawnFunc OnSpawn;

	// �|�b�v�G���A���X�g
	AnpanPopAreaList PopAreaList;


	// �A���p������.
	void SpawnAnpan(AnpanSharedPtr pAnpan);

	// �X�V����.
	void Update(int DeltaTime);

};

#endif		// #ifndef __ANPANMANAGER_H__
