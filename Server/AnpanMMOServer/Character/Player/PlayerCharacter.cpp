#include "stdafx.h"
#include "PlayerCharacter.h"
#include "Client.h"
#include "Math/Random.h"
#include "Packet/PacketLevelUp.h"
#include "Area/AreaManager.h"
#include "CacheServer/CacheServerConnection.h"
#include "Packet/CachePacketCharacterDataSave.h"
#include "Packet/PacketSkillCastFinish.h"
#include "Packet/CharacterType.h"
#include "Packet/PacketSkillActivate.h"
#include "Packet/PacketSkillUseFailed.h"
#include "Packet/PacketSkillRecast.h"

// コンストラクタ
PlayerCharacter::PlayerCharacter(Client *pInClient, u8 InJob, int MaxHp, int Atk, int Def, int InExp)
	: pClient(pInClient)
	, Exp(InExp)
	, Job(InJob)
	, SaveAreaId(0)
	, SavePosition(Vector3D::Zero)
{
	SetParameter(MaxHp, MaxHp, Atk, Def);
	Exp.SetLevelUpCallback(bind(&PlayerCharacter::OnLevelUp, this));
	Skill.SetOnCancelFunction(boost::bind(&PlayerCharacter::OnSkillCanceled, this, _1));
	Recast.SetRecastFinishedFunction(boost::bind(&PlayerCharacter::OnSkillRecastFinished, this, _1));
}

// デストラクタ
PlayerCharacter::~PlayerCharacter()
{
	SaveParameter();
}

// 移動した。
void PlayerCharacter::OnMoved()
{
	if (GetArea().lock()->IsInstance()) { return; }
	SavePosition = GetPosition();
}

// エリアが切り替わった。
void PlayerCharacter::OnAreaChange()
{
	AreaPtr pArea = GetArea();
	if (pArea.lock()->IsInstance()) { return; }
	SaveAreaId = pArea.lock()->GetId();
}


// レベルアップコールバック
void PlayerCharacter::OnLevelUp()
{
	int MaxHp = Random::Range<int>(10, 20);
	int Atk = Random::Range<int>(10, 20);
	int Def = Random::Range<int>(10, 20);
	AddParameter(MaxHp, Atk, Def);

	const CharacterParameter &Param = GetParameter();
	PacketLevelUp Packet(Param.MaxHp, Param.Atk, Param.Def, Exp.Get());
	GetClient()->SendPacket(&Packet);

	SaveParameter();
}

// パラメータを保存.
void PlayerCharacter::SaveParameter()
{
	const CharacterParameter &Param = GetParameter();
	if (SaveAreaId == 0) { return; }		// まだエリアに属していない。
	Client *pClient = GetClient();
	CachePacketCharacterDataSave Packet(pClient->GetUuid(), pClient->GetCustomerId(), Param.MaxHp, Param.Atk, Param.Def, Exp.Get(), SaveAreaId, SavePosition.X, SavePosition.Y, SavePosition.Z);
	CacheServerConnection::GetInstance()->SendPacket(&Packet);
}

// スキルがキャンセルされた
void PlayerCharacter::OnSkillCanceled(u8 Reason)
{
	PacketSkillUseFailed Packet(Reason);
	GetClient()->SendPacket(&Packet);
}

// リキャストが完了した。
void PlayerCharacter::OnSkillRecastFinished(u32 SkillId)
{
	PacketSkillRecast Packet(SkillId);
	GetClient()->SendPacket(&Packet);
}
