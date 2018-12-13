#ifndef __CACHESERVERCONNECTION_H__
#define __CACHESERVERCONNECTION_H__

#include "TCPConnection.h"

class PacketBase;

/**
 * �L���b�V���T�[�o�Ƃ̐ڑ�.
 */
class CacheServerConnection : public TCPConnection, public noncopyable
{

public:

	// �R���X�g���N�^
	CacheServerConnection(const shared_ptr<tcp::socket> &pInSocket);

	// �f�X�g���N�^
	virtual ~CacheServerConnection() {}

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

	static CacheServerConnection *GetInstance() { return pInstance; }

private:

	static CacheServerConnection *pInstance;

};

#endif		// #ifndef __CACHESERVERCONNECTION_H__
