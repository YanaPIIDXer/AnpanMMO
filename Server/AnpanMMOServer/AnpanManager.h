#ifndef __ANPANMANAGER_H__
#define __ANPANMANAGER_H__

#include <boost/unordered_map.hpp>
#include <boost/function.hpp>

class Anpan;
typedef weak_ptr<Anpan> AnpanPtr;
class PacketAnpanList;
class AnpanPopArea;

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
