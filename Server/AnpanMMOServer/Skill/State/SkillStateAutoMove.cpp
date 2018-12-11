#include "stdafx.h"
#include "SkillStateAutoMove.h"
#include "Master/MasterData.h"
#include "Skill/SkillControl.h"
#include "Math/Vector3D.h"
#include "Character/CharacterBase.h"
#include "Packet/PacketSkillUseFailed.h"

const s32 SkillStateAutoMove::AutoMoveLimitTime = 10000;

// コンストラクタ
SkillStateAutoMove::SkillStateAutoMove(SkillControl *pInControl)
	: SkillStateBase(pInControl)
	, ElapsedTime(0)
{
	const SkillItem *pItem = MasterData::GetInstance().GetSkillMaster().GetItem(pInControl->GetSkillId());
	SkillDistance = pItem->Distance;
	pOwner = pInControl->GetOwner();
	pTarget = pInControl->GetTarget();
}

// 毎フレームの処理.
void SkillStateAutoMove::Poll(s32 DeltaTime)
{
	ElapsedTime += DeltaTime;
	if (ElapsedTime >= AutoMoveLimitTime)
	{
		// 時間切れによるスキル中断.
		GetControl()->Cancel(PacketSkillUseFailed::Cancel);
		return;
	}

	Vector3D Dist = pTarget->GetPosition() - pOwner->GetPosition();
	if (Dist.GetSizeSq() <= SkillDistance * SkillDistance)
	{
		// 発動.
		GetControl()->Activate();
	}
}
