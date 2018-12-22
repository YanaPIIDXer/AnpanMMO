/**
 * @file InstanceAreaTicketManager.cpp
 * @brief インスタンスエリアチケット管理クラス
 * @author YanaP
 */
#ifndef __INSTANCEAREATICKETMANAGER_H__
#define __INSTANCEAREATICKETMANAGER_H__

#include <boost/unordered_map.hpp>

class InstanceAreaTicket;
class Vector3D;

/**
 * @class InstanceAreaTicketManager
 * @brief インスタンスエリアチケット管理
 * @details シングルトンクラス
 */
class InstanceAreaTicketManager : public noncopyable
{

private:		// 別名定義.

	typedef boost::unordered_map<u32, InstanceAreaTicket *> TicketMap;

public:

	/**
	 * @brief デストラクタ
	 */
	virtual ~InstanceAreaTicketManager();

	/**
	 * @fn InstanceAreaTicket *Publish(u32 AreaId, const Vector3D &StartPosition)
	 * @brief 発行
	 * @param[in] AreaId エリアマスタＩＤ
	 * @param[in] StartPosition 開始座標
	 * @return インスタンスエリアチケット
	 */
	InstanceAreaTicket *Publish(u32 AreaId, const Vector3D &StartPosition);

	/**
	 * @fn InstanceAreaTicket *Get(u32 Uuid)
	 * @brief 取得
	 * @param[in] Uuid チケットのＵＵＩＤ
	 * @return インスタンスエリアチケット
	 */
	InstanceAreaTicket *Get(u32 Uuid);

	/**
	 * @fn void Remove(u32 Uuid)
	 * @brief 消去
	 * @param[in] Uuid チケットのＵＵＩＤ
	 */
	void Remove(u32 Uuid);

private:

	// チケットリスト
	TicketMap TicketList;

	// 次に発行するUUID
	u32 NextUuid;

	// =========== Singleton ============

public:

	static InstanceAreaTicketManager &GetInstance() { return Instance; }

private:

	InstanceAreaTicketManager();
	static InstanceAreaTicketManager Instance;

};

#endif		// #ifndef __INSTANCEAREATICKETMANAGER_H__
