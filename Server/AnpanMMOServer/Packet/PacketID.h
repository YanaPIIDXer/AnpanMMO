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
		//! �A���p�����X�g
		AnpanList = 0x01,
		//! �A���p������
		SpawnAnpan = 0x02,
		//! �A���p���ړ�
		MoveAnpan = 0x03,
		//! �A���p����]
		RotateAnpan = 0x04,
		//! �A���p����~
		StopAnpan = 0x05,
		//! �_���[�W
		Damage = 0x06,
		//! ��
		Heal = 0x07,
		//! �`���b�g���M
		SendChat = 0x08,
		//! �`���b�g��M
		ReceiveChat = 0x09,
		//! ��������
		GameReady = 0x0A,
		//! �G���A�ړ�
		AreaMove = 0x0B,
		//! �G���A�ړ����N�G�X�g
		AreaMoveRequest = 0x0C,
		//! �G���A�ړ����X�|���X
		AreaMoveResponse = 0x0D,
		//! �o���l�ǉ�
		AddExp = 0x0E,
		//! ���x���A�b�v
		LevelUp = 0x0F,
		//! �S�[���h�ω�
		ChangeGold = 0x10,
		//! �C���X�^���X�}�b�v�`�P�b�g���s
		InstanceAreaTicketPublish = 0x11,
		//! �C���X�^���X�}�b�v�`�P�b�g����
		InstanceAreaTicketProcess = 0x12,
		//! �C���X�^���X�}�b�v�`�P�b�g�j��
		InstanceAreaTicketDiscard = 0x13,
		//! �C���X�^���X�}�b�v�E�o�|�C���g����
		SpawnInstanceAreaExitPoint = 0x14,
		//! ���O�C�����A�C�e�����X�g�ʒm
		ItemList = 0x15,
		//! ���O�C�����A�C�e���V���[�g�J�b�g�ʒm
		ItemShortcut = 0x16,
		//! �A�C�e���g�p
		ItemUse = 0x17,
		//! �A�C�e���ǉ�
		ItemAdd = 0x18,
		//! �A�C�e������
		ItemSubtract = 0x19,
		//! �A�C�e���j�����N�G�X�g
		ItemSubtractRequest = 0x1A,
		//! �A�C�e���V���[�g�J�b�g�ۑ����N�G�X�g
		SaveItemShortcutRequest = 0x1B,
		//! �A�C�e���V���[�g�J�b�g�ۑ�����
		SaveItemShortcutResult = 0x1C,
		//! ���O�C�����N�G�X�g
		LogInRequest = 0x1D,
		//! ���O�C�����N�G�X�g����
		LogInResult = 0x1E,
		//! �L�����N�^�쐬���N�G�X�g
		CreateCharacterRequest = 0x1F,
		//! �L�����N�^�쐬����
		CreateCharacterResult = 0x20,
		//! �L�����N�^�p�����[�^
		CharacterStatus = 0x21,
		//! �ʒm���X�g
		NoticeList = 0x22,
		//! �ʒm
		ReceiveNotice = 0x23,
		//! ��b�J�n
		NPCTalk = 0x24,
		//! �I������I��
		NPCTalkSelection = 0x25,
		//! �p�[�e�B�쐬���N�G�X�g
		PartyCreateRequest = 0x26,
		//! �p�[�e�B�쐬����
		PartyCreateResult = 0x27,
		//! �p�[�e�B���U���N�G�X�g
		PartyInviteRequest = 0x28,
		//! �p�[�e�B���U����
		PartyInviteResult = 0x29,
		//! �p�[�e�B���U���X�|���X
		PartyInviteResponse = 0x2A,
		//! �p�[�e�B����
		PartyJoin = 0x2B,
		//! �p�[�e�B�����o����
		PartyJoinMember = 0x2C,
		//! �p�[�e�B���E���N�G�X�g
		PartyExitRequest = 0x2D,
		//! �p�[�e�B���E����
		PartyExitResult = 0x2E,
		//! �p�[�e�B���E
		PartyExit = 0x2F,
		//! �p�[�e�B�����o�L�b�N���N�G�X�g
		PartyKickRequest = 0x30,
		//! �p�[�e�B�����o�L�b�N����
		PartyKickResult = 0x31,
		//! �p�[�e�B�����o�L�b�N
		PartyKick = 0x32,
		//! �p�[�e�B���U���N�G�X�g
		PartyDissolutionRequest = 0x33,
		//! �p�[�e�B���U����
		PartyDissolutionResult = 0x34,
		//! �p�[�e�B���U
		PartyDissolution = 0x35,
		//! Ping
		Ping = 0x36,
		//! �v���C���[���X�g
		PlayerList = 0x37,
		//! �v���C���[����
		SpawnPlayer = 0x38,
		//! �v���C���[�ړ�
		MovePlayer = 0x39,
		//! �v���C���[�ޏo
		ExitPlayer = 0x3A,
		//! �v���C���[���X�|���v��
		RespawnRequest = 0x3B,
		//! �v���C���[���X�|��
		PlayerRespawn = 0x3C,
		//! �N�G�X�g�f�[�^���X�g
		QuestData = 0x3D,
		//! �N�G�X�g��
		QuestAccept = 0x3E,
		//! �N�G�X�g�A���p���L��
		QuestAnpanKill = 0x3F,
		//! �N�G�X�g�X�e�[�W�i�s
		QuestStageChange = 0x40,
		//! �N�G�X�g�N���A
		QuestClear = 0x41,
		//! �N�G�X�g�j�����N�G�X�g
		QuestRetireRequest = 0x42,
		//! �N�G�X�g�j�����X�|���X
		QuestRetireResponse = 0x43,
		//! �A�N�e�B�u�N�G�X�g�ۑ�
		SaveActiveQuest = 0x44,
		//! �X�N���v�g�t���O
		ScriptFlag = 0x45,
		//! �X�L���g�p
		SkillUse = 0x46,
		//! �X�L���g�p���s
		SkillUseFailed = 0x47,
		//! �X�L���r���J�n
		SkillCast = 0x48,
		//! �X�L���r������
		SkillCastFinish = 0x49,
		//! �X�L������
		SkillActivate = 0x4A,
		//! ���L���X�g����
		SkillRecast = 0x4B,
		//! �X�L�����X�g
		SkillList = 0x4C,
		//! �X�L�����X�g�ۑ����N�G�X�g
		SaveSkillListRequest = 0x4D,
		//! �X�L�����X�g�ۑ����X�|���X
		SaveSkillListResponse = 0x4E,
		//! �X�L���c���[�f�[�^
		SkillTreeData = 0x4F,
		//! �X�L���c���[�J���v��
		SkillTreeOpenRequest = 0x50,
		//! �X�L���c���[�J������
		SkillTreeOpenResult = 0x51,
		//! ���O�C�����̎��Ԓʒm
		Time = 0x52,
		//! ���ԕω��ʒm
		TimeChange = 0x53,
		
	};
};

#endif		// #ifndef __PACKETID_H__
