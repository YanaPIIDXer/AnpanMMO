/**
 * @file ClientStateActive.h
 * @brief �N���C�A���g�X�e�[�g�F�Q�[����
 * @author YanaP
 */
#ifndef __CLIENTSTATEACTIVE_H__
#define __CLIENTSTATEACTIVE_H__

#include "ClientStateBase.h"

/**
 * @class ClientStateActive
 * @brief �Q�[����State
 */
class ClientStateActive : public ClientStateBase
{
		
public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] pInParent �N���C�A���g
	 */
	ClientStateActive(Client *pInParent);

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~ClientStateActive() {}

	/**
	 * @fn virtual void BeginState()
	 * @brief State�J�n���̏���
	 */
	virtual void BeginState();

private:

	// Ping����M�����B
	bool OnRecvPing(MemoryStreamInterface *pStream);

	// �ړ�����M�����B
	bool OnRecvMove(MemoryStreamInterface *pStream);

	// �`���b�g����M�����B
	bool OnRecvChat(MemoryStreamInterface *pStream);

	// �`���b�g�̃��[�h�`�F�b�N���ʂ���M�����B
	bool OnRecvChatWordCheckResult(MemoryStreamInterface *pStream);

	// �G���A�ړ��v������M�����B
	bool OnRecvAreaMoveRequest(MemoryStreamInterface *pStream);

	// ���X�|���v������M�����B
	bool OnRecvRespawnRequest(MemoryStreamInterface *pStream);

	// �X�L���g�p����M�����B
	bool OnRecvSkillUse(MemoryStreamInterface *pStream);

	// �p�[�e�B�쐬�v������M�����B
	bool OnRecvPartyCraeteRequest(MemoryStreamInterface *pStream);

	// �p�[�e�B���E�v������M�����B
	bool OnRecvPartyDissolutionRequest(MemoryStreamInterface *pStream);

	// �p�[�e�B���E�v������M�����B
	bool OnRecvPartyExitRequest(MemoryStreamInterface *pStream);

	// �p�[�e�B�L�b�N�v������M�����B
	bool OnRecvPartyKickRequest(MemoryStreamInterface *pStream);

	// �p�[�e�B���U�v������M�����B
	bool OnRecvPartyInviteRequest(MemoryStreamInterface *pStream);
	
	// �p�[�e�B���U���X�|���X����M�����B
	bool OnRecvPartyInviteResponse(MemoryStreamInterface *pStream);

	// �C���X�^���X�}�b�v�`�P�b�g�̏�������M�����B
	bool OnRecvInstanceAreaTicketProcess(MemoryStreamInterface *pStream);

	// NPC�Ƃ̉�b����M�����B
	bool OnRecvNPCTalk(MemoryStreamInterface *pStream);

	// NPC�Ƃ̉�b�ł̑I��������M�����B
	bool OnRecvNPCTalkSelection(MemoryStreamInterface *pStream);

	// �X�L�����X�g�ۑ����N�G�X�g����M�����B
	bool OnRecvSaveSkillListRequest(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o����X�L�����X�g�ۑ����X�|���X����M�����B
	bool OnRecvCacheSaveSkillListResponse(MemoryStreamInterface *pStream);

	// �X�L���c���[�J���v������M�����B
	bool OnRecvSkillTreeOpenRequest(MemoryStreamInterface *pStream);

	// �A�C�e���g�p����M�����B
	bool OnRecvItemUse(MemoryStreamInterface *pStream);

	// �A�C�e���j�����N�G�X�g����M�����B
	bool OnRecvItemSubtractRequest(MemoryStreamInterface *pStream);

	// �A�C�e���V���[�g�J�b�g�ۑ����N�G�X�g����M�����B
	bool OnRecvSaveItemShortcutRequest(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o����A�C�e���V���[�g�J�b�g�ۑ����ʂ���M�����B
	bool OnRecvCacheSaveItemShortcutResponse(MemoryStreamInterface *pStream);

	// �N�G�X�g�j���v������M�����B
	bool OnRecvQuestRetireRequest(MemoryStreamInterface *pStream);

	// �A�N�e�B�u�N�G�X�g�ۑ�����M�����B
	bool OnRecvSaveActiveQuest(MemoryStreamInterface *pStream);

	// �����ύX���N�G�X�g����M�����B
	bool OnRecvChangeEquipRequest(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o���瑕���ۑ����X�|���X����M�����B
	bool OnRecvCacheSaveEquipResponse(MemoryStreamInterface *pStream);

	// �A�C�e���w���v������M�����B
	bool OnRecvBuyItemRequest(MemoryStreamInterface *pStream);

	// �A�C�e�����p�v������M�����B
	bool OnRecvSellItemRequest(MemoryStreamInterface *pStream);

	// �V���b�v�I������M�����B
	bool OnRecvExitShop(MemoryStreamInterface *pStream);

	// ���[�����X�g���N�G�X�g����M�����B
	bool OnRecvMailListRequest(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o���烁�[�����X�g����M�����B
	bool OnRecvCacheMailList(MemoryStreamInterface *pStream);

	// ���[���J������M�����B
	bool OnRecvMailRead(MemoryStreamInterface *pStream);

	// ���[���Y�t����M���N�G�X�g����M�����B
	bool OnRecvMailAttachmentRecvRequest(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o���烁�[���Y�t����M���ʂ���M�����B
	bool OnRecvCacheMailAttachmentRecvResult(MemoryStreamInterface *pStream);

};

#endif		// #Ifndef __CLIENTSTATEACTIVE_H__
