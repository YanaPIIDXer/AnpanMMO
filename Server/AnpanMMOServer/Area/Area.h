#ifndef __AREA_H__
#define __AREA_H__

#include "PlayerManager.h"
#include "AnpanManager.h"

struct AreaItem;

/**
 * �G���A�N���X
 */
class Area
{

public:

	// �R���X�g���N�^
	Area(const AreaItem *pItem);

	// �f�X�g���N�^
	~Area() {}

	// ���t���[���̏���.
	void Poll(int DeltaTime);
	
private:

	// �v���C���[�Ǘ�.
	PlayerManager PlayerMgr;

	// �A���p���Ǘ�.
	AnpanManager AnpanMgr;


	// �A���p�����������ꂽ�B
	void OnSpawnAnpan(u32 Uuid, AnpanPtr pAnpan);

};

#endif		// #ifndef __AREA_H__
