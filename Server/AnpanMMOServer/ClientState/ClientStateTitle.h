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
	bool OnRecvLogInRequest(MemoryStreamInterface *pStream);

	// �L�����N�^�쐬���N�G�X�g����M�����B
	bool OnRecvCreateCharacterRequest(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o���烍�O�C�����ʂ���M�����B
	bool OnRecvCacheLogInResult(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o����L�����N�^�쐬���ʂ���M�����B
	bool OnRecvCacheCreateCharacterResult(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o����L�����N�^�f�[�^����M�����B
	bool OnRecvCacheCharacterDataResult(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o����X�L�����X�g����M�����B
	bool OnRecvCacheSkillListResponse(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o����X�L���c���[������M�����B
	bool OnRecvCacheSkillTreeResponse(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o����A�C�e�����X�g����M�����B
	bool OnRecvCacheItemListResponse(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o����A�C�e���V���[�g�J�b�g����M�����B
	bool OnRecvCacheItemShortcutResponse(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o����X�N���v�g�t���O����M�����B
	bool OnRecvCacheScriptFlagResponse(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o����N�G�X�g�f�[�^����M�����B
	bool OnRecvCacheQuestDataResponse(MemoryStreamInterface *pStream);

};

#endif		// #ifndef __CLIENTSTATETITLE_H__
