#ifndef __CACHESERVERCONNECTION_H__
#define __CACHESERVERCONNECTION_H__

#include "TCPConnection.h"

/**
 * �L���b�V���T�[�o�Ƃ̐ڑ�.
 */
class CacheServerConnection : TCPConnection
{

public:

	// �R���X�g���N�^
	CacheServerConnection(const shared_ptr<tcp::socket> &pInSocket);

	// �f�X�g���N�^
	virtual ~CacheServerConnection() {}

	// �ڑ�.
	bool Connect();

protected:

private:

};

#endif		// #ifndef __CACHESERVERCONNECTION_H__
