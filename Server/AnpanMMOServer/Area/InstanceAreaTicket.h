/**
 * @file InstanceAreaTicket.cpp
 * @brief インスタンスエリアチケットクラス
 * @author YanaP
 */
#ifndef __INSTANCEAREATICKET_H__
#define __INSTANCEAREATICKET_H__

#include <boost/unordered_map.hpp>
#include "WeakPtrDefine.h"
#include "Math/Vector3D.h"

/**
 * @enum ETicketState
 * @brief チケットステート
 */
enum ETicketState
{
	//! 処理待ち
	TicketStateWait,

	//! 進入.
	TicketStateEnter,

	//! 破棄.
	TicketStateDiscard,
};

/**
 * @struct InstanceAreaTicketInfo
 * @brief チケット情報
 */
struct InstanceAreaTicketInfo
{

public:

	//! クライアント
	ClientPtr pClient;

	//! ステート
	ETicketState State;

};

/**
 * @class InstanceAreaTicket
 * @brief インスタンスマップチケット
 */
class InstanceAreaTicket
{

private:		// 別名定義.

	typedef boost::unordered_map<u32, InstanceAreaTicketInfo> InfoMap;

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] InUuid ＵＵＩＤ
	 * @param[in] InAreaId エリアマスタＩＤ
	 * @param[in] InStartPosition 開始座標
	 */
	InstanceAreaTicket(u32 InUuid, u32 InAreaId, const Vector3D &InStartPosition);

	/**
	 * @brief デストラクタ
	 */
	~InstanceAreaTicket() {}

	/**
	 * @fn void AddClient(ClientPtr pClient)
	 * @brief クライアント追加
	 * @param[in] pClient クライアントへのweak_ptr
	 */
	void AddClient(ClientPtr pClient);

	/**
	 * @fn void RecvProcess(u32 Uuid, ETicketState Process)
	 * @brief 処理を受信した
	 * @param[in] Uuid クライアントＵＵＩＤ
	 * @param[in] Process 処理内容
	 */
	void RecvProcess(u32 Uuid, ETicketState Process);

	/**
	 * @fn bool IsReady() const
	 * @brief 準備が完了しているか？
	 * @return 準備が完了しているならtrueを返す。
	 */
	bool IsReady() const;

	/**
	 * @fn bool IsDiscard() const
	 * @brief 破棄されているか？
	 * @return 破棄されているならtrueを返す。
	 */
	bool IsDiscard() const;

	/**
	 * @fn bool IsWaiting() const
	 * @brief 待機中か？
	 * @return 待機中ならtrueを返す。
	 */
	bool IsWaiting() const;

	/**
	 * @fn u32 GetAreaId() const
	 * @brief エリアＩＤを取得
	 * @return エリアＩＤ
	 */
	u32 GetAreaId() const { return AreaId; }

	/**
	 * @fn void BroadcastPublishPacket()
	 * @brief 発行チケットをバラ撒く
	 */
	void BroadcastPublishPacket();

	/**
	 * @fn void BroadcastDiscardPacket()
	 * @brief 破棄チケットをバラ撒く
	 */
	void BroadcastDiscardPacket();

	/**
	 * @fn void EnterToInstanceArea(AreaPtr pArea)
	 * @brief インスタンスエリアに突っ込む
	 * @param[in] pArea インスタンスエリアへのweak_ptr
	 */
	void EnterToInstanceArea(AreaPtr pArea);

private:

	// UUID
	u32 Uuid;

	// エリアＩＤ
	u32 AreaId;

	// 開始座標.
	Vector3D StartPosition;

	// 情報リスト
	InfoMap InfoList;

};

#endif		// #ifndef __INSTANCEAREATICKET_H__
