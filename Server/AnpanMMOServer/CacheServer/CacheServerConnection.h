/**
 * @file CacheServerConnection.h
 * @brief キャッシュサーバとの接続クラス
 * @author YanaP
 */
#ifndef __CACHESERVERCONNECTION_H__
#define __CACHESERVERCONNECTION_H__

#include "TCPConnection.h"

class PacketBase;

/**
 * @class CacheServerConnection
 * @brief キャッシュサーバとの接続.
 * @details シングルトン（もどき）クラス
 */
class CacheServerConnection : public TCPConnection, public noncopyable
{

public:

	/**
	 * @brief コンストラクタ
	 */
	CacheServerConnection(const shared_ptr<tcp::socket> &pInSocket);

	/**
	 * @brief デストラクタ
	 */
	virtual ~CacheServerConnection() {}

	/**
	 * @fn bool Connect()
	 * @brief 接続
	 * @return 接続に成功したらtrueを返す。
	 */
	bool Connect();

	/**
	 * @fn void SendPacket(PacketBase *pPacket)
	 * @brief パケット送信
	 * @param[in] pPacket パケット
	 */
	void SendPacket(PacketBase *pPacket);

protected:

	/**
	 * @fn virtual void OnRecvData(size_t Size)
	 * @brief データを受信した
	 * @param[in] Size データサイズ
	 */
	virtual void OnRecvData(size_t Size);

	/**
	 * @fn virtual void OnDisconnected()
	 * @brief 切断された
	 */
	virtual void OnDisconnected();

private:

	// ============ Singletonもどき ================

public:

	/**
	 * @fn static CacheServerConnection *GetInstance()
	 * @brief インスタンス取得
	 * @return インスタンス
	 */
	static CacheServerConnection *GetInstance() { return pInstance; }

private:

	static CacheServerConnection *pInstance;

};

#endif		// #ifndef __CACHESERVERCONNECTION_H__
