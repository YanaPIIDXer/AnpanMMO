#ifndef __INSTANCEAREATICKET_H__
#define __INSTANCEAREATICKET_H__

#include <boost/unordered_map.hpp>
#include "WeakPtrDefine.h"

/**
 * インスタンスマップチケット
 */
class InstanceAreaTicket
{

private:		// 別名定義.

	typedef boost::unordered_map<u32, ClientPtr> ClientMap;

public:

	// コンストラクタ
	InstanceAreaTicket();

	// デストラクタ
	~InstanceAreaTicket() {}

	// クライアント追加.
	void AddClient(ClientPtr pClient);

private:

	// クライアントリスト
	ClientMap ClientList;

};

#endif		// #ifndef __INSTANCEAREATICKET_H__
