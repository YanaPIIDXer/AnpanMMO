#ifndef __AREABASE_H__
#define __AREABASE_H__

#include <boost/enable_shared_from_this.hpp>
#include "PlayerManager.h"
#include "AnpanManager.h"
#include "HeightMap.h"

struct AreaItem;
class PacketBase;

/**
 * �G���A���N���X
 */
class AreaBase : public enable_shared_from_this<AreaBase>
{

public:

	// �R���X�g���N�^
	AreaBase(const AreaItem *pItem);

	// �f�X�g���N�^
	virtual ~AreaBase() {}

	// ���t���[���̏���.
	void Poll(int DeltaTime);

	// �v���C���[�L�����̒ǉ�.
	void AddPlayerCharacter(const PlayerCharacterPtr &pPlayer);

	// �v���C���[�L�����폜,
	void RemovePlayerCharacter(u32 Uuid);

	// �ړ�����M�����B
	void OnRecvMove(u32 Uuid, float X, float Y, float Z, float Rotation);

	// �U������M�����B
	void OnRecvAttack(u32 AttackerUuid, u32 DefencerUuid);

	// �p�P�b�g�̃u���[�h�L���X�g
	void BroadcastPacket(PacketBase *pPacket, Client *pIgnoreClient = NULL);

	// �͈͂��w�肵���p�P�b�g�̃u���[�h�L���X�g
	void BroadcastPacketWithRange(PacketBase *pPacket, const Vector3D &Center, float Range, Client *pIgnoreClient = NULL);

	// �������擾.
	float GetHeight(float X, float Y) const;

	// �ړ��\���ǂ������`�F�b�N
	bool CheckMovable(const Vector3D &Start, const Vector3D &End, float ClimbableHeight, Vector3D &OutHit) const;

	// ID�擾.
	virtual u32 GetId() const = 0;

	// �����\���H
	virtual bool IsAbleDelete() const = 0;

	// �C���X�^���X�G���A���H
	virtual bool IsInstance() const { return false; }

protected:

	// �v���C���[�Ǘ�.
	PlayerManager PlayerMgr;

	// �A���p���Ǘ�.
	AnpanManager AnpanMgr;

private:

	// �n�C�g�}�b�v
	HeightMap HeightData;


	// �A���p�����������ꂽ�B
	void OnSpawnAnpan(u32 Uuid, AnpanPtr pAnpan);

};

#endif		// #ifndef __AREABASE_H__
