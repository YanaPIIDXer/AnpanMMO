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
	Anpan(const Vector3D &InPosition, u32 InMasterId, int Hp, int Atk, int Def, int InExp, float InScaleRate, u32 InDropId);

	// �f�X�g���N�^
	virtual ~Anpan() {}

	// �L�����N�^�^�C�v���擾.
	virtual u8 GetCharacterType() const { return CharacterType::Enemy; }

	// �U��.
	void AttackTo(CharacterPtr pTarget, u32 SkillId);

	// �|�����Ƃ��Ɋl���ł���o���l���擾.
	int GetExp() const { return Exp; }
	
	// ���a���擾.
	float GetRadius() const { return (BaseRadius * ScaleRate); }

	// �}�X�^�h�c���擾.
	u32 GetMasterId() const { return MasterId; }

	// �h���b�v�h�c���擾.
	u32 GetDropId() const { return DropId; }
	
protected:

	// ���t���[���̏���.
	virtual void Update(int DeltaTime);

	// �_���[�W���󂯂��B
	virtual void OnDamaged(weak_ptr<CharacterBase> pAttacker, int DamageValue);

private:

	// ���a.
	static const float BaseRadius;
	
	// AI
	AnpanAI AI;

	// �}�X�^�h�c
	u32 MasterId;

	// �|�����Ƃ��Ɋl���ł���o���l.
	int Exp;

	// �g�k�{��.
	float ScaleRate;

	// �h���b�v�h�c
	u32 DropId;

};

#endif		// #ifndef __ANPAN_H__
