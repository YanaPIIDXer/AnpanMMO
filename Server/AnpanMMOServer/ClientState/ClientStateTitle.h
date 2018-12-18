#ifndef __CLIENTSTATETITLE_H__
#define __CLIENTSTATETITLE_H__

#include "ClientStateBase.h"
#include "Math/Vector3D.h"

/**
 * �^�C�g�����State
 */
class ClientStateTitle : public ClientStateBase
{

public:

	// �R���X�g���N�^
	ClientStateTitle(Client *pInParent);

	// �f�X�g���N�^
	virtual ~ClientStateTitle() {}

private:

	// �ŏI���O�A�E�g�n�_.
	u32 LastAreaId;

	// �ŏI���O�A�E�g�ʒu.
	Vector3D LastPosition;


	// ���O�C�����N�G�X�g����M�����B
	void OnRecvLogInRequest(MemoryStreamInterface *pStream);

	// �L�����N�^�쐬���N�G�X�g����M�����B
	void OnRecvCreateCharacterRequest(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o���烍�O�C�����ʂ���M�����B
	void OnRecvCacheLogInResult(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o����L�����N�^�쐬���ʂ���M�����B
	void OnRecvCacheCreateCharacterResult(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o����L�����N�^�f�[�^����M�����B
	void OnRecvCacheCharacterDataResult(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o����X�L�����X�g����M�����B
	void OnRecvCacheSkillListResponse(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o����X�L���c���[������M�����B
	void OnRecvCacheSkillTreeResponse(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o����A�C�e�����X�g����M�����B
	void OnRecvCacheItemListResponse(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o����A�C�e���V���[�g�J�b�g����M�����B
	void OnRecvCacheItemShortcutResponse(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o����X�N���v�g�t���O����M�����B
	void OnRecvCacheScriptFlagResponse(MemoryStreamInterface *pStream);

};

#endif		// #ifndef __CLIENTSTATETITLE_H__
