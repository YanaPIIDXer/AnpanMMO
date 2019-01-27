/**
 * @file AnpanAIStateActive.cpp
 * @brief アンパンＡＩステート：アクティブ状態
 * @author YanaP
 */
#include "stdafx.h"
#include "AnpanAIStateActive.h"
#include "Character/Anpan/AI/AnpanAI.h"
#include "AnpanAIStateNonActive.h"
#include "Character/CharacterBase.h"
#include "Character/Anpan/Anpan.h"
#include "Character/Anpan/AI/AIGenerator.h"
#include "Master/MasterData.h"
#include "Math/MathUtil.h"
#include <math.h>

// コンストラクタ
AnpanAIStateActive::AnpanAIStateActive(Anpan *pInParent)
	: AnpanAIStateBase(pInParent)
	, WaitTimer(0)
	, bInitializedAction(false)
	, SkillDistance(0.0f)
{
	pCurrentTarget.reset();
	pSkillTarget.reset();
	pCurrentAction = AIGenerator::GetInstance().Get(pInParent->GetAIId());
}


// 更新.
void AnpanAIStateActive::Update(int DeltaTime)
{
	CharacterPtr pChara = GetAI()->GetHate().GetTop();
	if (pChara.expired() && !GetParent()->IsSkillActive())
	{
		// ヘイトリストからキャラがいなくなった。
		GetAI()->Stop();
		GetAI()->ChangeState(new AnpanAIStateNonActive(GetParent()));
		return;
	}

	if (pCurrentTarget.expired() || pChara.lock().get() != pCurrentTarget.lock().get())
	{
		pCurrentTarget = pChara;
	}

	if (!bInitializedAction)
	{
		InitializeAction();
		bInitializedAction = true;
	}

	switch (pCurrentAction.lock()->Action)
	{
		case AnpanAIItem::WAIT:

			WaitTimer -= DeltaTime;
			if (WaitTimer <= 0)
			{
				ChangeToNextAction();
			}
			break;
		
		case AnpanAIItem::APPROACH:

			if (IsApproached())
			{
				Stop();
				ChangeToNextAction();
			}
			break;

		case AnpanAIItem::KEEP_DISTANCE:

			if (IsKeepedDistanceToTarget())
			{
				Stop();
				ChangeToNextAction();
			}
			break;

		case AnpanAIItem::USE_SKILL:

			if (GetParent()->IsSkillCasting())
			{
				// キャスト中はＡＩは何もしない。
			}
			if (GetParent()->IsSkillAutoMoving())
			{
				// オート移動開始.
				if (!IsRotating())
				{
					RotateToTarget();
				}
				if (!IsMoving())
				{
					MoveToTarget();
				}
			}
			else if (GetParent()->IsSkillActive())
			{
				// スキルフローが終了した。
				ChangeToNextAction();
			}
			break;
	}
}


// ターゲットの方向を向く。
void AnpanAIStateActive::RotateToTarget()
{
	CharacterPtr pTarget = pCurrentTarget;
	if (GetParent()->IsSkillActive())
	{
		pTarget = pSkillTarget;
	}

	Vector3D TargetPos = pTarget.lock()->GetPosition();
	Vector3D MyPos = GetParent()->GetPosition();
	TargetPos.Z = MyPos.Z;		// 高さは考慮しない。
	Vector3D TargetVec = (TargetPos - MyPos).GetNormalized();
	Vector3D CenterVec = GetParent()->GetCenterVec();

	float Dot = MathUtil::Dot(TargetVec, CenterVec);
	float Rad = acos(Dot);
	float Deg = MathUtil::RadToDeg(Rad);

	if (isnan(Deg))
	{
		Deg = 0.0f;
	}

	if (MathUtil::Cross(CenterVec, TargetVec).X < 0.0f)
	{
		Deg *= -1.0f;
	}
	
	SetRotate(Rotation(Deg), 300);
}

// ターゲットに向かって移動する。
void AnpanAIStateActive::MoveToTarget()
{
	if (IsApproached())
	{
		if (!GetParent()->IsSkillActive())
		{
			ChangeToNextAction();
		}
		return;
	}
	
	CharacterPtr pTarget = pCurrentTarget;
	if (GetParent()->IsSkillActive())
	{
		pTarget = pSkillTarget;
	}

	Vector3D TargetPos = pTarget.lock()->GetPosition();
	Vector3D MyPos = GetParent()->GetPosition();
	TargetPos.Z = MyPos.Z;		// 高さは考慮しない。
	Vector3D TargetVec = TargetPos - MyPos;
	float Size = TargetVec.GetSize();
	TargetVec.Normalize();
	if (!GetParent()->IsSkillActive())
	{
		TargetVec *= (Size - static_cast<float>(pCurrentAction.lock()->Value));
	}
	else
	{
		TargetVec *= (Size - SkillDistance);
	}
	
	SetMove(TargetVec, 1000);
}

// 接近しているか？
bool AnpanAIStateActive::IsApproached()
{
	float ApproachDist = static_cast<float>(pCurrentAction.lock()->Value);
	if (GetParent()->IsSkillActive())
	{
		ApproachDist = SkillDistance;
	}

	Vector3D TargetVec = pCurrentTarget.lock()->GetPosition() - GetParent()->GetPosition();
	return (TargetVec.GetSizeSq() < ApproachDist * ApproachDist);
}

// ターゲットから距離を取る。
void AnpanAIStateActive::KeepDistanceToTarget()
{
	if (IsKeepedDistanceToTarget())
	{
		ChangeToNextAction();
		return;
	}

	Vector3D TargetPos = pCurrentTarget.lock()->GetPosition();
	Vector3D MyPos = GetParent()->GetPosition();
	TargetPos.Z = MyPos.Z;		// 高さは考慮しない。
	Vector3D TargetVec = MyPos - TargetPos;
	TargetVec.Normalize();
	TargetVec *= static_cast<float>(pCurrentAction.lock()->Value);

	SetMove(TargetVec, 1000);
}

// ターゲットから距離を取ったか？
bool AnpanAIStateActive::IsKeepedDistanceToTarget()
{
	Vector3D TargetVec = pCurrentTarget.lock()->GetPosition() - GetParent()->GetPosition();
	float KeepDist = static_cast<float>(pCurrentAction.lock()->Value);
	return (TargetVec.GetSizeSq() < KeepDist * KeepDist);
}

// スキル使用.
void AnpanAIStateActive::UseSkill()
{
	u32 SkillId = pCurrentAction.lock()->Value;
	pSkillTarget = pCurrentTarget;
	const SkillItem *pItem = MasterData::GetInstance().GetSkillMaster().GetItem(SkillId);
	if (pItem == NULL)
	{
		std::cout << "AnpanAI Warning! SkillID:" << SkillId << " is Invalid." << std::endl;
		ChangeToNextAction();
		return;
	}

	switch (pItem->SkillType)
	{
		case SkillItem::HEAL:
		case SkillItem::BUFF:

			pSkillTarget = GetParent()->shared_from_this();
			break;
	}

	GetParent()->UseSkill(SkillId, pSkillTarget);
	SkillDistance = static_cast<float>(pItem->Distance);
}

// 次のアクションに変更.
void AnpanAIStateActive::ChangeToNextAction()
{
	pCurrentAction = pCurrentAction.lock()->pNextAction;
	InitializeAction();
}

// アクションの初期化.
void AnpanAIStateActive::InitializeAction()
{
	switch (pCurrentAction.lock()->Action)
	{
		case AnpanAIItem::WAIT:

			WaitTimer = pCurrentAction.lock()->Value;
			break;

		case AnpanAIItem::APPROACH:

			RotateToTarget();
			MoveToTarget();
			break;

		case AnpanAIItem::KEEP_DISTANCE:

			KeepDistanceToTarget();
			break;

		case AnpanAIItem::USE_SKILL:

			UseSkill();
			break;

		case AnpanAIItem::CHANGE_STAGE:

			ChangeToNextAction();
			break;
	}
}
