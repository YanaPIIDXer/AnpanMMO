#ifndef __WORDCHECKSERVERCONNECTION_H__
#define __WORDCHECKSERVERCONNECTION_H__

#include "TCPConnection.h"

class PacketBase;

/**
 * �L���b�V���T�[�o�Ƃ̐ڑ�.
 */
class WordCheckServerConnection : public TCPConnection, public noncopyable
{

public:

	// �R���X�g���N�^
	WordCheckServerConnection(const shared_ptr<tcp::socket> &pInSocket);

	// �f�X�g���N�^
	virtual ~WordCheckServerConnection() {}

	// �ڑ�.
	bool Connect();

	// �p�P�b�g���M.
	void SendPacket(PacketBase *pPacket);

protected:

	// �f�[�^����M�����B
	virtual void OnRecvData(size_t Size);

	// �ؒf���ꂽ�B
	virtual void OnDisconnected();

private:

	// ============ Singleton���ǂ� ================

public:

	static WordCheckServerConnection *GetInstance() { return pInstance; }

private:

	static WordCheckServerConnection *pInstance;

};

#endif		// #ifndef __WORDCHECKSERVERCONNECTION_H__
