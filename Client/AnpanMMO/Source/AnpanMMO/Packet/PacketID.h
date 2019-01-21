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

	/**
	 * @enum EID
	 * �p�P�b�g�h�c
	 */
	enum EID
	{
		//! �A���p�����X�g�p�P�b�g
		AnpanList = 0x01,
		//! �A���p�������p�P�b�g
		SpawnAnpan = 0x02,
		//! �A���p���ړ��p�P�b�g
		MoveAnpan = 0x03,
		//! �A���p����]�p�P�b�g
		RotateAnpan = 0x04,
		//! �A���p����~�p�P�b�g
		StopAnpan = 0x05,
		//! �_���[�W�p�P�b�g
		Damage = 0x06,
		//! �񕜃p�P�b�g
		Heal = 0x07,
		//! �o�t�ǉ��p�P�b�g
		AddBuff = 0x08,
		//! �o�t�����p�P�b�g
		RemoveBuff = 0x09,
		//! �`���b�g���M�p�P�b�g
		SendChat = 0x0A,
		//! �`���b�g��M�p�P�b�g
		ReceiveChat = 0x0B,
		//! �����ύX���N�G�X�g�p�P�b�g
		ChangeEquipRequest = 0x0C,
		//! �����ύX���ʃp�P�b�g
		ChangeEquipResult = 0x0D,
		//! ���������p�P�b�g
		GameReady = 0x0E,
		//! �G���A�ړ��p�P�b�g
		AreaMove = 0x0F,
		//! �G���A�ړ����N�G�X�g�p�P�b�g
		AreaMoveRequest = 0x10,
		//! �G���A�ړ����X�|���X�p�P�b�g
		AreaMoveResponse = 0x11,
		//! �o���l�ǉ��p�P�b�g
		AddExp = 0x12,
		//! ���x���A�b�v�p�P�b�g
		LevelUp = 0x13,
		//! �S�[���h�ω��p�P�b�g
		ChangeGold = 0x14,
		//! �C���X�^���X�}�b�v�`�P�b�g���s�p�P�b�g
		InstanceAreaTicketPublish = 0x15,
		//! �C���X�^���X�}�b�v�`�P�b�g�����p�P�b�g
		InstanceAreaTicketProcess = 0x16,
		//! �C���X�^���X�}�b�v�`�P�b�g�j���p�P�b�g
		InstanceAreaTicketDiscard = 0x17,
		//! �C���X�^���X�}�b�v�E�o�|�C���g�����p�P�b�g
		SpawnInstanceAreaExitPoint = 0x18,
		//! ���O�C�����A�C�e�����X�g�ʒm�p�P�b�g
		ItemList = 0x19,
		//! ���O�C�����A�C�e���V���[�g�J�b�g�ʒm�p�P�b�g
		ItemShortcut = 0x1A,
		//! �A�C�e���g�p�p�P�b�g
		ItemUse = 0x1B,
		//! �A�C�e���ǉ��p�P�b�g
		ItemAdd = 0x1C,
		//! �A�C�e������p�P�b�g
		ItemSubtract = 0x1D,
		//! �A�C�e���j�����N�G�X�g�p�P�b�g
		ItemSubtractRequest = 0x1E,
		//! �A�C�e���V���[�g�J�b�g�ۑ����N�G�X�g�p�P�b�g
		SaveItemShortcutRequest = 0x1F,
		//! �A�C�e���V���[�g�J�b�g�ۑ����ʃp�P�b�g
		SaveItemShortcutResult = 0x20,
		//! ���O�C�����N�G�X�g�p�P�b�g
		LogInRequest = 0x21,
		//! ���O�C�����N�G�X�g���ʃp�P�b�g
		LogInResult = 0x22,
		//! �L�����N�^�쐬���N�G�X�g�p�P�b�g
		CreateCharacterRequest = 0x23,
		//! �L�����N�^�쐬���ʃp�P�b�g
		CreateCharacterResult = 0x24,
		//! �L�����N�^�p�����[�^�p�P�b�g
		CharacterStatus = 0x25,
		//! �ʒm���X�g�p�P�b�g
		NoticeList = 0x26,
		//! �ʒm�p�P�b�g
		ReceiveNotice = 0x27,
		//! ��b�J�n�p�P�b�g
		NPCTalk = 0x28,
		//! �I������I���p�P�b�g
		NPCTalkSelection = 0x29,
		//! �p�[�e�B�쐬���N�G�X�g�p�P�b�g
		PartyCreateRequest = 0x2A,
		//! �p�[�e�B�쐬���ʃp�P�b�g
		PartyCreateResult = 0x2B,
		//! �p�[�e�B���U���N�G�X�g�p�P�b�g
		PartyInviteRequest = 0x2C,
		//! �p�[�e�B���U���ʃp�P�b�g
		PartyInviteResult = 0x2D,
		//! �p�[�e�B���U���X�|���X�p�P�b�g
		PartyInviteResponse = 0x2E,
		//! �p�[�e�B�����p�P�b�g
		PartyJoin = 0x2F,
		//! �p�[�e�B�����o�����p�P�b�g
		PartyJoinMember = 0x30,
		//! �p�[�e�B���E���N�G�X�g�p�P�b�g
		PartyExitRequest = 0x31,
		//! �p�[�e�B���E���ʃp�P�b�g
		PartyExitResult = 0x32,
		//! �p�[�e�B���E�p�P�b�g
		PartyExit = 0x33,
		//! �p�[�e�B�����o�L�b�N���N�G�X�g�p�P�b�g
		PartyKickRequest = 0x34,
		//! �p�[�e�B�����o�L�b�N���ʃp�P�b�g
		PartyKickResult = 0x35,
		//! �p�[�e�B�����o�L�b�N�p�P�b�g
		PartyKick = 0x36,
		//! �p�[�e�B���U���N�G�X�g�p�P�b�g
		PartyDissolutionRequest = 0x37,
		//! �p�[�e�B���U���ʃp�P�b�g
		PartyDissolutionResult = 0x38,
		//! �p�[�e�B���U�p�P�b�g
		PartyDissolution = 0x39,
		//! Ping�p�P�b�g
		Ping = 0x3A,
		//! �v���C���[���X�g�p�P�b�g
		PlayerList = 0x3B,
		//! �v���C���[�����p�P�b�g
		SpawnPlayer = 0x3C,
		//! �v���C���[�ړ��p�P�b�g
		MovePlayer = 0x3D,
		//! �v���C���[�ޏo�p�P�b�g
		ExitPlayer = 0x3E,
		//! �v���C���[���X�|���v���p�P�b�g
		RespawnRequest = 0x3F,
		//! �v���C���[���X�|���p�P�b�g
		PlayerRespawn = 0x40,
		//! �N�G�X�g�f�[�^���X�g�p�P�b�g
		QuestData = 0x41,
		//! �N�G�X�g�󒍃p�P�b�g
		QuestAccept = 0x42,
		//! �N�G�X�g�A���p���L���p�P�b�g
		QuestAnpanKill = 0x43,
		//! �N�G�X�g�X�e�[�W�i�s�p�P�b�g
		QuestStageChange = 0x44,
		//! �N�G�X�g�N���A�p�P�b�g
		QuestClear = 0x45,
		//! �N�G�X�g�j�����N�G�X�g�p�P�b�g
		QuestRetireRequest = 0x46,
		//! �N�G�X�g�j�����X�|���X�p�P�b�g
		QuestRetireResponse = 0x47,
		//! �A�N�e�B�u�N�G�X�g�ۑ��p�P�b�g
		SaveActiveQuest = 0x48,
		//! �X�N���v�g�t���O�p�P�b�g
		ScriptFlag = 0x49,
		//! �A�C�e���w���v���p�P�b�g
		BuyItemRequest = 0x4A,
		//! �A�C�e���w�����ʃp�P�b�g
		BuyItemResult = 0x4B,
		//! �A�C�e�����p�v���p�P�b�g
		SellItemRequest = 0x4C,
		//! �A�C�e�����p���ʃp�P�b�g
		SellItemResult = 0x4D,
		//! �X�L���g�p�p�P�b�g
		SkillUse = 0x4E,
		//! �X�L���g�p���s�p�P�b�g
		SkillUseFailed = 0x4F,
		//! �X�L���r���J�n�p�P�b�g
		SkillCast = 0x50,
		//! �X�L���r�������p�P�b�g
		SkillCastFinish = 0x51,
		//! �X�L�������p�P�b�g
		SkillActivate = 0x52,
		//! ���L���X�g�����p�P�b�g
		SkillRecast = 0x53,
		//! �X�L�����X�g�p�P�b�g
		SkillList = 0x54,
		//! �X�L�����X�g�ۑ����N�G�X�g�p�P�b�g
		SaveSkillListRequest = 0x55,
		//! �X�L�����X�g�ۑ����X�|���X�p�P�b�g
		SaveSkillListResponse = 0x56,
		//! �X�L���c���[�f�[�^�p�P�b�g
		SkillTreeData = 0x57,
		//! �X�L���c���[�J���v���p�P�b�g
		SkillTreeOpenRequest = 0x58,
		//! �X�L���c���[�J�����ʃp�P�b�g
		SkillTreeOpenResult = 0x59,
		//! ���O�C�����̎��Ԓʒm�p�P�b�g
		Time = 0x5A,
		//! ���ԕω��ʒm�p�P�b�g
		TimeChange = 0x5B,
		
	};
};

#endif		// #ifndef __PACKETID_H__
