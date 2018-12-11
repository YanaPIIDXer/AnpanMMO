#include "stdafx.h"
#include "SkillStateCast.h"
#include "Master/MasterData.h"
#include "Skill/SkillControl.h"
#include "Character/CharacterBase.h"
#include "Packet/PacketSkillCast.h"

// �R���X�g���N�^
SkillStateCast::SkillStateCast(SkillControl *pInControl)
	: SkillStateBase(pInControl)
{
	const SkillItem *pItem = MasterData::GetInstance().GetSkillMaster().GetItem(pInControl->GetSkillId());
	CastTime = pItem->CastTime * 1000;
}

// State�J�n���̏���.
void SkillStateCast::BeginState()
{
	CharacterBase *pOwner = GetControl()->GetOwner();
	AreaPtr pArea = pOwner->GetArea();

	PacketSkillCast Packet(GetControl()->GetSkillId());
	pArea.lock()->BroadcastPacket(&Packet);
}

// ���t���[���̏���.
void SkillStateCast::Poll(s32 DeltaTime)
{
	CastTime -= DeltaTime;
	if (CastTime <= 0)
	{
		GetControl()->CastFinished();
	}
}
