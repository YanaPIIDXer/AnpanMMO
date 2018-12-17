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

// �R���X�g���N�^
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

// �f�X�g���N�^
PlayerCharacter::~PlayerCharacter()
{
	SaveParameter();
}

// �ړ������B
void PlayerCharacter::OnMoved()
{
	if (GetArea().lock()->IsInstance()) { return; }
	SavePosition = GetPosition();
}

// �G���A���؂�ւ�����B
void PlayerCharacter::OnAreaChange()
{
	AreaPtr pArea = GetArea();
	if (pArea.lock()->IsInstance()) { return; }
	SaveAreaId = pArea.lock()->GetId();
}

// �S�[���h�ǉ�.
void PlayerCharacter::AddGold(u32 Value)
{
	Gold += Value;

	CachePacketGoldSave Packet(GetClient()->GetUuid(), GetClient()->GetCustomerId(), Gold);
	CacheServerConnection::GetInstance()->SendPacket(&Packet);

	PacketChangeGold ChangePacket(Gold);
	GetClient()->SendPacket(&ChangePacket);
}

// �S�[���h����.
void PlayerCharacter::SubtractGold(u32 Value)
{
	if (Gold < Value)
	{
		// �����Ă͂Ȃ�Ȃ��������E�E�E
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

// �X�L���c���[������.
void PlayerCharacter::InitializeSkillTree(const FlexArray<u32> &OpenedNodes)
{
	for (int i = 0; i < OpenedNodes.GetCurrentSize(); i++)
	{
		Tree.Open(OpenedNodes[i]);
	}
}

// �X�L���c���[�I�[�v��
u8 PlayerCharacter::OpenSkillTree(u32 NodeId)
{
	const SkillTreeItem *pItem = MasterData::GetInstance().GetSkillTreeMaster().GetItem(NodeId);

	// �e�m�[�h���J����Ă��邩���`�F�b�N
	bool bIsOpened = true;
	if (pItem->ParentNode != 0 && !Tree.IsOpened(pItem->ParentNode, bIsOpened))
	{
		return PacketSkillTreeOpenResult::Error;
	}
	if (!bIsOpened)
	{
		return PacketSkillTreeOpenResult::NotOpenedParent;
	}

	// ���ɊJ����Ă��邩�ǂ������`�F�b�N
	if (!Tree.IsOpened(NodeId, bIsOpened))
	{
		return PacketSkillTreeOpenResult::Error;
	}
	if (bIsOpened)
	{
		return PacketSkillTreeOpenResult::AlreadyOpened;
	}

	// ���x���`�F�b�N
	if (GetParameter().Level < pItem->NeedLevel)
	{
		return PacketSkillTreeOpenResult::NotEnoughLevel;
	}

	// �R�X�g�`�F�b�N
	if (Gold < pItem->Cost)
	{
		// �R�X�g������Ȃ��B
		return PacketSkillTreeOpenResult::NotEnoughCost;
	}

	// �I�[�v��
	if (!Tree.Open(NodeId))
	{
		return PacketSkillTreeOpenResult::Error;
	}

	// �R�X�g����.
	SubtractGold(pItem->Cost);

	return PacketSkillTreeOpenResult::Success;
}

// �A�C�e�����X�g����M�����B
void PlayerCharacter::OnRecvItemList(const FlexArray<ItemData> &List)
{
	for (int i = 0; i < List.GetCurrentSize(); i++)
	{
		Items.Add(List[i].ItemId, List[i].Count);
	}
}

// �A�C�e���g�p.
void PlayerCharacter::UseItem(u32 ItemId, CharacterPtr pTarget)
{
	if (Items.GetCount(ItemId) == 0) { return; }
	Skill.UseItem(ItemId, pTarget);
}

// �A�C�e���ǉ�.
void PlayerCharacter::AddItem(u32 ItemId, u32 Count)
{
	Items.Add(ItemId, Count);

	PacketItemAdd Packet(ItemId, Count);
	GetClient()->SendPacket(&Packet);

	u32 ItemCount = Items.GetCount(ItemId);
	CachePacketItemCountChangeRequest CachePacket(GetClient()->GetUuid(), CharacterId, ItemId, ItemCount);
	CacheServerConnection::GetInstance()->SendPacket(&CachePacket);
}

// �A�C�e���j��.
void PlayerCharacter::SubtractItem(u32 ItemId, u32 Count)
{
	Items.Subtract(ItemId, Count);

	PacketItemSubtract Packet(ItemId, Count);
	GetClient()->SendPacket(&Packet);

	u32 ItemCount = Items.GetCount(ItemId);
	CachePacketItemCountChangeRequest CachePacket(GetClient()->GetUuid(), CharacterId, ItemId, ItemCount);
	CacheServerConnection::GetInstance()->SendPacket(&CachePacket);
}


// ���x���A�b�v�R�[���o�b�N
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

// �p�����[�^��ۑ�.
void PlayerCharacter::SaveParameter()
{
	const CharacterParameter &Param = GetParameter();
	if (SaveAreaId == 0) { return; }		// �܂��G���A�ɑ����Ă��Ȃ��B
	Client *pClient = GetClient();
	CachePacketCharacterDataSave Packet(pClient->GetUuid(), CharacterId, Param.Level, Param.MaxHp, Param.Atk, Param.Def, Exp.Get(), SaveAreaId, SavePosition.X, SavePosition.Y, SavePosition.Z);
	CacheServerConnection::GetInstance()->SendPacket(&Packet);
}

// �X�L�����L�����Z�����ꂽ
void PlayerCharacter::OnSkillCanceled(u8 Reason)
{
	PacketSkillUseFailed Packet(Reason);
	GetClient()->SendPacket(&Packet);
}

// ���L���X�g�����������B
void PlayerCharacter::OnSkillRecastFinished(u32 SkillId)
{
	PacketSkillRecast Packet(SkillId);
	GetClient()->SendPacket(&Packet);
}

// �A�C�e�����g�p�����B
void PlayerCharacter::OnUsedItem(u32 ItemId)
{
	SubtractItem(ItemId, 1);
}
