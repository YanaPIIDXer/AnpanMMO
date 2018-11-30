#ifndef __ANPAN_H__
#define __ANPAN_H__

#include "Character/CharacterBase.h"
#include "AI/AnpanAI.h"
#include "Packet/CharacterType.h"

/**
 * �A���p���N���X
 */
class Anpan : public CharacterBase
{

public:

	// �R���X�g���N�^
	Anpan(const Vector3D &InPosition, int Hp, int Atk, int Def, int InExp, float InScaleRate);

	// �f�X�g���N�^
	virtual ~Anpan() {}

	// ���t���[���̏���.
	void Poll(int DeltaTime);

	// �L�����N�^�^�C�v���擾.
	virtual u8 GetCharacterType() const { return CharacterType::Enemy; }

	// �U��.
	void AttackTo(CharacterBase *pTarget);

	// �|�����Ƃ��Ɋl���ł���o���l���擾.
	int GetExp() const { return Exp; }
	
	// ���a���擾.
	float GetRadius() const { return (BaseRadius * ScaleRate); }
	
protected:

	// �_���[�W���󂯂��B
	virtual void OnDamaged(weak_ptr<CharacterBase> pAttacker, int DamageValue);

private:

	// ���a.
	static const float BaseRadius;
	
	// AI
	AnpanAI AI;

	// UUID
	u32 Uuid;

	// �|�����Ƃ��Ɋl���ł���o���l.
	int Exp;

	// �g�k�{��.
	float ScaleRate;

};

#endif		// #ifndef __ANPAN_H__
