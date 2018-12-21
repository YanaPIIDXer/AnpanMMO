/**
 * @file $FILE_NAME$
 * @brief �p�P�b�g�h�c��`.
 * @author NativePacketGenerator
 */

#ifndef __CACHESERVERPACKETID_H__
#define __CACHESERVERPACKETID_H__

/**
 * @brief �p�P�b�g�h�c��`.
 */
class CachePacketID
{

public:

	/**
	 * @enum EID
	 * �p�P�b�g�h�c
	 */
	enum EID
	{
		//! ���O�C�����N�G�X�g
		CacheLogInRequest = 0x40,
		//! ���O�C�����N�G�X�g����
		CacheLogInResult = 0x41,
		//! �L�����N�^�쐬���N�G�X�g
		CacheCreateCharacterRequest = 0x42,
		//! �L�����N�^�쐬����
		CacheCreateCharacterResult = 0x43,
		//! �L�����N�^��񃊃N�G�X�g
		CacheCharacterDataRequest = 0x44,
		//! �L�����N�^��񃌃X�|���X
		CacheCharacterDataResult = 0x45,
		//! �X�L�����X�g���N�G�X�g
		CacheSkillListRequest = 0x46,
		//! �X�L�����X�g���X�|���X
		CacheSkillListResponse = 0x47,
		//! �X�N���v�g�t���O���N�G�X�g
		CacheScriptFlagRequest = 0x48,
		//! �X�N���v�g�t���O���X�|���X
		CacheScriptFlagResponse = 0x49,
		//! �X�N���v�g�t���O�ۑ����N�G�X�g
		CacheScriptFlagSaveRequest = 0x4A,
		//! �X�L�����X�g�ۑ����N�G�X�g
		CacheSaveSkillListRequest = 0x4B,
		//! �X�L�����X�g�ۑ����X�|���X
		CacheSaveSkillListResponse = 0x4C,
		//! �X�L���c���[���N�G�X�g
		CacheSkillTreeRequest = 0x4D,
		//! �X�L���c���[���X�|���X
		CacheSkillTreeResponse = 0x4E,
		//! �X�L���c���[�J��
		CacheOpenSkillTree = 0x4F,
		//! �L�����N�^�ۑ����N�G�X�g
		CacheCharacterDataSave = 0x50,
		//! �S�[���h�ۑ����N�G�X�g
		CacheGoldSave = 0x51,
		//! �A�C�e�����X�g���N�G�X�g
		CacheItemListRequest = 0x52,
		//! �A�C�e�����X�g���X�|���X
		CacheItemListResponse = 0x53,
		//! �A�C�e�����ω����N�G�X�g
		CacheItemCountChangeRequest = 0x54,
		//! �A�C�e���V���[�g�J�b�g���N�G�X�g
		CacheItemShortcutRequest = 0x55,
		//! �A�C�e���V���[�g�J�b�g���X�|���X
		CacheItemShortcutResponse = 0x56,
		//! �A�C�e���V���[�g�J�b�g�ۑ����N�G�X�g
		CacheSaveItemShortcutRequest = 0x57,
		//! �A�C�e���V���[�g�J�b�g�ۑ����X�|���X
		CacheSaveItemShortcutResponse = 0x58,
		//! �N�G�X�g�f�[�^���N�G�X�g
		CacheQuestDataRequest = 0x59,
		//! �N�G�X�g�f�[�^���X�|���X
		CacheQuestDataResponse = 0x5A,
		//! �N�G�X�g�f�[�^�ۑ����N�G�X�g
		CacheSaveQuestDataRequest = 0x5B,
		//! �N�G�X�g�j�����N�G�X�g
		CacheQuestRetireRequest = 0x5C,
		//! �A�N�e�B�u�N�G�X�g�ۑ����N�G�X�g
		CacheSaveActiveQuestRequest = 0x5D,
		
	};
};

#endif		// #ifndef __CACHESERVERPACKETID_H__
