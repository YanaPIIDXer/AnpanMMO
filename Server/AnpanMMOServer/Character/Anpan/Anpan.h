#ifndef __ANPAN_H__
#define __ANPAN_H__

#include "Character/CharacterBase.h"
#include "AI/AnpanAI.h"

/**
 * �A���p���N���X
 */
class Anpan : public CharacterBase
{

public:

	// �R���X�g���N�^
	Anpan(const Vector2D &InPosition, int Hp, int Atk, int Def);

	// �f�X�g���N�^
	virtual ~Anpan() {}

	// ���t���[���̏���.
	void Poll(int DeltaTime);

	// UUID���Z�b�g�B
	void SetUuid(u32 InUuid) { Uuid = InUuid; }

	// UUID���擾.
	u32 GetUuid() const { return Uuid; }

private:

	// AI
	AnpanAI AI;

	// UUID
	u32 Uuid;

};

#endif		// #ifndef __ANPAN_H__
