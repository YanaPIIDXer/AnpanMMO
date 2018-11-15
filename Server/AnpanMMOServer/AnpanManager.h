#ifndef __ANPANMANAGER_H__
#define __ANPANMANAGER_H__

#include <boost/unordered_map.hpp>
#include <boost/function.hpp>
#include "Character/Anpan/Anpan.h"

typedef weak_ptr<Anpan> AnpanPtr;
class PacketAnpanList;

/**
 * �A���p���Ǘ��N���X
 */
class AnpanManager
{

private:		// �ʖ���`.

	typedef shared_ptr<Anpan> AnpanSharedPtr;
	typedef unordered_map<unsigned int, AnpanSharedPtr> AnpanMap;
	typedef boost::function<void(unsigned int, AnpanPtr)> SpawnFunc;

public:

	// �R���X�g���N�^
	AnpanManager();

	// �f�X�g���N�^
	~AnpanManager() {}

	// ������.
	void Initialize(int InMinHp, int InMaxHp, int InMinAtk, int InMaxAtk, int InMinDef, int InMaxDef, int InMinExp, int InMaxExp);

	// ���t���[���̏���.
	void Poll(int DeltaTime);

	// �擾.
	AnpanPtr Get(u32 Uuid) const;

	// �������R�[���o�b�N��ݒ�.
	void SetSpawnCallback(const SpawnFunc &InOnSpawn) { OnSpawn = InOnSpawn; }

	// �A���p�����X�g�p�P�b�g�𐶐�.
	void MakeListPacket(PacketAnpanList &Packet);

private:

	// �����C���^�[�o��
	static const int SpawnInterval;

	// �A���p���̍ő吔.
	static const int AnpanMax;

	// �A���p�����X�g
	AnpanMap AnpanList;

	// ���̂t�t�h�c
	unsigned int NextUuid;

	// �������R�[���o�b�N
	SpawnFunc OnSpawn;

	// �����܂ł̎���.
	int SpawnTime;

	// �ŏ��g�o
	int MinHp;

	// �ő�g�o
	int MaxHp;

	// �ŏ��U����.
	int MinAtk;

	// �ő�U����.
	int MaxAtk;

	// �ŏ��h���.
	int MinDef;

	// �ő�h���.
	int MaxDef;

	// �ŏ��o���l.
	int MinExp;

	// �ő�o���l.
	int MaxExp;


	// �A���p������.
	void SpawnAnpan();

	// �X�V����.
	void Update(int DeltaTime);

};

#endif		// #ifndef __ANPANMANAGER_H__
