#ifndef __CLIENTSTATETITLE_H__
#define __CLIENTSTATETITLE_H__

#include "ClientStateBase.h"

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

};

#endif		// #ifndef __CLIENTSTATETITLE_H__
