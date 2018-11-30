#ifndef __CLIENTSTATEACTIVE_H__
#define __CLIENTSTATEACTIVE_H__

#include "ClientStateBase.h"

/**
 * �Q�[����State
 */
class ClientStateActive : public ClientStateBase
{
		
public:

	// �R���X�g���N�^
	ClientStateActive(Client *pInParent);

	// �f�X�g���N�^
	virtual ~ClientStateActive() {}

private:

	// �ړ�����M�����B
	void OnRecvMove(MemoryStreamInterface *pStream);

	// �U������M�����B
	void OnRecvAttack(MemoryStreamInterface *pStream);

	// �`���b�g����M�����B
	void OnRecvChat(MemoryStreamInterface *pStream);

	// �`���b�g�̃��[�h�`�F�b�N���ʂ���M�����B
	void OnRecvChatWordCheckResult(MemoryStreamInterface *pStream);

	// �G���A�ړ��v������M�����B
	void OnRecvAreaMoveRequest(MemoryStreamInterface *pStream);

	// ���X�|���v������M�����B
	void OnRecvRespawnRequest(MemoryStreamInterface *pStream);

	// �p�[�e�B�쐬�v������M�����B
	void OnRecvPartyCraeteRequest(MemoryStreamInterface *pStream);

	// �p�[�e�B���E�v������M�����B
	void OnRecvPartyDissolutionRequest(MemoryStreamInterface *pStream);

	// �p�[�e�B���E�v������M�����B
	void OnRecvPartyExitRequest(MemoryStreamInterface *pStream);

	// �p�[�e�B�L�b�N�v������M�����B
	void OnRecvPartyKickRequest(MemoryStreamInterface *pStream);

	// �p�[�e�B���U�v������M�����B
	void OnRecvPartyInviteRequest(MemoryStreamInterface *pStream);
	
	// �p�[�e�B���U���X�|���X����M�����B
	void OnRecvPartyInviteResponse(MemoryStreamInterface *pStream);

};

#endif		// #Ifndef __CLIENTSTATEACTIVE_H__
