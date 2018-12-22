/**
 * @file CacheServerConnection.h
 * @brief �L���b�V���T�[�o�Ƃ̐ڑ��N���X
 * @author YanaP
 */
#ifndef __CACHESERVERCONNECTION_H__
#define __CACHESERVERCONNECTION_H__

#include "TCPConnection.h"

class PacketBase;

/**
 * @class CacheServerConnection
 * @brief �L���b�V���T�[�o�Ƃ̐ڑ�.
 * @details �V���O���g���i���ǂ��j�N���X
 */
class CacheServerConnection : public TCPConnection, public noncopyable
{

public:

	/**
	 * @brief �R���X�g���N�^
	 */
	CacheServerConnection(const shared_ptr<tcp::socket> &pInSocket);

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~CacheServerConnection() {}

	/**
	 * @fn bool Connect()
	 * @brief �ڑ�
	 * @return �ڑ��ɐ���������true��Ԃ��B
	 */
	bool Connect();

	/**
	 * @fn void SendPacket(PacketBase *pPacket)
	 * @brief �p�P�b�g���M
	 * @param[in] pPacket �p�P�b�g
	 */
	void SendPacket(PacketBase *pPacket);

protected:

	/**
	 * @fn virtual void OnRecvData(size_t Size)
	 * @brief �f�[�^����M����
	 * @param[in] Size �f�[�^�T�C�Y
	 */
	virtual void OnRecvData(size_t Size);

	/**
	 * @fn virtual void OnDisconnected()
	 * @brief �ؒf���ꂽ
	 */
	virtual void OnDisconnected();

private:

	// ============ Singleton���ǂ� ================

public:

	/**
	 * @fn static CacheServerConnection *GetInstance()
	 * @brief �C���X�^���X�擾
	 * @return �C���X�^���X
	 */
	static CacheServerConnection *GetInstance() { return pInstance; }

private:

	static CacheServerConnection *pInstance;

};

#endif		// #ifndef __CACHESERVERCONNECTION_H__
