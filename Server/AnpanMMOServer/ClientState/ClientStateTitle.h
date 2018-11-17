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

private:

	// ���O�C�����N�G�X�g����M�����B
	void OnRecvLogInRequest(MemoryStreamInterface *pStream);

	// �L���b�V���T�[�o���烍�O�C�����ʂ���M�����B
	void OnRecvCacheLogInResult(MemoryStreamInterface *pStream);

	// �L�����N�^���[�h
	void LoadCharacter();

};

#endif		// #ifndef __CLIENTSTATETITLE_H__
