#ifndef __AREA_H__
#define __AREA_H__

#include <boost/enable_shared_from_this.hpp>
#include "PlayerManager.h"
#include "AnpanManager.h"
#include "HeightMap.h"

struct AreaItem;
class PacketBase;

class Area;
typedef weak_ptr<Area> AreaPtr;

/**
 * �G���A�N���X
 */
class Area : public enable_shared_from_this<Area>
{

public:

	// �R���X�g���N�^
	Area(const AreaItem *pItem);

	// �f�X�g���N�^
	virtual ~Area() {}

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
	void BroadcastPacket(PacketBase *pPacket);

	// ID�擾.
	u32 GetId() const { return Id; }

	// �������擾.
	float GetHeight(float X, float Y) const;
	
	// �ړ��\���ǂ������`�F�b�N
	bool CheckMovable(const Vector3D &Start, const Vector3D &End, float ClimbableHeight, Vector3D &OutHit) const;
	
private:

	// ID
	u32 Id;

	// �v���C���[�Ǘ�.
	PlayerManager PlayerMgr;

	// �A���p���Ǘ�.
	AnpanManager AnpanMgr;

	// �n�C�g�}�b�v
	HeightMap HeightData;


	// �A���p�����������ꂽ�B
	void OnSpawnAnpan(u32 Uuid, AnpanPtr pAnpan);

};

#endif		// #ifndef __AREA_H__
