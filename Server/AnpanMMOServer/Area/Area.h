#ifndef __AREA_H__
#define __AREA_H__

#include "PlayerManager.h"
#include "AnpanManager.h"

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
	~Area() {}

	// ���t���[���̏���.
	void Poll(int DeltaTime);

	// �v���C���[�L�����̒ǉ�.
	void AddPlayerCharacter(const PlayerCharacterPtr &pPlayer);

	// �v���C���[�L�����폜,
	void RemovePlayerCharacter(u32 Uuid);

	// �U������M�����B
	void OnRecvAttack(u32 AttackerUuid, u32 DefencerUuid);
	
	// �p�P�b�g�̃u���[�h�L���X�g
	void BroadcastPacket(PacketBase *pPacket);
	
private:

	// �v���C���[�Ǘ�.
	PlayerManager PlayerMgr;

	// �A���p���Ǘ�.
	AnpanManager AnpanMgr;


	// �A���p�����������ꂽ�B
	void OnSpawnAnpan(u32 Uuid, AnpanPtr pAnpan);

};

#endif		// #ifndef __AREA_H__
