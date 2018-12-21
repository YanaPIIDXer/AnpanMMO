/**
 * @file $FILE_NAME$
 * @brief �p�P�b�g�h�c��`.
 * @author NativePacketGenerator
 */

#ifndef __PACKETID_H__
#define __PACKETID_H__

/**
 * @brief �p�P�b�g�h�c��`.
 */
class PacketID
{

public:

	enum EID
	{
		AnpanList = 0x01,
		SpawnAnpan = 0x02,
		MoveAnpan = 0x03,
		RotateAnpan = 0x04,
		StopAnpan = 0x05,
		Damage = 0x06,
		Heal = 0x07,
		SendChat = 0x08,
		ReceiveChat = 0x09,
		GameReady = 0x0A,
		AreaMove = 0x0B,
		AreaMoveRequest = 0x0C,
		AreaMoveResponse = 0x0D,
		AddExp = 0x0E,
		LevelUp = 0x0F,
		ChangeGold = 0x10,
		InstanceAreaTicketPublish = 0x11,
		InstanceAreaTicketProcess = 0x12,
		InstanceAreaTicketDiscard = 0x13,
		SpawnInstanceAreaExitPoint = 0x14,
		ItemList = 0x15,
		ItemShortcut = 0x16,
		ItemUse = 0x17,
		ItemAdd = 0x18,
		ItemSubtract = 0x19,
		ItemSubtractRequest = 0x1A,
		SaveItemShortcutRequest = 0x1B,
		SaveItemShortcutResult = 0x1C,
		LogInRequest = 0x1D,
		LogInResult = 0x1E,
		CreateCharacterRequest = 0x1F,
		CreateCharacterResult = 0x20,
		CharacterStatus = 0x21,
		NoticeList = 0x22,
		ReceiveNotice = 0x23,
		NPCTalk = 0x24,
		NPCTalkSelection = 0x25,
		PartyCreateRequest = 0x26,
		PartyCreateResult = 0x27,
		PartyInviteRequest = 0x28,
		PartyInviteResult = 0x29,
		PartyInviteResponse = 0x2A,
		PartyJoin = 0x2B,
		PartyJoinMember = 0x2C,
		PartyExitRequest = 0x2D,
		PartyExitResult = 0x2E,
		PartyExit = 0x2F,
		PartyKickRequest = 0x30,
		PartyKickResult = 0x31,
		PartyKick = 0x32,
		PartyDissolutionRequest = 0x33,
		PartyDissolutionResult = 0x34,
		PartyDissolution = 0x35,
		Ping = 0x36,
		PlayerList = 0x37,
		SpawnPlayer = 0x38,
		MovePlayer = 0x39,
		ExitPlayer = 0x3A,
		RespawnRequest = 0x3B,
		PlayerRespawn = 0x3C,
		QuestData = 0x3D,
		QuestAccept = 0x3E,
		QuestAnpanKill = 0x3F,
		QuestStageChange = 0x40,
		QuestClear = 0x41,
		QuestRetireRequest = 0x42,
		QuestRetireResponse = 0x43,
		SaveActiveQuest = 0x44,
		ScriptFlag = 0x45,
		SkillUse = 0x46,
		SkillUseFailed = 0x47,
		SkillCast = 0x48,
		SkillCastFinish = 0x49,
		SkillActivate = 0x4A,
		SkillRecast = 0x4B,
		SkillList = 0x4C,
		SaveSkillListRequest = 0x4D,
		SaveSkillListResponse = 0x4E,
		SkillTreeData = 0x4F,
		SkillTreeOpenRequest = 0x50,
		SkillTreeOpenResult = 0x51,
		Time = 0x52,
		TimeChange = 0x53,
		
	};
};

#endif		// #ifndef __PACKETID_H__
