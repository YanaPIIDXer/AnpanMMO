#include "stdafx.h"
#include "SkillStateAutoMove.h"
#include "Master/MasterData.h"
#include "Skill/SkillControl.h"
#include "Math/Vector3D.h"
#include "Character/CharacterBase.h"
#include "Packet/PacketSkillUseFailed.h"

const s32 SkillStateAutoMove::AutoMoveLimitTime = 10000;

// �R���X�g���N�^
SkillStateAutoMove::SkillStateAutoMove(SkillControl *pInControl)
	: SkillStateBase(pInControl)
	, ElapsedTime(0)
{
	const SkillItem *pItem = MasterData::GetInstance().GetSkillMaster().GetItem(pInControl->GetSkillId());
	SkillDistance = pItem->Distance;
	pOwner = pInControl->GetOwner();
	pTarget = pInControl->GetTarget();
}

// ���t���[���̏���.
void SkillStateAutoMove::Poll(s32 DeltaTime)
{
	ElapsedTime += DeltaTime;
	if (ElapsedTime >= AutoMoveLimitTime)
	{
		// ���Ԑ؂�ɂ��X�L�����f.
		GetControl()->Cancel(PacketSkillUseFailed::Cancel);
		return;
	}

	Vector3D Dist = pTarget->GetPosition() - pOwner->GetPosition();
	if (Dist.GetSizeSq() <= SkillDistance * SkillDistance)
	{
		// ����.
		GetControl()->Activate();
	}
}
