#include "stdafx.h"
#include "PlayerCharacter.h"
#include "Client.h"
#include "Math/Random.h"
#include "Area/AreaManager.h"
#include "Master/MasterData.h"
#include "CacheServer/CacheServerConnection.h"
#include "Packet/CachePacketCharacterDataSave.h"
#include "Packet/CachePacketGoldSave.h"
#include "Packet/PacketLevelUp.h"
#include "Packet/PacketSkillCastFinish.h"
#include "Packet/CharacterType.h"
#include "Packet/PacketSkillActivate.h"
#include "Packet/PacketSkillUseFailed.h"
#include "Packet/PacketSkillRecast.h"
#include "Packet/PacketChangeGold.h"
#include "Packet/PacketSkillTreeOpenResult.h"
#include "Packet/ItemData.h"
#include "Packet/PacketItemAdd.h"
#include "Packet/PacketItemSubtract.h"
#include "Packet/CachePacketItemCountChangeRequest.h"

// コンストラクタ
PlayerCharacter::PlayerCharacter(Client *pInClient, u32 InCharacterId, u8 InJob, u32 Level, int MaxHp, int Atk, int Def, int InExp, u32 InGold)
	: pClient(pInClient)
	, Exp(InExp)
	, CharacterId(InCharacterId)
	, Job(InJob)
	, Gold(InGold)
	, Tree(InJob)
	, SaveAreaId(0)
	, SavePosition(Vector3D::Zero)
{
	SetParameter(Level, MaxHp, MaxHp, Atk, Def);
	Exp.SetLevelUpCallback(bind(&PlayerCharacter::OnLevelUp, this));
	Skill.SetOnCancelFunction(boost::bind(&PlayerCharacter::OnSkillCanceled, this, _1));
	Skill.SetOnUsedItemFunction(boost::bind(&PlayerCharacter::OnUsedItem, this, _1));
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

// ゴールド追加.
void PlayerCharacter::AddGold(u32 Value)
{
	Gold += Value;

	CachePacketGoldSave Packet(GetClient()->GetUuid(), GetClient()->GetCustomerId(), Gold);
	CacheServerConnection::GetInstance()->SendPacket(&Packet);

	PacketChangeGold ChangePacket(Gold);
	GetClient()->SendPacket(&ChangePacket);
}

// ゴールド消費.
void PlayerCharacter::SubtractGold(u32 Value)
{
	if (Gold < Value)
	{
		// あってはならない事だが・・・
		Gold = 0;
	}
	else
	{
		Gold -= Value;
	}

	CachePacketGoldSave Packet(GetClient()->GetUuid(), CharacterId, Gold);
	CacheServerConnection::GetInstance()->SendPacket(&Packet);

	PacketChangeGold ChangePacket(Gold);
	GetClient()->SendPacket(&ChangePacket);
}

// スキルツリー初期化.
void PlayerCharacter::InitializeSkillTree(const FlexArray<u32> &OpenedNodes)
{
	for (int i = 0; i < OpenedNodes.GetCurrentSize(); i++)
	{
		Tree.Open(OpenedNodes[i]);
	}
}

// スキルツリーオープン
u8 PlayerCharacter::OpenSkillTree(u32 NodeId)
{
	const SkillTreeItem *pItem = MasterData::GetInstance().GetSkillTreeMaster().GetItem(NodeId);

	// 親ノードが開かれているかをチェック
	bool bIsOpened = true;
	if (pItem->ParentNode != 0 && !Tree.IsOpened(pItem->ParentNode, bIsOpened))
	{
		return PacketSkillTreeOpenResult::Error;
	}
	if (!bIsOpened)
	{
		return PacketSkillTreeOpenResult::NotOpenedParent;
	}

	// 既に開かれているかどうかをチェック
	if (!Tree.IsOpened(NodeId, bIsOpened))
	{
		return PacketSkillTreeOpenResult::Error;
	}
	if (bIsOpened)
	{
		return PacketSkillTreeOpenResult::AlreadyOpened;
	}

	// レベルチェック
	if (GetParameter().Level < pItem->NeedLevel)
	{
		return PacketSkillTreeOpenResult::NotEnoughLevel;
	}

	// コストチェック
	if (Gold < pItem->Cost)
	{
		// コストが足りない。
		return PacketSkillTreeOpenResult::NotEnoughCost;
	}

	// オープン
	if (!Tree.Open(NodeId))
	{
		return PacketSkillTreeOpenResult::Error;
	}

	// コスト消費.
	SubtractGold(pItem->Cost);

	return PacketSkillTreeOpenResult::Success;
}

// アイテムリストを受信した。
void PlayerCharacter::OnRecvItemList(const FlexArray<ItemData> &List)
{
	for (int i = 0; i < List.GetCurrentSize(); i++)
	{
		Items.Add(List[i].ItemId, List[i].Count);
	}
}

// アイテム使用.
void PlayerCharacter::UseItem(u32 ItemId, CharacterPtr pTarget)
{
	if (Items.GetCount(ItemId) == 0) { return; }
	Skill.UseItem(ItemId, pTarget);
}

// アイテム追加.
void PlayerCharacter::AddItem(u32 ItemId, u32 Count)
{
	Items.Add(ItemId, Count);

	PacketItemAdd Packet(ItemId, Count);
	GetClient()->SendPacket(&Packet);

	u32 ItemCount = Items.GetCount(ItemId);
	CachePacketItemCountChangeRequest CachePacket(GetClient()->GetUuid(), CharacterId, ItemId, ItemCount);
	CacheServerConnection::GetInstance()->SendPacket(&CachePacket);
}

// アイテム破棄.
void PlayerCharacter::SubtractItem(u32 ItemId, u32 Count)
{
	Items.Subtract(ItemId, Count);

	PacketItemSubtract Packet(ItemId, Count);
	GetClient()->SendPacket(&Packet);

	u32 ItemCount = Items.GetCount(ItemId);
	CachePacketItemCountChangeRequest CachePacket(GetClient()->GetUuid(), CharacterId, ItemId, ItemCount);
	CacheServerConnection::GetInstance()->SendPacket(&CachePacket);
}


// レベルアップコールバック
void PlayerCharacter::OnLevelUp()
{
	int MaxHp = Random::Range<int>(10, 20);
	int Atk = Random::Range<int>(10, 20);
	int Def = Random::Range<int>(10, 20);
	LevelUp(MaxHp, Atk, Def);

	const CharacterParameter &Param = GetParameter();
	PacketLevelUp Packet(Param.Level, Param.MaxHp, Param.Atk, Param.Def, Exp.Get());
	GetClient()->SendPacket(&Packet);

	SaveParameter();
}

// パラメータを保存.
void PlayerCharacter::SaveParameter()
{
	const CharacterParameter &Param = GetParameter();
	if (SaveAreaId == 0) { return; }		// まだエリアに属していない。
	Client *pClient = GetClient();
	CachePacketCharacterDataSave Packet(pClient->GetUuid(), CharacterId, Param.Level, Param.MaxHp, Param.Atk, Param.Def, Exp.Get(), SaveAreaId, SavePosition.X, SavePosition.Y, SavePosition.Z);
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

// アイテムを使用した。
void PlayerCharacter::OnUsedItem(u32 ItemId)
{
	SubtractItem(ItemId, 1);
}
