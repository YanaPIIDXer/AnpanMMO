#ifndef __INSTANCEAREATICKET_H__
#define __INSTANCEAREATICKET_H__

#include <boost/unordered_map.hpp>
#include "WeakPtrDefine.h"

// チケットステート
enum ETicketState
{
	// 処理待ち
	TicketStateWait,

	// 進入.
	TicketStateEnter,

	// 破棄.
	TicketStateDiscard,
};

// チケット情報.
struct InstanceAreaTicketInfo
{

public:

	// クライアント
	ClientPtr pClient;

	// ステート
	ETicketState State;

};

/**
 * インスタンスマップチケット
 */
class InstanceAreaTicket
{

private:		// 別名定義.

	typedef boost::unordered_map<u32, InstanceAreaTicketInfo> InfoMap;

public:

	// コンストラクタ
	InstanceAreaTicket();

	// デストラクタ
	~InstanceAreaTicket() {}

	// クライアント追加.
	void AddClient(ClientPtr pClient);

	// 処理を受信した。
	void RecvProcess(u32 Uuid, ETicketState Process);

	// 準備が完了しているか？
	bool IsReady() const;

	// 破棄されているか？
	bool IsDiscard() const;

	// 待機中か？
	bool IsWaiting() const;

private:

	// 情報リスト
	InfoMap InfoList;

};

#endif		// #ifndef __INSTANCEAREATICKET_H__
