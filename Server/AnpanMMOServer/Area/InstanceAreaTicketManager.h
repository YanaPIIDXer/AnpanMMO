#ifndef __INSTANCEAREATICKETMANAGER_H__
#define __INSTANCEAREATICKETMANAGER_H__

#include <boost/unordered_map.hpp>

class InstanceAreaTicket;

/**
 * インスタンスエリアチケットマネージャ
 */
class InstanceAreaTicketManager : public noncopyable
{

private:		// 別名定義.

	typedef boost::unordered_map<u32, InstanceAreaTicket *> TicketMap;

public:

	// デストラクタ
	virtual ~InstanceAreaTicketManager();

	// 発行.
	InstanceAreaTicket *Publish();

	// 取得.
	InstanceAreaTicket *Get(u32 Uuid);

	// 消去.
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
